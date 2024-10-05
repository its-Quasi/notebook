using namespace std;
#include <bits/stdc++.h>
typedef long long ll;

int main() {
  int tt, n;
  string s;
  cin >> tt;
  while (tt--) {
    cin >> n >> s;
    string ns;
    ns.push_back(s[0]);
    for (int i = 1; i < n; i++) {
      if (ns.back() != s[i]) ns.push_back(s[i]);
    }
    int c0 = count(ns.begin(), ns.end(), '0');
    int c1 = count(s.begin(), s.end(), '1');
    cout << (c1 > c0 ? "Yes" : "No") << endl;
  }
}
