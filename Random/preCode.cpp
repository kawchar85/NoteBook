#include<bits/stdc++.h>
using namespace std;
#define ALL(v) v.begin(),v.end()
#define clean(x,y) memset(x,y,sizeof(x));
#define endl "\n"
#define MOD 1000000007
#define MAX 200005
typedef long long ll;
int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int TC = 1;
  //cin>>TC;
  for(int cs = 1; cs <= TC; cs++) {
    //cout << "Case " << cs << ": ";
    solve();
  } return 0; }

int x4[]={+1,-1,+0,+0}; int y4[]={+0,+0,+1,-1};
int x8[]={+0,+0,+1,-1,-1,+1,-1,+1}; 
int y8[]={-1,+1,+0,+0,+1,+1,-1,-1};
int xk[]={1,1,2,2,-1,-1,-2,-2}; 
int yk[]={2,-2,1,-1,2,-2,1,-1};
//freopen("a.in","r", stdin); 
//freopen("a.out","w", stdout);
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
