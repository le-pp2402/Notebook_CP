#include <bits/stdc++.h>

using namespace std;

#define i64 long long

i64 fpow (i64 val, i64 exp, i64 m) {
  if (exp == 0) return 1ll;
  i64 ret = fpow(val, exp / 2, m) % m;
  if (exp % 2 == 0) {
    return ret * ret % m;
  } else {
    return ret * ret % m * val % m;
  }
}

i64 inv (i64 val, i64 m) {
  return fpow(val, m - 2, m) % m;
}

i64 BSGS(i64 a, i64 bb, i64 m) {
  i64 k = ceil(sqrt(m));
  map<i64, i64> mp;
  vector<i64> baby;
  baby.push_back(1ll);
  mp[1] = 0;
  for (int i = 1; i < k; i++) {
    i64 tmp = ((a % m) * (baby[i - 1] % m)) % m;
    baby.push_back(tmp);
    mp[tmp] = i;
  }
  sort(baby.begin(), baby.end());
  i64 a_k = fpow(inv(a, m), k, m);
  for (i64 i = 0; i < k; i++) {
    if (binary_search(baby.begin(), baby.end(), bb) == true) {
      return mp[bb] + i * k; 
    }
    bb = (bb * a_k) % m;
  }
  return -1;
}

// a ^ x = b (mod m) 
// k = ceil(sqrt(m))
// baby step : a ^ 1, a ^ 2, a ^ 3, a ^ 4 ... a ^ (k - 1)
// giant step: b * a ^ -kr, r = 1.. until  r * k > m
