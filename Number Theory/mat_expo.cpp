struct MAT{ll n,m;vector<vector<ll>> v;MAT(){ }
	MAT(ll _n,ll _m){n=_n;m=_m;
	v.assign(n,vector<ll>(m,0));}
	MAT(vector<vector<ll>> a){n=a.size();
	m=n?a[0].size():0;v=a;}
	inline void make_unit(){assert(n==m);
		for(ll i=0;i<n;i++)for(ll j=0;j<n;j++)
		v[i][j]=(i==j);}
	inline MAT operator + (const MAT &b){
		assert(n==b.n and m==b.m);MAT ans(n,m);
		for(ll i=0;i<n;i++)for(ll j=0;j<m;j++)
		ans.v[i][j]=(v[i][j]+b.v[i][j])%mod;return ans;}
	inline MAT operator - (const MAT &b){
		assert(n==b.n and m==b.m);MAT ans(n,m);
		for(ll i=0;i<n;i++)for(ll j=0;j<m;j++)
			ans.v[i][j]=(v[i][j]-b.v[i][j]+mod)%mod;
		return ans;}
	inline MAT operator * (const MAT &b){
		assert(m==b.n);MAT ans(n,b.m);
		for(ll i=0;i<n;i++)for(ll j=0;j<b.m;j++)
			for(ll k=0;k<m;k++)ans.v[i][j]=
			(ans.v[i][j]+(v[i][k]*b.v[k][j])%mod)%mod;
		return ans;}
	inline MAT expo (ll k){
		assert(n==m);MAT tmp=v,ans(n,n);ans.make_unit();
		while(k){if(k&1) ans=ans*tmp;tmp=tmp*tmp;k>>=1;}
		return ans;}
	inline bool operator == (const MAT &b){
		return v==b.v;}
	inline bool operator != (const MAT &b){
		return v!=b.v;}
};