ios_base::sync_with_stdio(0); cin.tie(0);
#define ALL(v) v.begin(),v.end()
#define Unique(a) sort(ALL(a)); (a).resize(unique(ALL(a)) - (a).begin())
iint x4[]={+1,-1,+0,+0}; int y4[]={+0,+0,+1,-1};
int x8[]={+0,+0,+1,-1,-1,+1,-1,+1}; 
int y8[]={-1,+1,+0,+0,+1,+1,-1,-1};
int xk[]={1,1,2,2,-1,-1,-2,-2}; 
int yk[]={2,-2,1,-1,2,-2,1,-1};
//freopen("a.in","r", stdin); 
//freopen("a.out","w", stdout);
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")