#define MXN 10010
#define M1 1000050169
#define M2 1000004119
#define B1 1021
#define B2 2111
ll pow1[MXN] , pow2[MXN];
void pre(){
  pow1[0] = pow2[0] = 1;
  for(ll i=1; i<MXN; i++){
    pow1[i]=(pow1[i-1]*B1)%M1; pow2[i]=(pow2[i-1]*B2)%M2;}}
struct DoubleHash{
  ll H1[MXN], H2[MXN]; string keystring;
  DoubleHash(string &s){ keystring=s; calculate(s); }
  int id(char ch){ if('a'<=ch && ch<='z') return ch-'a'+1;
    return ch-'A'+27; }
  void calculate(string &str){ll n=str.size(),H1[0]=H2[0]=0;
    for(ll i=1; i<=n; i++){
      H1[i]=(B1*H1[i-1]+id(str[i-1]))%M1;
      H2[i]=(B2*H2[i-1]+id(str[i-1]))%M2;  } }
  pair<ll,ll> tempHash(string &str){
    ll n=str.size(), h1=0, h2=0;
    for(ll i=1; i<=n; i++){
      h1=(B1*h1+id(str[i-1]))%M1;h2=(B2*h2+id(str[i-1]))%M2;
    }  return {h1,h2};  }
  ll getHash1(ll lft,ll rgt){ /*1 based*/ ll len=rgt-lft+1;
    return (H1[rgt]-H1[lft-1]*pow1[len]%M1+M1)%M1;  }
  ll getHash2(ll lft,ll rgt){  ll len=rgt-lft+1;
    return (H2[rgt]-H2[lft-1]*pow2[len]%M2+M2)%M2; }
  pair<ll,ll> getHash(ll lft, ll rgt){
    //pre(): must be calculated
    return {getHash1(lft,rgt), getHash2(lft,rgt)};  }
  ll cmpSub(ll l1, ll r1, ll l2, ll r2){
    ll len1=r1-l1+1,len2=r2-l2+1,eql=0;
    ll low=0, high=min(len1,len2),mid;
    while(low<=high) {
      mid=(low+high)/2;
      if(getHash(l1,l1+mid-1)==getHash(l2,l2+mid-1)){
        eql=mid; low=mid+1;
      } else { high=mid-1;  } }
    if(eql == min(len1, len2)) {
      if(len1==len2) return 0; if(len1<len2) return -1;
      return 1;/*large [l1...r1]*/ }
    if(keystring[l1+eql-1]<keystring[l2+eql-1])
      return -1;  return 1;  }  };
