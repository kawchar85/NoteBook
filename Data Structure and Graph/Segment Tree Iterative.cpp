ll tree[1 << 19];
void update(int idx, int val) {
  tree[idx += n] += val;
  for(idx /= 2; idx; idx /= 2) 
    tree[idx]=tree[2*idx]+tree[2*idx+1]; }
ll query(int lo, int hi) {
  ll ra = 0, rb = 0;
  for(lo+=n, hi+=n+1; lo<hi; lo/=2, hi/=2){
    if (lo & 1) ra = ra + tree[lo++];
    if (hi & 1) rb = rb + tree[--hi]; }
  return ra + rb; }
