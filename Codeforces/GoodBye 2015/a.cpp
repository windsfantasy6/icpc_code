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
int main() {
  int x;
  cin >> x;
  string s;
  cin >> s;
  cin >> s;
  if (s[0] == 'w') {
    if (x == 5 || x == 6) {
      cout << 53 << endl;
    }
    else {
      cout << 52 << endl;
    }
  }
  else {
    int arr[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int res = 0;
    for (int i = 0; i < 12; i++) {
      if (x <= arr[i]) {
        res++;
      }
    }
    cout << res << endl;
  }
  return 0;
}
