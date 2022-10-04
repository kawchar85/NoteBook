ll cnt[MAX];
ll nC4(ll n){ return n*(n-1)*(n-2)*(n-3)/24LL;  }
solve(){
  memset(cnt, 0, sizeof cnt);
  for(i=0; i<n; i++) {  cin>>x;  cnt[x]++;  }
  for(i=1; i<MAX; i++){
    for(j=i+i; j<MAX; j+=i)
      cnt[i]+=cnt[j];
    //cnt[i]=total number such that gcd=i*k,k=1,2,3...
  }
  for(i=1; i<MAX; i++) {
      cnt[i]=nC4(cnt[i]);
    //cnt[i]=total number of group of 4 element s.t. gcd=i*k
  }
  for(i=MAX-1; i>0; i--){
    for(j=i+i; j<MAX; j+=i)
      cnt[i]-=cnt[j];//multiple bad dilam
    //cnt[i]=total number of group of 4 element s.t. gcd=i
  } }
//For Continuous sub-array
map<int, ll> cnt;//cnt[i] = number sub-array s.t. gcd=i
void CountGcd(vector<int>& v) {
  map<int, int> divisors, nextDivisors;
  int n=(int)v.size();
  for(int i=0; i<n; i++){
    nextDivisors.clear();
    for(auto &p : divisors) 
      nextDivisors[__gcd(p.first, v[i])] += p.second;
    nextDivisors[v[i]]++;
    swap(nextDivisors, divisors);
    for (auto &p : divisors)  cnt[p.first] += p.second;  } }
