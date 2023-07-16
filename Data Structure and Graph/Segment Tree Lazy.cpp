ll arr[MAX]; int N;
struct info{
  ll lazy,val; info() {lazy=0LL; val=0LL; }
}tree[3*MAX];
void propagate(int node, int l, int r) {
  tree[node].val+=tree[node].lazy*(r-l+1);
  if(l!=r){
    tree[2*node].lazy+=tree[node].lazy;
    tree[2*node+1].lazy+=tree[node].lazy;
  } tree[node].lazy=0; }
ll merge(ll x, ll y) {return x+y;}
void build(int node, int l,int r) {
  if(l==r){
    tree[node].lazy=0;tree[node].val=arr[l]; return;}
  int mid=(l+r)/2;
  build(node*2,l,mid);build(node*2+1,mid+1,r);
  tree[node].lazy=0LL;
  tree[node].val=merge(tree[node*2].val,tree[2*node+1].val);}
ll query(int node,int l,int r,int i,int j){
  propagate(node,l,r); if(i>r || j<l) return 0LL;
  if(l>=i && r<=j) return tree[node].val;
  int mid=(l+r)/2;
  auto x=query(node*2,l,mid,i,j);
  auto y=query(node*2+1,mid+1,r,i,j);return merge(x,y);}
int searchQuery(int node, int l, int r, ll sum) {
  propagate(node,l,r); int mid=(l+r)/2;
  if(l==r) return l; ll x=tree[2*node].val;
  if(sum<=x) return searchQuery(2*node, l, mid, sum);
  else return searchQuery(2*node+1, mid+1, r, sum-x);}
void update(int node,int l,int r,int i,int j,ll val){
  propagate(node,l,r); if(i>r || j<l) return;
  if(l>=i && r<=j) {
    tree[node].lazy+=val;propagate(node,l,r);return;}
  int mid=(l+r)/2; update(node*2,l,mid,i,j,val);
  update(node*2+1,mid+1,r,i,j,val);
  tree[node].val=merge(tree[node*2].val,tree[node*2+1].val);}
void build(int n){ N=n; build(1,0,N-1);}
void update(int i, int j, ll val){
  update(1,0,N-1,i,j,val); }
ll query(int x, int y){ return query(1,0,N-1,x,y); }
