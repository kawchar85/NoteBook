int BIT[MAX],N;
void update(int x, int val) {
  while(x <= N) { BIT[x]+=val; x+=x&(-x);} }
int query(int x) { int sum=0; 
  while(x>0) { sum+=BIT[x]; x-=x&(-x);} return sum; }
