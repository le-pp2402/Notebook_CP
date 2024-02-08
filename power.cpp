const ll mod = 1e9 + 7;

ll power(ll n, ll k, ll mod = 1e9 + 7) {
	if (k == 0) return 1;
	ll ans = power(n, k / 2);
	ans = (ans * ans) % mod;
	if (n % 2) ans = (ans * n) % mod;
	return ans;
}
