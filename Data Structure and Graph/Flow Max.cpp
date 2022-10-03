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
      if (par[v] == -1 && capacity[cur][v]) {
          par[v] = cur; 
          int new_flow = min(flow, capacity[cur][v]);
          q.push({v, new_flow}); } } } return 0; }
//O(V*E*E)
int maxflow(int s, int t) {
  int flow = 0,new_flow;
  while (1){
    new_flow = bfs(s, t); if(new_flow<=0) break;
    flow += new_flow; int cur = t;
    while (cur != s) {
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
  bool bfs(){
    while(!q.empty()){
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
  ll maxFlow()  {
    ll f = 0LL,pushed;
    while(1)  {
      fill(level.begin(), level.end(), -1);
      level[s] = 0;  q.push(s); if(!bfs()) break;
      fill(par.begin(), par.end(), 0);
      while(pushed = dfs(s, flow_inf)) f += pushed;
    } return f; }    };
