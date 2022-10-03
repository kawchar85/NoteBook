vector<int>g[siz],gin[siz],comps[siz];
int t,n,m,cur,h,k,sz,mark[siz],a[siz]; bool bad,used[siz];
vector<int>component; stack<int>order;
void dfs1(int v) {
  used[v] = true;
  for(auto u : g[v]){ if(!used[u]) dfs1(u); }
  order.push(v);  }
void dfs2(int v) {
  used[v] = 1; component.push_back(v);
  for(auto u : gin[v]){ if(!used[u]) dfs2(u); } }
int32_t main(){  cin>>n>>m;
  for(int i = 1;i<=m;i++){
    int x,y; cin>>x>>y;
    g[x].pb(y); gin[y].pb(x); }
  for(int i=1; i<=n; i++) if(!used[i]) dfs1(i);
  memset(used,0,sizeof used);
  while(order.size()){
    int v = order.top(); order.pop();
    if(!used[v]){
        component.clear(); dfs2(v);
        //component will have all node of this strongly connected component
    }  }  }
