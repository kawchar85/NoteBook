ll BigMod(ll a,ll p, ll M=MOD){
  if(!p) return 1%M;
  ll x=Biod(a,p/2,M); x=(x*x)%M;
  if(p&1) x=(x*a)%M; return x; }

ll Big_Mod(ll a, ll p, ll M=MOD){
  ll result=1;
  while(p>0){ if(p&1){
      result*=a; if(result>M) result%=M; }
    p>>=1; a*=a; if(a>M) a%=M;
  } return result%M; }
