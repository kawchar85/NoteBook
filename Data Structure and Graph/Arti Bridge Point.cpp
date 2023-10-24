vl adj[MAX],point; vector<pll> span_edge,back_edge,bridge;
bool arti_point[MAX],vis[MAX]; ll d[MAX],low[MAX],timer=0;
void arti_BP(ll u=1, ll par=-1){
  low[u]=d[u]=++timer; vis[u]=1; ll child=0;
  for(auto now : adj[u]) { if(now==par)continue;
    if(vis[now]){
      low[u]=min(low[u],d[now]);
      if(d[now]<d[u]) back_edge.push_back({u,now});
    } else { span_edge.push_back({u,now}); arti_BP(now,u);
      low[u]=min(low[u],low[now]);
      if(d[u]<low[now]) bridge.push_back({u,now});
      if(d[u]<=low[now] && par!=-1) arti_point[u]=1;
      child++; }
    if(child>1 && par==-1) arti_point[u]=1; } }
struct OnlineBridge { // 1 indexed
  vector<int>par,dsu_2ecc,dsu_cc,dsu_cc_size,last_visit;
  int bridges, lca_it;
  OnlineBridge() {}
  OnlineBridge(int n) {
    dsu_2ecc.resize(n + 1); dsu_cc.resize(n + 1); 
    par.resize(n + 1); dsu_cc_size.resize(n + 1);
    lca_it = 0; last_visit.assign(n + 1, 0);
    for (int i=0; i<= n; ++i) {
        dsu_2ecc[i] = dsu_cc[i] = i;
        dsu_cc_size[i] = 1; par[i] = -1;  }
    bridges = 0;  }
  int find_2ecc(int u) {
    if (u == -1) return -1;
    return dsu_2ecc[u]==u?u:dsu_2ecc[u]=find_2ecc(dsu_2ecc[u]); }
  int find_cc(int u) {
    u = find_2ecc(u);
    return dsu_cc[u]==u?u:dsu_cc[u]=find_cc(dsu_cc[u]);}
  void make_root(int u) {
    u = find_2ecc(u);
    int root = u, child = -1;
    while (u != -1) {
      int p = find_2ecc(par[u]);
      par[u] = child; dsu_cc[u] = root;
      child = u; u = p; }
    int previous_root = child;
    dsu_cc_size[root] = dsu_cc_size[previous_root];}
  void merge_path (int u, int v) {
    ++lca_it;
    vector<int> path_u, path_v;
    int lca = -1;
    while (lca == -1) {
      if (u != -1) {
        u = find_2ecc(u); path_u.push_back(u);
        if (last_visit[u] == lca_it){
          lca = u; break; }
        last_visit[u] = lca_it; u = par[u]; }
      if (v != -1) {
        v = find_2ecc(v); path_v.push_back(v);
        if (last_visit[v] == lca_it){
          lca = v; break; }
        last_visit[v] = lca_it; v = par[v]; } }
    for (int x : path_u) {
      dsu_2ecc[x] = lca; if (x == lca) break;
      --bridges; }
    for (int x : path_v) {
      dsu_2ecc[x] = lca; if (x == lca) break;
      --bridges; } }
  void add_edge(int u, int v) {
    u = find_2ecc(u); v = find_2ecc(v);
    if (u == v) return;
    int comp_u = find_cc(u), comp_v = find_cc(v);
    if (comp_u != comp_v) {
      ++bridges;
      if (dsu_cc_size[comp_u] > dsu_cc_size[comp_v]) {
        swap(u, v); swap(comp_u, comp_v); }
      make_root(u); par[u] = dsu_cc[u] = v;
      dsu_cc_size[comp_v] += dsu_cc_size[u]; }
    else { merge_path(u, v); } } }online_bridge;
int main() {
  online_bridge = OnlineBridge(n);
  online_bridge.add_edge(u, v); }
