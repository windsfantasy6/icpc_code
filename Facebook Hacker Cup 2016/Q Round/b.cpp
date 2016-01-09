#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
  freopen("b.in.txt", "r", stdin);
  freopen("b.out.txt", "w", stdout);
  int tk, tk1 = 0;
  cin >> tk;
  while (tk--) {
    tk1++;
    int n;
    cin >> n;
    vector<string> a(2);
    cin >> a[0] >> a[1];
    vector<vector<pair<pair<int, int>, bool> > > intervals(2);
    for (int i = 0; i < 2; i++) {
      int head = 0, tail = 0;
      while (tail < n) {
        while (tail < n && a[i][tail] != '.') {
          tail++;
        }
        head = tail;
        while (tail < n && a[i][tail] == '.') {
          tail++;
        }
        if (tail - head > 0) {
          intervals[i].push_back(make_pair(make_pair(head, tail), false));
        }
      }
    }
    int ans = intervals[0].size() + intervals[1].size();
    for (int i = 0; i < 2; i++) {
      /*
      for (int j = 0; j < intervals[i].size(); j++) {
        cout << intervals[i][j].first.first << "\t" << intervals[i][j].first.second << endl;
      }
      */
      int other = 1 - i;
      for (int j = 0; j < intervals[i].size(); j++) {
        int x = intervals[i][j].first.first;
        int y = intervals[i][j].first.second;
        if (y - x == 1) {
          for (int k = 0; k < intervals[other].size(); k++) {
            if (intervals[other][k].first.first <= x && y <= intervals[other][k].first.second) {
              if (intervals[other][k].second == false) {
                intervals[other][k].second = true;
                intervals[i][j].second = true;
                ans--;
              }
              break;
            }
          }
        }
      }
    }
    cout << "Case #" << tk1 << ": " << ans << endl;
  }
  return 0;
}
