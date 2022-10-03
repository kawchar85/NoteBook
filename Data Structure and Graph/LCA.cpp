//Kawchar
#define maxN 17 #define MAX 100001
vector<int> adj[MAX]; int lvl[MAX],LCA[MAX][maxN+1];
void DFS(int v, int p) {
  LCA[v][0]=p;
  for(auto x : adj[v]){
      if(x==p) continue; lvl[x]=lvl[v]+1; DFS(x, v); } }
void init(int N) {
  memset(LCA, -1, sizeof LCA);
  lvl[1]=0; DFS(1, -1);
  for(int j=1; j<=maxN; j++) {
    for(int i=1; i<=N; i++) {
      if(~LCA[i][j-1]) {
        int p = LCA[i][j-1]; LCA[i][j]=LCA[p][j-1]; } } }}
int find_lca(int a, int b) {
  if(lvl[a]>lvl[b])  swap(a,b);
  int d=lvl[b]-lvl[a];
  while(d>0) {  int j = log2(d);
    b=LCA[b][j]; d-=(1<<j); }
  if(a==b) return a;
  for(int j=maxN; ~j; j--) {
    if(~LCA[a][j] && (LCA[a][j]!=LCA[b][j])) {
      a=LCA[a][j]; b=LCA[b][j]; } } return LCA[a][0]; }
int RootedLCA(int r, int u, int v) {
  int ur=find_lca(u,r); int rv=find_lca(r,v);
  int uv=find_lca(u,v); if(ur==rv) return uv;
  if(rv==uv) return ur; if(uv==ur) return rv; }
//Samaun Bhai
vector<pair<int,int> >g[siz];
int n,m,par[siz][21],dep[siz],cost[siz],w[siz];
void go(int u,int p){
  par[u][0] = p;
  for(int i=1;i<20;i++) par[u][i]=par[par[u][i-1]][i-1];
  for(auto x:g[u]){
    if(x.first == p) continue;
    cost[x.first]=x.second+cost[u]; dep[x.first]=1+dep[u];
    go(x.first,u); } }
int up(int u,int d){
  for(int i = 0;i<20;i++) if(d&(1<<i)) u = par[u][i];
  return u; }
int lca(int u,int v){
  if(dep[u]<dep[v]) swap(u,v);
  u = up(u,dep[u]-dep[v]); if(u == v) return u;
  for(int i = 19;i>=0;i--){
    if(par[u][i] != par[v][i]){
      u = par[u][i]; v = par[v][i]; } } return par[u][0]; }
int find_dist(int u,int v){
    int ret=cost[u]+cost[v]-2*cost[lca(u,v)]; return ret; }
int32_t main(){ go(1,0); int ans = find_dist(5,9); }
