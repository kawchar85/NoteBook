//Fast doubling {n,n+1}
pii fib(int n){
  if(n==0) return {0,1};  pii p=fib(n>>1);
  int a=p.F*(2*p.S-p.F);  int b=p.F*p.F+p.S*p.S;
  if(n&1) return {b, b+a};  else return {a,b}; }
