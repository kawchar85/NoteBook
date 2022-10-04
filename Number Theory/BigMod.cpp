ll BigMod(ll a,ll p, ll M=MOD){
    if(!p) return 1%M;
    ll x=Biod(a,p/2,M);
    x=(x*x)%M;//Overflow?
    if(p&1) x=(x*a)%M;
    return x;   }
