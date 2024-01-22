//Ford-Fulkerson Edmonds-Karp : Max Flow
/*Directed: cap[x][y]=c; cap[y][x]=0;
  Undirected: cap[x][y]=c; cap[y][x]=c;
  Multiple Edge: cap[x][y]+=c; */
int bfs(int s, int t){
  memset(par,-1,sizeof par);
  par[s] = s; queue<pair<int, int>> q; q.push({s, 1e9});
  while (!q.empty()) {
    int cur=q.front().first; int flow=q.front().second;
    q.pop(); if (cur == t) return flow;
    for (int v : g[cur]) {
      if(par[v] == -1 && capacity[cur][v]) {
        par[v] = cur; 
        int new_flow = min(flow, capacity[cur][v]);
        q.push({v, new_flow}); } } } return 0; }
//O(V*E*E)
int maxflow(int s, int t) {
  int flow = 0,new_flow; while (1){
    new_flow = bfs(s, t); if(new_flow<=0) break;
    flow += new_flow; int cur = t; while (cur != s) {
      int prev=parent[cur]; capacity[prev][cur]-=new_flow;
      capacity[cur][prev] += new_flow; cur = prev;
    } } return flow; }
struct FlowEdge{
  int v,u; ll cap,flow=0LL;
  FlowEdge(int vv, int uu, ll c) {
    v=vv; u=uu; cap=c; /*Edge v to u*/ } };
//O(V*V*E)
struct Dinic{
  const ll flow_inf=LLONG_MAX; vector<int> level, par;
  vector<FlowEdge> edges; vector< vector<int> > adj;
  int n,m=0,s,t; queue<int> q;
  Dinic(int nn, int ss, int tt){
    n=nn+5; s=ss; t=tt;
    adj.resize(n); par.resize(n); level.resize(n); }
  void add_edge(int v, int u, ll cap){
    edges.emplace_back(v,u,cap);
    edges.emplace_back(u,v,0LL);//Ulto edge
    adj[v].push_back(m); adj[u].push_back(m+1); m+=2; }
  bool bfs(){  while(!q.empty()){
      int v=q.front(); q.pop();
      for(int id : adj[v]) {
        if(level[edges[id].u]!=-1 || edges[id].cap - edges[id].flow < 1) continue;
        level[edges[id].u]=level[v]+1;q.push(edges[id].u);
      } } return level[t]!=-1; }
  ll dfs(int v, ll pushed) {
    if(pushed == 0LL) return 0LL; if(v == t) return pushed;
    for(int& cid=par[v];cid<(int)adj[v].size();cid++){
      int id = adj[v][cid];  int u = edges[id].u;
      if(level[v]+1 != level[u] || edges[id].cap - edges[id].flow < 1)  continue;
      ll tr=dfs(u,min(pushed,edges[id].cap-edges[id].flow));
      if(tr == 0)  continue;
      edges[id].flow += tr; edges[id ^ 1].flow -= tr;
      return tr; } return 0LL; }
  ll maxFlow()  { ll f = 0LL,pushed;  while(1)  {
      fill(level.begin(), level.end(), -1);
      level[s] = 0;  q.push(s); if(!bfs()) break;
      fill(par.begin(), par.end(), 0);
      while(pushed = dfs(s, flow_inf)) f += pushed;
    } return f; }   };
//Maximum Bipartite Matching O(N^3)
const int N = 2e3 + 9; mt19937 rnd(chrono::steady_clock
  ::now().time_since_epoch().count());
