using ll = uint64_t; using u128 = __uint128_t;
bool isComposite(ll n,ll a,ll d,int s){
  ll x=BigMod(a, d, n);
  if(x==1LL || x==n-1) return 0;
  for(int r=1; r<s; r++){
    x = ( (u128)x*x)%n;
    if(x==n-1) return 0;  }  return 1; }
bool MillerRabin(ll n){
  int s=0; ll d=n-1;
  while((d&1) == 0){  d >>= 1; s++; }
  for(ll a : {2,3,5,7,11,13,17,19,23,29,31,37}){
    if(n==a) return 1;
    if(isComposite(n, a, d, s)) return 0;
  } return 1; }
bool isPrime(ll n){
  if(n==2LL || n==3LL) return 1;
  if(n<5LL || n%2==0 || n%3==0) return 0;
  return MillerRabin(n); }
int pollard_rho(int n){
  if(n%2==0) return 2;
  int x = rand()%n+1; int c = rand()%n+1;
  int y=x, g=1;
  while(g==1){
    x=((x*x)%n+c)%n; y=((y*y)%n+c)%n;
    y=((y*y)%n+c)%n; g= __gcd(abs(x-y),n);
  } return g; }
vector<int>fact;
//O(N^1/4)
void factorize(int n){ if(n==1) return;
  if(isPrime(n)) { fact.push_back(n); return;}
  int divisor=pollard_rho(n);
  factorize(divisor);factorize(n/divisor); }
