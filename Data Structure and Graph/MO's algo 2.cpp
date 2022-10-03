/*mos algo and counting count
answer query offline, devide n inputs by sqrt(n) chunks and
for each chunk answer queury, where r pointer will go only
to the right(at max n times) and l pointer will  move
between same block (which is of length sqrt(n) ). so overall
running timw will be like n*sqrt(n) and we counted count of
count each element with count 5 will contribute in count of
count array with value 1,2,3,4 and 5 
**so if count is k then it will put its mark in all i<=k */
const int mod = 1e9+7,chunk = 550,siz = 3e5+5;
int t,n,m, a[siz],x,id[siz],freq[siz],out[siz],k,cnt_[siz], cnt_of_cnt[siz]; pair<int,int>q[siz];
struct inp{
  int id,l,r; };
vector<inp>todo[siz];
bool cmp(inp a,inp b){
   return a.r<b.r; }
int32_t main(){
  for(int i = 1;i<=n;i++) cin>>a[i];
  int cnt = 1;
  for(int i = 1;i<=n;i++){
    id[i] = cnt; if(i%chunk == 0) cnt++; }
  for(int i = 1;i<=t;i++){
    int x,y; cin>>x>>y;
    todo[id[x]].pb({i,x,y}); }
  for(int i = 1;i<=cnt;i++){
    if(todo[i].size() == 0) continue;
    sort(todo[i].begin(),todo[i].end(),cmp);
    for(int j = 1;j<=n;j++){
        cnt_[j] = 0; cnt_of_cnt[j] = 0; }
    int l = (i-1)*chunk+1,r = l, mx = 1;
    cnt_[a[l]]++; cnt_of_cnt[1]++;
    for(auto x:todo[i]){
      int ind = x.id,cl = x.l,cr = x.r;
      /// reach r, include some
      while(r<cr) {
        r++; cnt_[a[r]]++; cnt_of_cnt[cnt_[a[r]]]++;
        mx = max(mx,cnt_[a[r]]); }
      /// reach l, exclude some
      while(l<cl) {
        cnt_of_cnt[cnt_[a[l]]]--; cnt_[a[l]]--; l++;
        while(mx>0 and cnt_of_cnt[mx] == 0) mx--;  }
      /// reach l, include some
      while(l>cl) {
        l--; cnt_[a[l]]++; cnt_of_cnt[cnt_[a[l]]]++;
        mx = max(mx,cnt_[a[l]]);    }
      int other = cr-cl+1-mx;  int cur = mx-(other+1);
      out[ind] = max(1,1+cur); }  }
  for(int i = 1;i<=t;i++) cout<<out[i]<<endl; }