struct Blossom {
  int vis[N],par[N],orig[N],match[N],aux[N],t,n;
  bool ad[N]; vector<int> g[N]; queue<int> Q;
  Blossom() {} Blossom(int _n){
    n = _n; t = 0; for(int i = 0; i <= _n; ++i) {
      g[i].clear(); match[i] = par[i] = 0;
      vis[i] = aux[i] = ad[i] = orig[i] = 0; }  }
  void add_edge(int u, int v) {
    g[u].push_back(v); g[v].push_back(u); }
  void augment(int u, int v) {  int pv = v, nv;
    do { pv = par[v]; nv = match[pv]; match[v] = pv;
      match[pv] = v; v = nv; } while (u != pv); }
  int lca(int v, int w) { ++t; while (true) { if(v) {
      if (aux[v] == t) return v; aux[v] = t;
      v = orig[par[match[v]]]; } swap(v, w); } }
  void blossom(int v, int w, int a) {
    while (orig[v] != a) {
      par[v] = w; w = match[v]; ad[v] = true;
      if (vis[w] == 1) Q.push(w), vis[w] = 0;
      orig[v] = orig[w] = a; v = par[w]; } }
  bool bfs(int u) {  fill(vis + 1, vis + n + 1, -1);
    iota(orig + 1, orig + n + 1, 1);
    Q = queue<int> (); Q.push(u); vis[u] = 0;
    while (!Q.empty()) {
      int v = Q.front(); Q.pop(); ad[v] = true;
      for (int x : g[v]) {
        if (vis[x] == -1) { par[x] = v; vis[x] = 1;
          if (!match[x]) return augment(u, x), true;
          Q.push(match[x]); vis[match[x]] = 0;
        } else if (vis[x] == 0 && orig[v] != orig[x]){
          int a=lca(orig[v],orig[x]); blossom(x, v, a);
          blossom(v, x, a); } } } return false; }
  int maximum_matching() {
    int ans = 0; vector<int> p(n - 1);
    iota(p.begin(), p.end(), 1);
    shuffle(p.begin(),p.end(),rnd);
    for(int i = 1; i <= n; i++)
     shuffle(g[i].begin(),g[i].end(),rnd);
    for (auto u : p) { if (!match[u]) {
        for(auto v : g[u]) { if (!match[v]) {
          match[u] = v, match[v] = u; ++ans; break;
          } } } }
    for(int i = 1; i <= n; ++i)
     if(!match[i] && bfs(i)) ++ans;
    return ans; } } M;
void solve() {
  M = Blossom (n); M.add_edge(i, j);
  ans = M.maximum_matching();
  //i --> M.match[i]
}
//bipartite graph maximum pair matching kuhn's O(n*m)
vi adj[MAX];bool used[MAX]; int matchR[MAX];
bool try_kuhn(int v) {
  if(used[v]) return 0; used[v] = true;
  for(int to : adj[v]) {
    if(matchR[to] == -1 || try_kuhn(matchR[to])){
      matchR[to] = v; return 1; } } return 0; }
void maxBPM(int n) {
  memset(matchR, -1, sizeof matchR); int total=0;
  for(int i=1; i<=n; i++) {
    memset(used, 0, sizeof used);total+=try_kuhn(i);}
  cout<<total<<endl;
  for(int i=1; i<=n; i++)
    if(matchR[i]!=-1) cout<<matchR[i]<<" "<<i<<endl;}
//Min Cost Max Flow
int cost[MAX][MAX],capacity[MAX][MAX],d[MAX],p[MAX];
bool inq[MAX];
void add_edge(int u, int v, int cap, int c){
  //u--->v : directed , capacity cap, cost c
  adj[u].push_back(v); adj[v].push_back(u);
  cost[u][v]=c; cost[v][u]=-c;
  capacity[u][v]=cap; capacity[v][u]=0; }
void shortest_paths(int n, int s) {
  for(int i=1;i<=n;i++)d[i]=inf, inq[i]=0, p[i]=-1;
  queue<int> q; d[s] = 0; q.push(s); inq[s] = true;
  while(!q.empty()) {
    int u = q.front(); q.pop(); inq[u] = false;
    for(int v : adj[u]) {
      if(capacity[u][v]>0 && d[v]>d[u]+cost[u][v]){
        d[v] = d[u] + cost[u][v]; p[v] = u;
        if(!inq[v]) { inq[v] = 1; q.push(v);}}}}}
//O(V*V*E*E)
int min_cost_flow(int N,int s,int t,int maxFlow=inf){
  int flow = 0,minCost = 0,cur,f;
  while(flow < maxFlow) {
    shortest_paths(N, s); if(d[t] == inf) break;
    f = maxFlow - flow; cur = t;
    while(cur != s) {
    f = min(f, capacity[p[cur]][cur]); cur = p[cur];}
    flow += f; minCost += f * d[t]; cur = t;
    while (cur != s) {  capacity[p[cur]][cur] -= f;
      capacity[cur][p[cur]] += f; cur = p[cur];} }
  return minCost; }
main(){add_edge(u,v,cap,c);cout<<min_cost_flow(n,1,n);}