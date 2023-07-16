a+b=a^b+2*(a&b); a^b=(a|b)&(~a|~b)
#define setbit(n) (n&-n)
#define bitOn(n,i) ((1LL<<i)|n)
#define bitOn2(n,i,j) ((((1LL<<(j-i+1))-1)<<i)|n)
#define bitOff(n,i) (~(1LL<<i)&n)
#define bitOff2(n,i,j) (~(((1LL<<(j-i+1))-1)<<i)&n)
#define bitToggle(n,i) ((1LL<<i)^n)
#define bitToggle2(n,i,j) ((((1LL<<(j-i+1))-1)<<i)^n)
#define bitOnAll(n) (n=-1)
#define bitOffAll(n) (n=0)
#define getbit(n,i) ((n>>i)&1)
#define last1cng(n) (n)&((n)-1)
#define last0cng(n) ~(last1cng(~(n)))
//all the subsets of the mask
void subSet(ll mask){
  for(ll i = mask; i>0; i = (i-1)&mask)
    cout<<bitset<8>(i)<<endl; }
