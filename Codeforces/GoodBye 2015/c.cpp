#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;
int sigma(vector<vector<int> > &sum, int x1, int y1, int x2, int y2) {
  int res = 0, d1 = 0, d2 = 0, s = 0;
  if (x1 > 0) {
    d1 = sum[x1 - 1][y2];
  }
  if (y1 > 0) {
    d2 = sum[x2][y1 - 1];
  }
  if (x1 > 0 && y1 > 0) {
    s = sum[x1 - 1][y1 - 1];
  }
  return sum[x2][y2] - d1 - d2 + s;
}
int main() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  for (int i = 0; i < h; i++) {
    cin >> a[i];
  }
  vector<vector<int> > up(h, vector<int>(w));
  vector<vector<int> > left(h, vector<int>(w));
  vector<vector<int> > sum(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (i > 0) {
        if (a[i][j] != '#' && a[i - 1][j] != '#') {
          up[i][j] = 1;
        }
      }
      if (j > 0) {
        if (a[i][j] != '#' && a[i][j - 1] != '#') {
          left[i][j] = 1;
        }
      }
    }
  }
  vector<vector<int> > us(h, vector<int>(w));
  vector<vector<int> > ls(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int us1 = 0, us2 = 0, ud = 0, ls1 = 0, ls2 = 0, ld = 0;
      if (i > 0) {
        us1 = us[i - 1][j];
        ls1 = ls[i - 1][j];
      }
      if (j > 0) {
        us2 = us[i][j - 1];
        ls2 = ls[i][j - 1];
      }
      if (i > 0 && j > 0) {
        ud = us[i - 1][j - 1];
        ld = ls[i - 1][j - 1];
      }
      us[i][j] = us1 + us2 - ud + up[i][j];
      ls[i][j] = ls1 + ls2 - ld + left[i][j];
      sum[i][j] = us[i][j] + ls[i][j];
      //cout << i << "\t" << j << "\t" << us[i][j] << "\t" << ls[i][j] << "\t" << sum[i][j] << endl;
      //cout << "us1, us2, ud = " << us1 << ", " << us2 << ", " << ud << endl;
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;
    int res = sigma(sum, x1, y1, x2, y2);
    //cout << "r1 = " << res << endl;
    res -= sigma(us, x1, y1, x1, y2);
    //cout << "r2 = " << res << endl;
    res -= sigma(ls, x1, y1, x2, y1);
    //cout << "r3 = " << res << endl;
    cout << res << endl;
  }
  return 0;
}




















