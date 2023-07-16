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
//2D Sparse Table: O(n^2 (logn)^2
int A[MAXN][MAXN]; int M[MAXN][MAXN][LOGN][LOGN];
void Build2DSparse(int N){ //1 based
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++)
        M[i][j][0][0] = A[i][j];
    for(int q = 1; (1<<q) <= N; q++){
      int add = 1<<(q-1);
      for(int j=1; j+add <= N; j++){
        M[i][j][0][q] = merge(M[i][j][0][q-1], M[i][j+add][0][q-1]);  }  }  }
    for(int p=1; (1<<p)<=N; p++){
      int add = 1<<(p-1);
      for(int i=1; i+add <= N; i++){
        for(int q=0; (1<<q) <= N; q++){
          for(int j=1; j<= N; j++)
            M[i][j][p][q] = merge(M[i][j][p-1][q], M[i+add][j][p-1][q]);  } }  } }
//merge() of all A[i][j], where x1<=i<=x2 and y1<=j<=y2
int Query(int x1,int y1,int x2,int y2){
  int kX = log2(x2-x1+1); int kY = log2(y2-y1+1);
  int addX = 1<<kX;  int addY = 1<<kY;
  int ret1 = merge(M[x1][y1][kX][kY], M[x1][y2-addY+1][kX][kY]);
  int ret2 = merge(M[x2-addX+1][y1][kX][kY], M[x2-addX+1][y2-addY+1][kX][kY]);
  return max(ret1, ret2); }
