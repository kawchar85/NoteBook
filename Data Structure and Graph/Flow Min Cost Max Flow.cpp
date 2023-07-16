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
    while (cur != s) {
      capacity[p[cur]][cur] -= f;
      capacity[cur][p[cur]] += f; cur = p[cur];} }
  return minCost; }
main(){add_edge(u,v,cap,c);cout<<min_cost_flow(n,1,n);}
