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
  int n;
  cin >> n;
  vector<int> s(3);
  cin >> s[0] >> s[1] >> s[2];
  sort(s.begin(), s.end());
  for (int i = 0; i < 3; i++) {
    s[i] = -s[i];
  }
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    mp[-x]++;
  }
  auto it = mp.begin();
  int round = 0;
  if (mp.begin()->first < s[0] + s[1] + s[2]) {
    cout << -1 << endl;
    return 0;
  }
  while (it != mp.end()) {
    round++;
    int cnt = 0;
    if (it == mp.end()) {
      break;
    }
    for (int i = 2; i >= 0; i--) {
      if (s[i] <= it->first) {
        cnt++;
        it->second--;
        if (it->second <= 0) {
          auto it1 = it;
          it1++;
          mp.erase(it);
          it = it1;
          if (it == mp.end()) {
            break;
          }
        }
      }
    }
    if (it == mp.end()) {
      break;
    }
    if (cnt == 3) {
      continue;
    }
    else if (cnt == 2) {
      auto nit = mp.lower_bound(s[0]);
      if (nit != mp.end()) {
        nit->second--;
        if (nit->second <= 0) {
          if (it == nit) {
            it++;
          }
          mp.erase(nit);
        }
      }
    }
    else if (cnt == 1) {
      int cc = 0;
      {
        auto nit = mp.lower_bound(s[0]);
        if (nit != mp.end()) {
          cc++;
          nit->second--;
          if (nit->second <= 0) {
            if (it == nit) {
              it++;
            }
            mp.erase(nit);
          }
        }
      }
      {
        auto nit = mp.lower_bound(s[1]);
        if (nit != mp.end()) {
          cc++;
          nit->second--;
          if (nit->second <= 0) {
            if (it == nit) {
              it++;
            }
            mp.erase(nit);
          }
        }
      }
      {
        if (cc == 0) {
          auto nit = mp.lower_bound(s[0] + s[1]);
          if (nit != mp.end()) {
            cc++;
            nit->second--;
            if (nit->second <= 0) {
              if (it == nit) {
                it++;
              }
              mp.erase(nit);
            }
          }
        }
      }
    }
    else if (cnt == 0) {
      int other;
      for (other = 2; other >= 0; other--) {
        int str = 0;
        for (int i = 0; i < 3; i++) {
          if (i != other) {
            str += s[i];
          }
        }
        if (str <= it->first) {
          it->second--;
          if (it->second == 0) {
            auto it1 = it;
            it1++;
            mp.erase(it);
            it = it1;
            if (it == mp.end()) {
              break;
            }
          }
          auto nit = mp.lower_bound(s[other]);
          if (nit != mp.end()) {
            nit->second--;
            if (nit->second <= 0) {
              if (it == nit) {
                it++;
              }
              mp.erase(nit);
            }
          }
          break;
        }
      }
      if (other == -1) {
        int str = s[0] + s[1] + s[2];
        if (str <= it->first) {
          it->second--;
          if (it->second == 0) {
            auto it1 = it;
            it1++;
            mp.erase(it);
            it = it1;
            if (it == mp.end()) {
              break;
            }
          }
        }
      }
    }
  }
  cout << round << endl;
  return 0;
}






















