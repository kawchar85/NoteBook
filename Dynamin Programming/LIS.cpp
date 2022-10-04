int n,a[N],B[N],len[N];
int find_lis(){
  int ans=0;
  for(int i=1; i<=n; i++){
    len[i]=lower_bound(B+1, B+ans+1, a[i])-B;//Incresing
  //len[i]=upper_bound(B+1, B+ans+1, a[i])-B;//Non-decresing
    ans=max(ans, len[i]);  B[len[i]]=a[i];  }  return ans; }
void print_lis(int ans){
  vector<int> seq;
  for(int i=n; i>=1; i--){
    if(len[i]==ans){  seq.push_back(a[i]);  ans--; }  }
  int i=(int)seq.size();
  while(i--)  cout<<seq[i]<<" \n"[!i];  }
void init(){ clean(B,-1);  clean(len,0); }
