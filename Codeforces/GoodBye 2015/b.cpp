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
int cntZero(long long x) {
  int res = 0;
  while (x) {
    if ((x & 1) == 0) {
      res++;
    }
    x = x >> 1;
  }
  return res;
}
int work(long long x) {
  if (x == 0) {
    return 0;
  }
  int i;
  if (cntZero(x) == 0) {
    for (i = 63; i >= 0; i--) {
      if (x & (1ll << i)) {
        break;
      }
    }
    return (1 + i) * i / 2;
  }
  int res = 0;
  if (cntZero(x) == 1) {
    for (i = 0; i < 64; i++) {
      if ((x & (1ll << i)) == 0) {
        break;
      }
    }
    res = i;
    for (i = 63; i >= 0; i--) {
      if (x & (1ll << i)) {
        break;
      }
    }
    res = i - res;
  }
  //out << "res = " << res << endl;
  for (i = 63; i >= 0; i--) {
    if (x & (1ll << i)) {
      break;
    }
  }
  int i1 = i - 1;
  while (i1 >= 0 && (x & (1ll << i1))) {
    if (cntZero(x) > 1) {
      res++;
    }
    i1--;
  }
  return (i - 1) * (i) / 2 + res;
}
int main() {
  long long l, h;

  while (cin >> l >> h) {
//  cout << "l, h = " << l << "\t" << h << endl;
    cout << work(h) - work(l - 1) << endl;
  }
  return 0;
}
