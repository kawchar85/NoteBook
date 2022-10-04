struct Line {
  //mx+c
  mutable ll m, c, p;
  bool operator<(const Line& o) const { return m < o.m; }
  bool operator<(ll x) const { return p < x; }  };
//for min query LineContainer(true), normally->max
struct LineContainer : multiset<Line, less<>> {
  // (for doubles, use inf = 1/.0, div(a,b) = a/b)
  static const ll inf = LLONG_MAX;
  int mnQ=1;
  LineContainer(bool minQuery=false){
    if(minQuery) mnQ=-1;  else mnQ=1; }
  ll div(ll a, ll b) { // floored division
    return a / b - ((a ^ b) < 0 && a % b); }
  bool isect(iterator x, iterator y) {
    if (y == end()) return x->p = inf, 0;
    if (x->m == y->m) x->p = x->c > y->c ? inf : -inf;
    else x->p = div(y->c - x->c, x->m - y->m);
    return x->p >= y->p;  }
  void add(ll m, ll c) {
    m*=mnQ, c*=mnQ;
    auto z = insert({m, c, 0}), y = z++, x = y;
    while (isect(y, z)) z = erase(z);
    if(x != begin() && isect(--x,y)) isect(x,y = erase(y));
    while ((y = x) != begin() && (--x)->p >= y->p)
      isect(x, erase(y));  }
  ll query(ll x) {
    assert(!empty()); auto l = *lower_bound(x);
    return mnQ*(l.m * x + l.c);  }  };
score(l,r) = sum{(i-l)*ai} ; i=l+1 ... r
           = sum{i*ai} - l*sum{ai}
           = ms[r]-ms[l]-l*s[r]+l*s[l]
   ans = max{ms[i]-ms[j]-j*s[i]+j*s[j]} for j<i
       = max{ (-j)*(s[i])+(j*s[j])-ms[j] + ms[i]}
       = max{ fj(s[i]) + ms[i]}
       = max{ fj(s[i])} + ms[i]
    fj(x) = -j*(x)+(j*s[j]-ms[j])
container.add(0,0);
for(i=1; i<=n; i++){
  ans=max(ans, container.query(cum[i])+cum2[i]);
  container.add(-i, i*cum[i]-cum2[i]); }
