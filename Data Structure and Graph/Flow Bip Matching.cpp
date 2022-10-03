//bip_match_E_rootV.cpp
vector<int>g[siz]; vector<pair<int,int> >inp[siz];
int t,n,m,k,a[siz],dist[siz],match[siz];
bool used[siz],vis[siz];
bool bfs() {
  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    if (match[i] == 0) {
      dist[i] = 0;  q.push(i);
    } else { dist[i] = 1e9; } }
  dist[0] = 1e9;
  while (q.size()) {
    int u = q.front(); q.pop();
    if (dist[u] < dist[0]){
      for (auto v : g[u])
        if (dist[match[v]] == 1e9) {
          dist[match[v]] = dist[u]+1; q.push(match[v]); }
      }
  }
  return dist[0] != 1e9; }
bool dfs(int u){
  for(auto v:g[u]){
    if (match[v] == 0 or (dist[match[v]] == dist[u] + 1 and dfs(match[v])) ){
      match[v] = u; match[u] = v; return true;
    }
  }
  dist[u] = 1e9; return false; }
int hopcroft_karp() {
  for(int i = 0;i<=2*n;i++){
      dist[i] = 1e9; match[i] = 0; }
  int ans = 0;
  while (bfs()){
    for (int i = 1; i <= n; ++i) {
      if (match[i] == 0 && dfs(i)) ++ans; }
  }
  return ans; }
bool is_ok(int mid) {
  for(int i = 1;i<=2*n;i++) {
    g[i].clear();
    for(auto p:inp[i]) {
        if(p.second>mid) continue;
        g[i].pb(p.first);
    }
  }
  int ans = hopcroft_karp();
  return ans == n; }
int32_t main(){
  for(int i = 1;i<=m;i++){
    int x,y,w; cin>>x>>y>>w; 
    inp[x].pb({y+n,w}); inp[y+n].pb({x,w}); a[i] = w; }
  sort(a+1,a+1+m); int l = 1,r = m,ans = -1;
  while(l<=r) {
    int mid = l+(r-l)/2;
    if(is_ok(a[mid])){ ans = a[mid]; r = mid-1; }
    else l = mid+1;
  }
  cout<<ans<<endl; }
