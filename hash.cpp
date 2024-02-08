const int N = 100001;
const ll base = 31;
const ll mod = 1e9 + 7;
int fct[N];
class Hash {
public:
  vector<ll> H;
  int n;
  Hash(string s) {
    this->n = sz(s);
    H.resize(sz(s));
    H[0] = 0;
    for (int i = 1; i < n; i++) {
      H[i] = (H[i - 1] * base + (s[i] - 'a' + 1)) % mod;
    }
		debug(H);
  }
  ll getHash(int l, int r) {
		debug(l, r);
    return (H[r] - (H[l - 1] * fct[r - l + 1]) + mod * mod) % mod;
  }
};
