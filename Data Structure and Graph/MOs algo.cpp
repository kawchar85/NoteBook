#define B_SIZE 550 ///sqrt(MAX)
struct query{ int l,r,id; };
query Q[MAX]; int ar[MAX], ans[MAX], fre[1000006],cnt=0;
bool cmp(query &a, query &b){
  if(a.l/B_SIZE != b.l/B_SIZE) return a.l<b.l;
  return a.l/B_SIZE%2?a.r>b.r:a.r<b.r;  }
void add(int pos) {
  fre[ar[pos]]++; if(fre[ar[pos]]==1) cnt++;  }
void sub(int pos) {
  fre[ar[pos]]--; if(!fre[ar[pos]]) cnt--;  }
int get_ans() { return cnt; }
void MO(int q) { sort(Q, Q+q, cmp); int cur_l=0, cur_r=-1;
  for(int i=0; i<q; i++) { int L=Q[i].l; int R=Q[i].r;
    while(cur_l>L) add(--cur_l); while(cur_r<R) add(++cur_r);
    while(cur_l<L) sub(cur_l++); while(cur_r>R) sub(cur_r--);
    ans[Q[i].id]=get_ans();  } }
//query on path: kth smallest number
#define LOG 18
#define B_SIZE 450 //sqrt(2*MAX) ft[2*max]
int ft[2 * MAX], in[MAX], out[MAX], Timer = 1;
//(in[x],out[x]) child of x & each node will appear twice
void DFS(int u, int p) {
  ft[Timer] = u; in[u] = Timer++;
  for(auto v : adj[u]) {
    if(v == p) continue; DFS(v, u);}
  ft[Timer] = u; out[u] = Timer++; }
/*Different version: 
FT[t]=u;in[u]=t++;...out[u]=t-1;(in[x],out[x]] child of x*/
const int blk = 450;
struct DS{ vector<int> cnt[blk], total;
  DS() { total.resize(blk, 0);
    for(int i = 0; i < blk; i++) cnt[i].resize(blk, 0); }
  void insert(int x) { int b = x / blk, idx = x % blk;
    cnt[b][idx]++; total[b]++; }
  void remove(int x) { int b = x / blk, idx = x % blk;
    if(!cnt[b][idx]) return; cnt[b][idx]--; total[b]--; }
  int find(int k) { //sqrt(N), k'th smallest
    for(int i = 0; i < blk; i++) {
      if(total[i]<k) { k -= total[i];continue;}
      for(int j = 0; j < blk; j++) { k -= cnt[i][j];
        if(k<=0) return i * blk + j; }} return 0; }}ds;
struct query{ int l, r, id, lca, k; };
query Q[MAX]; int ans[MAX], times[MAX];
void add(int pos){ds.insert(val[ft[pos]]);}
void sub(int pos){ds.remove(val[ft[pos]]);}
void calc(int pos){ if(!times[ft[pos]]) add(pos);
  else sub(pos); times[ft[pos]] ^= 1; }
int get_ans(int k) {return ds.find(k);}
void MO(int q) {
  sort(Q, Q+q, cmp); int cur_l = 0, cur_r = -1;
  for(int i = 0; i < q; i++) { int L = Q[i].l, R = Q[i].r;
    while(cur_l>L)calc(--cur_l); while(cur_r<R)calc(++cur_r);
    while(cur_l<L)calc(cur_l++); while(cur_r>R)calc(cur_r--);
    if(Q[i].lca) add(Q[i].lca); ans[Q[i].id]=get_ans(Q[i].k);
    if(Q[i].lca) sub(Q[i].lca); }}
main(){ for(int i = 0; i < m; i++) {
    int x, y, k; cin >> x >> y >> k;
    if(in[x] > in[y]) swap(x, y); Q[i].id = i; Q[i].k = k;
    int p = find_lca(x, y);
    if(p == x){Q[i].l = in[x]; Q[i].r = in[y];
      Q[i].lca = 0; } else { Q[i].l = out[x];
      Q[i].r = in[y]; Q[i].lca = in[p]; } }  MO(m); }
