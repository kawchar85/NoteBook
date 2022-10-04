struct matrix{
  int a[2][2] = {{0,0},{0,0}};
  matrix operator *(const matrix& other){
    matrix product;
    for(int i = 0;i<2;i++){
      for(int j = 0;j<2;j++){
        for(int k = 0;k<2;k++)
        (product.a[i][j]+=(a[i][k]*other.a[k][j])%mod)%=mod;
      }
    }
    return product;
  }
};
matrix bix(matrix a,int n){
  matrix ret; ret.a[0][0] = 1; ret.a[1][1] = 1;
  while(n>0){
    if(n&1) ret = ret*a;  a = a*a; n/=2;
  }
  return ret;
}
int32_t main(){
  matrix mult; mult.a[0][0] = 0; 
  mult.a[0][1] = 1; mult.a[1][0] = 1; mult.a[1][1] = 1;
  matrix ans = bix(mult,n);//or ans=bix(mult,n-1)
  cout<<ans.a[0][1]<<endl;//or ans.a[1][1] 
  //in or case we have to print n=0 specially
}
//Fast doubling {n,n+1}
pii fib(int n){
  if(n==0) return {0,1};  pii p=fib(n>>1);
  int a=p.F*(2*p.S-p.F);  int b=p.F*p.F+p.S*p.S;
  if(n&1) return {b, b+a};  else return {a,b}; }
