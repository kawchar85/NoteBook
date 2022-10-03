int n,a[siz],tree[4*siz],lazy[4*siz];
void dolazy(int par,int l,int r){
  tree[par]+=lazy[par];
  if(l!=r){
      lazy[2*par]+=lazy[par]; lazy[2*par+1]+=lazy[par]; }
  lazy[par] = 0;  }
void build(int par=1,int l=0,int r=n-1){
  if(l == r){ tree[par] = a[l]; return; }
  int mid = l+r>>1;
  build(2*par,l,mid); build(2*par+1,mid+1,r);
  tree[par] = min(tree[2*par],tree[2*par+1]); }
int get_min(int par,int l,int r,int L,int R){
  dolazy(par,l,r);
  if(r<L or l>R) return 1e9;
  if(l>=L and r<=R) return tree[par];
  int mid = l+r>>1;
  return min(get_min(2*par,l,mid,L,R), get_min(2*par+1,mid+1,r,L,R)); }
void upd(int par,int l,int r,int L,int R,int val){
  dolazy(par,l,r);
  if(r<L or l>R) return;
  if(l>=L and r<=R){
      lazy[par] += val; dolazy(par,l,r); return; }
  int mid = l+r>>1;
  upd(2*par,l,mid,L,R,val); upd(2*par+1,mid+1,r,L,R,val);
  tree[par] = min(tree[2*par],tree[2*par+1]); }
int mins(int l,int r){ return get_min(1,1,n,l,r); }
void up(int l,int r,int val){ upd(1,1,n,l,r,val); }
//Kawchar
int searchQuery(int node, int l, int r, ll sum) {
  propagate(node,l,r); int mid=(l+r)/2;
  if(l==r) return l;  ll x=tree[2*node].val;
  if(sum<=x) return searchQuery(2*node, l, mid, sum);
  else return searchQuery(2*node+1, mid+1, r, sum-x); }
