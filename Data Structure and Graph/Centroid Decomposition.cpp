vi adj[MAX]; int sz[MAX]; bool is_removed[MAX];
vector< pair<int, int> > ancestors[MAX];
int get_size(int u, int p = -1) { sz[u] = 1;
  for(auto v : adj[u]) {
    if(v == p || is_removed[v]) continue;
    sz[u] += get_size(v, u); } return sz[u]; }
int get_centroid(int u, int n, int p = -1) {
  for(auto v : adj[u]) {
    if(v == p || is_removed[v]) continue;
    if(sz[v]*2 > n) return get_centroid(v, n, u); }
  return u; }
void get_dists(int u, int cen, int p, int cur_dist=1){
  for(auto v : adj[u]) {
    if(v == p || is_removed[v]) continue;
    get_dists(v, cen, u, cur_dist + 1);
  } ancestors[u].push_back({cen, cur_dist}); }
void get_cnts(int u, int p, bool f, int depth = 1) {
  if(depth>k) return; mx_depth=max(mx_depth, depth);
  if(f) cnt[depth]++;
  else ans += cnt[k - depth];
  for(auto v : adj[u]) {
    if(v == p || is_removed[v]) continue;
    get_cnts(v, u, f, depth + 1); } }
void build_cd(int u = 1) {
  int c = get_centroid(u, get_size(u));
  //calculate
  for(auto v : adj[c]) { if(is_removed[v]) continue;
    get_dists(v, c, c); }
  //alt
  mx_depth = 0; cnt[0] = 1;
  for(auto v : adj[c]) { if(is_removed[v]) continue;
    get_cnts(v, c, 0); get_cnts(v, c, 1); }
  fill(cnt + 1, cnt + mx_depth + 1, 0);
  //end-cal
  is_removed[c] = 1;
  for(auto v : adj[c]) {
    if(is_removed[v]) continue; build_cd(v); } }
void update(int u) {
  mn_dist[u] = 0;
  for(auto [p, dist] : ancestors[u])
    mn_dist[p] = min(mn_dist[p], dist); }
int query(int u) {
  int ans = mn_dist[u];
  for(auto [p, dist] : ancestors[u]) {
    ans=min(ans,mn_dist[p]+dist); } return ans; }
void update(int u, bool c) {
  if(c == 1) { mn_dist[u].insert(0);
    for(auto [p, dist] : ancestors[u])
      mn_dist[p].insert(dist);
  } else{ mn_dist[u].erase(mn_dist[u].find(0));
      for(auto [p, dist] : ancestors[u])
        mn_dist[p].erase(mn_dist[p].find(dist));}}
int query(int u) {
  int ans = *mn_dist[u].begin();
  for(auto [p, dist] : ancestors[u])
    ans = min(ans, *mn_dist[p].begin() + dist);
  return ans; }
