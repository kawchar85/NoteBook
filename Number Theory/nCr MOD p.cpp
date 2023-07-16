//nPr: (n,0)=1, (n,r)=n*(n-1, r-1);
//nCr: (n,0)=1,(n,1)=n,(n,r)=(n-1,r)+(n-1,r-1)
//Ciecular pemu: nPr/r

ll fact[MAX],inv[MAX],invFact[MAX];
ll nCr(ll n, ll r){
    if(r>n) return 0;
    return fact[n]*invFact[r]%MOD*invFact[n-r]%MOD;
}
void PreCalculaton(){
    fact[0]=1;
    for(i=1; i<MAX; ++i)
        fact[i]=i*fact[i-1]%MOD;
    inv[1]=1;
    for(i=2; i<MAX; ++i) ///must be MAX<MOD
        inv[i]=((MOD-MOD/i)*inv[MOD%i])%MOD;
    invFact[0]=1;
    for(i=1; i<MAX; ++i)
        invFact[i]=(invFact[i-1]*inv[i])%MOD;
}