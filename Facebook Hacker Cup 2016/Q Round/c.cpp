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
  freopen("c.in.txt", "r", stdin);
  freopen("c.out.txt", "w", stdout);
  int tk, tk1 = 0;
  cin >> tk;
  while (tk--) {
    tk1++;
    long long n, u;
    cin >> n >> u;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int head = 0, tail = 0;
    long long ans = 0;
    long long sum = 0;
    while (tail < n) {
      while (tail < n && sum <= u) {
        //cout << "head, tail, sum = " << head << ", " << tail << ", " << sum << endl;
        sum += a[tail];
        tail++;
      }
      if (tail == n) {
        break;
      }
      while (head < tail && sum > u) {
        //cout << "head, tail = " << head << ", " << tail << endl;
        ans += tail - head - 1;
        sum -= a[head];
        head++;
      }
      //cout << "ans = " << ans << endl;
    }

    while (head < n) {
      ans += tail - head;
      if (sum > u) {
        ans--;
      }
      sum -= a[head];
      head++;
    }

    cout << "Case #" << tk1 << ": " << ans << endl;
  }
  return 0;
}
