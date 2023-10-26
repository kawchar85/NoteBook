const int N = 2e3 + 9; //O(N^3)
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct Blossom {
  int vis[N],par[N],orig[N],match[N],aux[N],t,n;
  bool ad[N]; vector<int> g[N]; queue<int> Q;
  Blossom() {} Blossom(int _n){
    n = _n; t = 0;
    for(int i = 0; i <= _n; ++i) {
      g[i].clear(); match[i] = par[i] = 0;
      vis[i] = aux[i] = ad[i] = orig[i] = 0; }  }
  void add_edge(int u, int v) {
    g[u].push_back(v); g[v].push_back(u); }
  void augment(int u, int v) {
    int pv = v, nv;
    do { pv = par[v]; nv = match[pv]; match[v] = pv;
      match[pv] = v; v = nv; } while (u != pv); }
  int lca(int v, int w) { ++t;
    while (true) { if (v) {
      if (aux[v] == t) return v; aux[v] = t;
      v = orig[par[match[v]]]; } swap(v, w); } }
  void blossom(int v, int w, int a) {
    while (orig[v] != a) {
      par[v] = w; w = match[v]; ad[v] = true;
      if (vis[w] == 1) Q.push(w), vis[w] = 0;
      orig[v] = orig[w] = a; v = par[w]; } }
  bool bfs(int u) {
    fill(vis + 1, vis + n + 1, -1);
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
