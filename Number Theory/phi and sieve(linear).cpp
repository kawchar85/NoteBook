int lp[MAX+1],phi[MAX+1];
vector<int> prm;
void pre() {
  phi[1]=1;
  for(int i=2; i<=MAX; ++i){
    if(lp[i] == 0){
      lp[i]=i,phi[i]=i-1; prm.push_back(i);
    } else {
      if(lp[i]==lp[i/lp[i]]) phi[i]=phi[i/lp[i]]*lp[i];
      else phi[i]=phi[i/lp[i]]* (lp[i]-1);  }
    for(int j=0; j<(int)prm.size()&&prm[j]<=lp[i]&& i*prm[j]<=MAX; ++j) 
      lp[i*prm[j]] = prm[j]; } }

//Characteristics of phi:
phi=n*MULof(1-1/p)
gcd(i,N)=g --> phi(N/g);
gcd(x,y)=g, 1<=x,y<=N --> sumPhi(N/g);(cumSum->sumPhi)
phi(lcm(a,b))*phi(gcd(a,b))=phi(a)*phi(b)
sum of co-prime → phi(n)*n/2;
sum of gcd(i,N), for i= 1 to N --> sum of (d*phi(n/d)) for all d|N;
sum of LCM(i,N) for i=1 to N --> (N/2) *( x +1) where x=sum of (d* phi(d) ) for all d|N;
sum of gcd(k-1,N), for k=1 to N and gcd(k,N)=1 --> phi(N)*NOD(N) 

//Preity
generalization of Euler’s theorem:
x^n = x^( phi(m)+n mod phi(m)) mod m
LCM sum: 2(SUM-n)=n*(sum of d*phi(d),s.t d|n and d is npt 1)

int phi(int n) { int ret = n;
  for(int i = 2;i*i<=n;i++){
    if(n%i == 0){
      ret-=ret/i;  while(n%i == 0) n/=i;
    } } if(n>1) ret-=ret/n;  return ret; }
ll Euler_Phi(ll n) {
  ll i,result=n;
  for(i=0;i<prime.size()&&prime[i]*prime[i]<=n;i++){
    if(n%prime[i]==0){
      while(n%prime[i]==0) n/=prime[i];
      result=(result/prime[i])*(prime[i]-1); } }
  if(n>1) result=(result/n)*(n-1); return result; }
void Euler() {
  for(int i=0; i<MAX; i++) phi[i]=i;
  for(i=2; i<MAX; i++){
    if(phi[i]==i){ phi[i]=i-1;
      for(j=i+i; j<MAX; j+=i)
        phi[j]=phi[j]/i*(i-1); } } }
