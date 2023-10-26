int sz[MX],par[MX],dep[MX],val[MX],id[MX],tp[MX],ct;
int tree[3*MX], arr[MX], N, lazy[3*MX];
// here seg tree //
void dfs_sz(int u, int p) {
  sz[u] = 1; par[u] = p; for (int v : adj[u]) {
    if (v == p) continue; dep[v] = dep[u] + 1;
    //edgeToNode[i] = v; value of i'th edge in node v
    par[v] = u; dfs_sz(v, u); sz[u] += sz[v]; } }
void dfs_hld(int u, int p, int top) {
  id[u] = ct++; tp[u] = top;
  arr[ id[u] ] = val[u]; int h_chi = -1, h_sz = -1;
  for (int v : adj[u]) { if (v == p) continue;
    if (sz[v] > h_sz) { h_sz = sz[v]; h_chi = v; } }
  if (h_chi == -1) return; dfs_hld(h_chi, u, top);
  for(int v : adj[u]) {
    if(v==p || v==h_chi) continue; dfs_hld(v,u, v);}}
int pathQuery(int x, int y) { int ret = INT_MIN;
  while (tp[x] != tp[y]) {
    if (dep[tp[x]] < dep[tp[y]]) swap(x, y);
    ret = merge(ret, query(id[tp[x]], id[x]));
    x = par[tp[x]];
  } if (dep[x] > dep[y]) swap(x, y);
  // id[x] + 1 to id[y] in case values are in edge
  ret = merge(ret, query(id[x], id[y])); return ret; }
void updatePath(int x, int y, int add) {
  while (tp[x] != tp[y]) {
    if (dep[tp[x]] < dep[tp[y]]) swap(x, y);
    update(id[tp[x]], id[x], add); x = par[tp[x]];
  } if (dep[x] > dep[y]) swap(x, y);
  update(id[x], id[y], add); }
void updateNode(int u, int val) {update(id[u], val); }
void updateEdge(int u, ll val) { 
  update(id[edgeToNode[u]], val); }
void updateSubTree(int u, int val) {
  update(id[u], id[u]+sz[u]-1, val);}
void init_hld(int n) {
  ct = 0; dep[1] = 0; dfs_sz(1, 1); dfs_hld(1, 1, 1);
  buildSegTree(ct); /*arr[0 ... ct-1]*/ }
