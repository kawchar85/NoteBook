//bipartite graph maximum pair matching kuhn's O(n*m)
vector<int>g[sz]; int t,n,m,k,timer,from[sz]; bool used[sz];
bool go(int u){
  used[u] = 1;
  for(auto x:g[u]){
    if(used[x]) continue;
    if(!from[x] or go(from[x])){ from[x] = u; return 1; }
  } return 0; }
main(){ int ans = 0;
  for(int i = 1;i<=n;i++){
      memset(used,0,sizeof used); go(i); }
  for(int  i = 1;i<=n;i++){
      if(from[i] == 0) continue;
      cout<<"match "<<i<<" "<<from[i]<<endl; } }
