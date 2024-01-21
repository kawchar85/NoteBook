//DSU on Index
ll par[MAX],idx[MAX], arr[MAX];
ll findPar(ll v){ if(par[v] == v) return v;
  return par[v] = findPar(par[v]); }
void union_sets(ll v, ll p){ //new par=p
  v=findPar(v); p=findPar(p); par[v]=p; }
void translate(ll x, ll y){ //x-->y
  ll id_x = idx[x]; ll id_y = idx[y];
  if(x == y || id_x == -1) return;
  if(id_y == -1){ idx[y]=id_x; arr[id_x]=y;
  } else {union_sets(id_x, id_y); }
  idx[x]=-1; }
void init(ll n){ memset(idx,-1,sizeof idx);
  for(int i=0; i<MAX; i++) par[i]=i;
  for(i=1; i<=n; i++){int id = idx[arr[i]];
      if(id == -1) idx[arr[i]] = i;
      else union_sets(i, id);
  }}//main: translate(x,y); arr[findPar(idx)]
//Array coloring
for(i=q-1; ~i; i--){
for(v=getPar(Q[i].l);v<=Q[i].r;v=getPar(v))
   color[v]=c, par[v] = v + 1; }
//XOR path
//init:w[i]=0,sz[i]=1,par[i]=i,
pii find_par(int v){
  if(par[v] == v) return {v, 0};
  auto [who, wt]=find_par(par[v]);
  par[v] = who; w[v] ^= wt;
  return {who, w[v]}; }
int merge(int u, int v, int x) {
  pii p1=find_par(u),p2=find_par(v);
  u=p1.first; v=p2.first;
  int new_w=p1.second^p2.second^x;
  if(p1.first == p2.first) {
  if(new_w) return -1;return 0;} 
  if(sz[u] < sz[v]) swap(u, v);
  par[v] = u; w[v] = new_w;
  sz[u] += sz[v];return 1; }
