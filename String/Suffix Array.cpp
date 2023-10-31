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
//O(N)
const int N = 3e5 + 9, LG = 18; typedef vector<int> vi;
void induced_sort(const vi &vec, int val_range, vi &SA, const vector<bool> &sl, const vi &lms_idx){
  vi l(val_range, 0), r(val_range, 0);
  for (int c : vec) {
    if(c + 1 < val_range) ++l[c + 1];  ++r[c]; }
  partial_sum(l.begin(), l.end(), l.begin());
  partial_sum(r.begin(), r.end(), r.begin());
  fill(SA.begin(), SA.end(), -1);
  for (int i = lms_idx.size() - 1; i >= 0; --i)
    SA[--r[vec[lms_idx[i]]]] = lms_idx[i];
  for (int i : SA)  if (i >= 1 && sl[i - 1]) {
      SA[l[vec[i - 1]]++] = i - 1;  }
  fill(r.begin(), r.end(), 0);
  for (int c : vec)  ++r[c];
  partial_sum(r.begin(), r.end(), r.begin());
  for(int k=SA.size()-1, i=SA[k]; k>=1; --k, i=SA[k])
    if(i >= 1 && !sl[i - 1]) {
      SA[--r[vec[i - 1]]] = i - 1; } }
vi SA_IS(const vi &vec, int val_range) {
  const int n = vec.size();
  vi SA(n), lms_idx; vector<bool> sl(n);
  sl[n - 1] = 0;
  for (int i = n - 2; i >= 0; --i) {
    sl[i] = (vec[i] > vec[i + 1] || (vec[i] == vec[i + 1] && sl[i + 1]));
    if(sl[i] && !sl[i + 1]) lms_idx.push_back(i + 1); }
  reverse(lms_idx.begin(), lms_idx.end());
  induced_sort(vec, val_range, SA, sl, lms_idx);
  vi new_lms_idx(lms_idx.size()), lms_vec(lms_idx.size());
  for (int i = 0, k = 0; i < n; ++i)
    if(!sl[SA[i]] && SA[i] >= 1 && sl[SA[i] - 1])
      new_lms_idx[k++] = SA[i];
  int cur = 0;  SA[n - 1] = cur;
  for(size_t k = 1; k < new_lms_idx.size(); ++k){
    int i=new_lms_idx[k-1], j=new_lms_idx[k];
    if (vec[i] != vec[j]) {
      SA[j] = ++cur; continue;  }
    bool flag = 0;
    for(int a = i + 1, b = j + 1; ; ++a, ++b) {
      if(vec[a] != vec[b]) { flag = 1; break;  }
      if((!sl[a] && sl[a-1]) || (!sl[b] && sl[b-1])){
        flag = !((!sl[a] && sl[a-1]) && (!sl[b] && sl[b-1]));
        break; } }
    SA[j] = (flag ? ++cur : cur); }
  for (size_t i = 0; i < lms_idx.size(); ++i)
    lms_vec[i] = SA[lms_idx[i]];
  if (cur + 1 < (int)lms_idx.size()) {
    auto lms_SA = SA_IS(lms_vec, cur + 1);
    for (size_t i = 0; i < lms_idx.size(); ++i) {
      new_lms_idx[i] = lms_idx[lms_SA[i]]; } }
  induced_sort(vec, val_range, SA, sl, new_lms_idx);
  return SA; }
vector<int> suffix_array(const string &s, const int LIM = 128) {
  vector<int> vec(s.size() + 1);
  copy(begin(s), end(s), begin(vec));
  vec.back() = '#'; auto ret = SA_IS(vec, LIM);
  ret.erase(ret.begin()); return ret; }
struct SuffixArray {
  int n; string s; vi sa, rank, lcp, lg;
  vector<vi> t;  SuffixArray() {}
  SuffixArray(string _s) {
    n = _s.size(); s = _s;
    sa = suffix_array(s); rank.resize(n);
    for (int i = 0; i < n; i++) rank[sa[i]] = i;
    costruct_lcp(); prec(); build(); }
  void costruct_lcp() {
    //lcp[i] = lcp of suffix started from i and i+1
    int k = 0; lcp.resize(n, 0);
    for (int i = 0; i < n; i++) {
      if(rank[i] == n - 1) { k = 0; continue; }
      int j = sa[rank[i] + 1];
      while (i + k < n && j + k < n && s[i + k] == s[j + k])  k++;
      lcp[rank[i]] = k; if (k)  k--; } }
  void prec() { lg.resize(n, 0);
    for(int i=2; i < n; i++) lg[i]=lg[i/2] + 1; }
  void build() { int sz = n - 1; t.resize(sz);
    for (int i = 0; i < sz; i++) {
      t[i].resize(LG); t[i][0] = lcp[i]; }
    for (int k = 1; k < LG; ++k) {
      for(int i = 0; i + (1 << k) - 1 < sz; ++i){
        t[i][k] = min(t[i][k - 1], t[i + (1 << (k - 1))][k - 1]); } } }
  int query(int l, int r) { int k = lg[r - l + 1];
    return min(t[l][k], t[r - (1 << k) + 1][k]); }
  // lcp of suffix starting from i and j
  int get_lcp(int i, int j) { 
    if(i == j) return n - i; int l=rank[i], r=rank[j];
    if(l > r) swap(l, r); return query(l, r - 1); }
  int lower_bound(string &t) {
    int l = 0, r = n - 1, k = t.size(), ans = n;
    while(l <= r) { int mid = l + r >> 1;
      if(s.substr(sa[mid], min(n - sa[mid], k)) >= t)
      	ans = mid, r = mid - 1; else l = mid + 1;
    } return ans;  }
  int upper_bound(string &t) {
    int l = 0, r = n - 1, k = t.size(), ans = n;
    while(l <= r) { int mid = l + r >> 1;
      if(s.substr(sa[mid], min(n - sa[mid], k)) > t)
       ans = mid, r = mid - 1; else l = mid + 1;
    } return ans; }
  // occurrences of s[p, ..., p + len - 1]
  pair<int, int> find_occurrence(int p, int len) {
    p = rank[p]; pair<int, int> ans = {p, p};
    int l = 0, r = p - 1;
    while (l <= r) { int mid = l + r >> 1;
      if(query(mid, p - 1) >= len) 
      	ans.first=mid, r=mid - 1; else l=mid + 1; }
    l = p + 1, r = n - 1;
    while (l <= r) { int mid = l + r >> 1;
      if(query(p, mid - 1) >= len) 
      	ans.second = mid, l = mid + 1;
      else r = mid - 1; } return ans; }
  ll unique_substring() { ll cnt = 0;
    for (int i = 0; i < n; i++)
      cnt += (n-sa[i]-lcp[i]); return cnt; } };
