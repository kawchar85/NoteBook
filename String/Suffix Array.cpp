vector<int>p,c,lcp;
void build_suffix_array(string& s){
  int alphabet=256, n=(int)s.size(),i,k,cls;
  vector<int> cnt(max(alphabet, n), 0);
  vector<int> ptmp(n), ctmp(n);
  p.resize(n); c.resize(n); pair<int, int> cur, prev;
  for(i=0; i<n; ++i)  cnt[s[i]]++;
  for(i=1; i<alphabet; i++) cnt[i]+=cnt[i-1];
  for(i=0; i<n; i++) p[--cnt[s[i]]]=i;
  c[p[0]]=0; cls=1;
  for(i=1; i<n; i++) {
    if(s[p[i]] != s[p[i-1]]) cls++;
    c[p[i]]=cls-1; }
  for(k=0; (1<<k)<n; ++k) {
    for(i=0; i<n; ++i) {
      ptmp[i]=p[i]-(1<<k);
      if(ptmp[i]<0) ptmp[i]+=n; }
    fill(cnt.begin(),cnt.begin()+cls,0);
    for(i=0; i<n; i++)  cnt[c[ptmp[i]]]++;
    for(i=1; i<cls; i++)  cnt[i]+=cnt[i-1];
    for(i=n-1; ~i; i--) p[--cnt[c[ptmp[i]]]]=ptmp[i];
    ctmp[p[0]]=0; cls=1;
    for(i=1; i<n; ++i) {
      cur={c[p[i]], c[(p[i]+(1<<k))%n]};
      prev={c[p[i-1]], c[(p[i-1]+(1<<k))%n]};
      if(cur!=prev) cls++;  ctmp[p[i]]=cls-1;  }
    c.swap(ctmp);  }  }
void build_lcp_array(string& s){
  int i,k=0,n=(int)s.size(); lcp.resize(n);
  //lcp[i]=lcp of suffix in pos i and pos i-1
  for(i=0; i<n-1; i++) {
    int pi=c[i]; int j=p[pi-1];
    while(s[i+k]==s[j+k]) k++;
    lcp[pi]=k; k=max(k-1, 0); } }
int LCP(int i, int j) {
  //use sparse table/segment tree
  int pi=c[i], pj=c[j]; if(pi>pj) swap(pi,pj);
  int mn=INT_MAX;
  for(i=pi+1; i<=pj; i++) mn=min(mn,lcp[i]);
  return mn;  }
void init(string s) {  s+="$";
  build_suffix_array(s);  build_lcp_array(s); }
bool diffClass(int x, int y, int n){
  if(x>y) swap(x,y); return x<n&&y>n; }
void LongestCommonSubString(string s, string t){
  string ss=s+"@"+t+"$";
  build_suffix_array(ss); build_lcp_array(ss);
  int n=(int)s.size(); int N=(int)ss.size();
  int mx=0,start=0;
  for(int i=1; i<N; i++){
    if(diffClass(p[i], p[i-1], n)){
        if(lcp[i]>mx){ mx=lcp[i]; start=p[i]; } } }
  cout<<ss.substr(start, mx)<<endl; }
//Unique SubString: cnt+=(n-p[i]-1-lcp[i])
//cntSubStr:
int getPrev(int i, int len){
  int ans=i, lo=0,hi=i-1,mid;
  while(lo<=hi){
    mid=(lo+hi)/2;
    if(getLCP(mid, i)>=len){ ans=mid; hi=mid-1; } 
    else {  lo=mid+1; } } return ans;  }
int getNext(int i, int len){
  int ans=i; int lo=i+1,hi=(int)lcp.size()-1,mid;
  while(lo<=hi){
    mid=(lo+hi)/2;
    if(getLCP(mid, i)>=len){ ans=mid;lo=mid+1; } 
    else { hi=mid-1; } } return ans;  }
{call-->
int len=r-l+1;  int SaID=c[l];//index in SA
int L=getPrev(SaID, len); //lower,this is rank of S[l..r]
int R=getNext(SaID, len); //upper
cout<<(R-L+1)<<endl;}
//cnt pair of (i,j):k len same from i,j
struct MyStack{
  stack< pll >st; ll sum;
  MyStack() { sum=0LL; st.push({0LL,0LL}); }
  void pop() { auto x=st.top(); st.pop();
    sum-=(x.first)*(x.second-st.top().second); }
  void push(ll x, ll idx){
    while(st.top().first && st.top().first>x) pop();
    sum+=x*(idx-st.top().second); st.push({x,idx}); }  };
{call-->
MyStack ms;
for(i=2; i<=n; i++){  ms.push(lcp[i],i-1); total+=ms.sum;} }
//k'th pos of t in s
int isEqual(int x){
  int m=(int)t.size();
  for(int i=0; i<m; i++) {
    if(s[i+x]==t[i]) continue; if(s[i+x]<t[i]) return -1;
    else return 1; } return 0; }
int Lower(vector<int>& p){
  int low=0,x,high=(int)p.size()-1,mid;
  while(low<=high) {
    mid=(low+high)/2; x=isEqual(p[mid]);
    if(x<0) low=mid+1; else high=mid-1; } return low;  }
int Uppwer(vector<int>& p){
  int low=0,x, high=(int)p.size()-1, mid;
  while(low<=high) {
    mid=(low+high)/2; x=isEqual(p[mid]);
    if(x<=0) low=mid+1; else high=mid-1; } return low; }
main(){ s+="$"; vector<int> v=build_suffix_array(s);
  for(i=1; i<=n; i++) A[i] = v[i-1];
  wavelet_tree wt(A+1, A+n+1);
  cin>>t>>k; x = Lower(v); y = Uppwer(v);
  if((y-x)<k){pos=-1;} else pos =  1 + wt.kth(x+1, y, k) }
