//combinatorics_template.cpp
/* when calculating numbers that are going to be powers 
mod them with (mod-1). 
permutation_stuff:
square of a permuation means {p[p[i]], .....} by doing 
square of a permuation : 
each odd length cycle stays same odd length cycle, just
direction changes like below 1-4-2-5-3-1(cycle length 5)
pair with length of permuatiuon by 2 distance one 
1-2-3-4-5-1
each even length cycle divides in two cycles of equal 
length 2-3-4-1-2(len 4) 2-4 and 3-1
**pair prod all pair prod = (sum^2 - each square sum )/2;*/
int t,n,m,x,pos,k,fact[siz];
int bix(int a,int n){
  int ret = 1;
  while(n>0){ if(n&1) (ret*=a)%=mod; (a*=a)%=mod; n/=2; }
  return ret; }
void pre(){
  fact[0] = 1;
  for(int i = 1;i<siz;i++) fact[i] = (fact[i-1]*i)%mod; }
int ncr(int n,int r){
  if(r>n or n<0) return 0;
  if(n == 0 and r == 0) return 1;
  int ret = fact[n];
  (ret*=bix(fact[r],mod-2))%=mod;
  (ret*=bix(fact[n-r],mod-2))%=mod;
  return ret; }
int32_t main(){ pre(); }
//Kawchar
ll inv(ll n, ll M=MOD){ return BigMod(n, M-2, M);}
ll mul(ll x, ll y, ll M=MOD){ return (((x%M)*(y%M))%M);}
ll add(ll A, ll B, ll M=MOD){ return (A%M + B%M)%M;}
ll dvd(ll A, ll B, ll M=MOD){ return mul(A, inv(B, M), M);}
ll sub(ll A, ll B, ll M=MOD){ return (A%M-B%M+M)%M;}
