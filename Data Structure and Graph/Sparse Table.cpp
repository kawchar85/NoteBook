//Samaun Bhai
int find_min(int l,int r){
  int k = log2(r-l+1); //longest power of two
  int extra = r-l+1-(1<<k);
  return min(sp[l][k],sp[l+extra][k]);
}
//Kawchar
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
