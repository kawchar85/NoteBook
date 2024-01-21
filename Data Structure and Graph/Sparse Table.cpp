#define LVL 20 //ceil(log_2(MAXN))+1
int arr[MAX], dst[MAX][LVL];
int merge(int x, int y) { return __gcd(x,y); }
//0 based
void build(int n){
  for(int i=0; i<n; ++i) dst[i][0] = arr[i];
  for(int k=1; k<LVL; ++k)
    for(int i=0; (i+(1<<k)-1)<n; ++i)
      dst[i][k]=merge(dst[i][k-1], dst[i+(1<<(k-1))][k-1]);}
int query(int l, int r){
  int k=31-__builtin_clz(r-l+1);
  return merge(dst[l][k], dst[r-(1<<k)+1][k]);  }
vector<vector<vector<int>>> st;
int merge(int a,int b,int c,int d) {
    return min({a, b, c, d}); }
//O(n*m*Log(max(n,m)) ///0-based
void build2DSparseTable(int n,int m){
  int LOG = log2(max(n, m))+1;
  vector<vector<vector<int>>>().swap(st);
  st.resize(n, vector<vector<int>>(m, vector<int>(LOG)));
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      st[i][j][0] = arr[i][j];
  for(int k = 1; k < LOG; k++) {
  for(int i = 0; i + (1<<k) <= n; i++) {
  for(int j = 0; j + (1<<k) <= m; j++) {
    st[i][j][k] = merge(
      st[i][j][k-1],
      st[i+(1<<(k-1))][j][k-1],
      st[i][j+(1<<(k-1))][k-1],
      st[i+(1<<(k-1))][j+(1<<(k-1))][k-1]
    ); } } } }
//O(merge())
int query(int x1,int y1,int x2,int y2) {
  int k = log2(min(x2-x1+1, y2-y1+1))+1;
  return merge(
    st[x1][y1][k-1],
    st[x2-(1<<(k-1))+1][y1][k-1],
    st[x1][y2-(1<<(k-1))+1][k-1],
    st[x2-(1<<(k-1))+1][y2-(1<<(k-1))+1][k-1]
    ); }
