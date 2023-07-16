//nPr: (n,0)=1, (n,r)=n*(n-1, r-1);
//nCr: (n,0)=1,(n,1)=n,(n,r)=(n-1,r)+(n-1,r-1)
//Circular permutation: nPr/r

ll fact[MAX],inv[MAX],invFact[MAX];
ll nCr(ll n, ll r){ if(r>n) return 0;
  return fact[n]*invFact[r]%MOD*invFact[n-r]%MOD; }
void PreCalculaton(){ fact[0]=1;
  for(i=1; i<MAX; ++i) fact[i]=i*fact[i-1]%MOD;
  inv[1]=1;
  for(i=2; i<MAX; ++i) ///must be MAX<MOD
      inv[i]=((MOD-MOD/i)*inv[MOD%i])%MOD;
  invFact[0]=1;
  for(i=1; i<MAX; ++i) 
    invFact[i]=(invFact[i-1]*inv[i])%MOD; }
//nCr_mod_p_by_lucas_for_small_p._O(LogN)
ll Lucas(ll n, ll m){
  if(n==0 && m==0) return 1ll;
  ll ni = n % MOD; ll mi = m % MOD;
  if(mi>ni) return 0;
  return (Lucas(n/MOD, m/MOD)*nCr(ni, mi))%MOD; }
ll nCr_by_lucas(ll n, ll r){ return Lucas(n, r); }

//nCr_mod_M, M_is_not_prime
const int N = 142858; //need primes <=M (nCr%M)
int spf[N]; vector<int> primes;
void sieve(){
  for(int i = 2; i < N; i++){
    if(spf[i] == 0) spf[i] = i, primes.push_back(i);
    int sz = primes.size();
    for(int j = 0; j < sz && i * primes[j] < N && primes[j] <= spf[i]; j++)
      spf[i * primes[j]] = primes[j]; } }

// returns n! % mod, mod = multiple of p
// O(mod * log(n))
int factmod(ll n, int p, const int mod){
  vector<int> f(mod + 1); f[0] = 1 % mod;
  for(int i = 1; i <= mod; i++){
    if (i % p) f[i] = 1LL * f[i - 1] * i % mod;
    else f[i] = f[i - 1]; }
  int ans = 1 % mod;
  while (n > 1) {
    ans = 1LL * ans * f[n % mod] % mod;
    ans = 1LL*ans*BigMod(f[mod], n/mod, mod)%mod;
    n /= p;
  } return ans; }
ll multiplicity(ll n, int p){
  ll ans = 0;
  while (n) { n /= p; ans += n;}  return ans;}
// C(n, r) modulo p^k
// O(p^k log n)
int ncr(ll n, ll r, int p, int k){
  if(n < r || r < 0) return 0;
  int mod = 1;
  for (int i = 0; i < k; i++) { mod *= p; }
  ll t = multiplicity(n, p) - multiplicity(r, p) - multiplicity(n - r, p);
  if(t >= k) return 0;
  int ans = 1LL * factmod(n, p, mod) * inverse(factmod(r, p, mod), mod) % mod * inverse(factmod(n - r, p, mod), mod) % mod;
  ans = 1LL * ans * BigMod(p, t, mod) % mod;
  return ans;
}
pair<ll, ll> CRT(ll a1, ll m1, ll a2, ll m2) {
  ll p, q;
  ll g = e_gcd(m1, m2, p, q);
  if(a1 % g != a2 % g) return make_pair(0, -1);
  ll m = m1 / g * m2;
  p = (p % m + m) % m;  q = (q % m + m) % m;
  return make_pair((p * a2 % m * (m1 / g) % m + q * a1 % m * (m2 / g) % m) %  m, m); }
// O(m log(n) log(m))
int ncr(ll n, ll r, int m) {
  if(n < r || r < 0) return 0;
  pair<ll, ll> ans({0, 1});
  while (m > 1) {
    int p = spf[m], k = 0, cur = 1;
    while (m % p == 0) {
      m /= p; cur *= p; ++k; }
    ans=CRT(ans.first, ans.second, ncr(n,r,p,k),cur);
  } return ans.first; }
