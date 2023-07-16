//preity
void add(int cur){ cnt[col[cur]]++; }
void remove_sack(int cur){ cnt[ col[cur]]--; }
void query(){
  int i,x,y,p; cin >> m;
  for(i=0;i<m;i++){
      cin>>x>>y;
      p=parent_find(x,y); if(p>0) q[p].push_back({i,y});
  } }
void dfs(int node, bool keep){
  int i,start,end_time; start=t; sack[t]=node; t++;
  int mx=0,bigchild=-1;
  for(i=0;i<graph[node].size();i++){
    if(sz[ graph[node][i] ] > mx){         
      mx=sz[ graph[node][i] ]; bigchild=graph[node][i]; }}
  for(i=0;i<graph[node].size();i++){
    if(graph[node][i] == bigchild) continue;
    dfs(graph[node][i],false); }
  end_time=t; 
  if(bigchild!=-1) dfs(bigchild, true);
  for(i=start;i<end_time;i++) add(sack[i]);
  for(i=0;i<q[node].size();i++)
    ans[ q[node][i].first] = cnt[ jeta jante chacchi ]; 
  if(keep) return;
  for(i=start;i<t;i++) remove_sack(sack[i]); }
//kawchar
int val[MAX],cnt[MAX],sz[MAX],ans[MAX]; bool big[MAX];
void processQuery(int v){ /*ans[v] = cnt[ ?? ]; */}
void getSize(int v, int p) {
  sz[v] = 1; for(auto u : adj[v]){
    if( u == p ) continue; getSize(u,v); sz[v]+=sz[u];}}
void add(int v, int p, int x){ cnt[ val[v] ] += x;
  for(auto u : adj[v])if(u!=p && !big[u]) add(u, v, x);}
void dfs(int v, int p, bool keep){
  int mx = -1, bigChild = -1; for(auto u : adj[v])
    if(u != p && sz[u] > mx) mx = sz[u], bigChild = u;
  for(auto u : adj[v])
    if(u != p && u != bigChild) dfs(u, v, 0);
  if(bigChild!=-1) dfs(bigChild,v,1), big[bigChild] = 1;
  add(v, p, 1);  processQuery(v);
  if(bigChild != -1) big[bigChild] = 0;
  if(keep == 0){ add(v, p, -1); } }
void init(int root=1){getSize(root,-1);dfs(root,-1,0);}
