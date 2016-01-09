#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define sqr(x) ((x) * (x))
#define eps 1e-8
int sign(double x) {
  if (x > eps) {
    return 1;
  }
  if (x < -eps) {
    return -1;
  }
  return 0;
}
int main() {
  freopen("a.in.txt", "r", stdin);
  freopen("a.out.txt", "w", stdout);
  int tk, tk1 = 0;
  cin >> tk;
  while (tk--) {
    tk1++;
    int n;
    cin >> n;
    vector<pair<double, double> > a(n);
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      a[i] = make_pair(x, y);
    }
    vector<vector<double> > dist(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dist[i][j] = sqrt(sqr(a[i].first - a[j].first) + sqr(a[i].second - a[j].second));
      }
      sort(dist[i].begin(), dist[i].end());
    }
    /*
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << dist[i][j] << "\t";
      }
      cout << endl;
    }
    */
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int head = 0, tail = 0;
      while (tail < n) {
        while (tail < n && sign(dist[i][tail] - dist[i][head]) == 0) {
          tail++;
        }
        //cout << "diff = " << tail - head << endl;
        if (tail - head >= 2) {
          ans += (tail - head) * (tail - head - 1) / 2;
        }
        head = tail;
      }
    }
    cout << "Case #" << tk1 << ": " << ans << endl;
  }
  return 0;
}
