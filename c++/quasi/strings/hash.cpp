typedef pair<ll, ll> pii;
const long long base = 1777771;
const long long mod1 = 999727999;
const long long mod2 = 1070777777;

struct Hash {
  vector<pii> hs, pot;
  Hash(string s) {
    hs.resize(sz(s) + 1);
    pot.resize(sz(s) + 1);
    pot[0] = pii(1, 1);
    for (int i = 1; i <= sz(s); i++) {
      hs[i].first = (hs[i - 1].first * base + s[i - 1]) % mod1;
      hs[i].second = (hs[i - 1].second * base + s[i - 1]) % mod2;
      pot[i].first = (pot[i - 1].first * base) % mod1;
      pot[i].second = (pot[i - 1].second * base) % mod2;
    }
  }
  pii get(int l, int r) {
    l++;
    r++;
    long long x1 = hs[r].first;
    long long y1 = (hs[l - 1].first * pot[r - l + 1].first) % mod1;
    long long x2 = hs[r].second;
    long long y2 = (hs[l - 1].second * pot[r - l + 1].second) % mod2;
    return pii((x1 - y1 + mod1) % mod1, (x2 - y2 + mod2) % mod2);
  }
};
