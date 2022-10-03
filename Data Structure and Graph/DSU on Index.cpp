ll par[MAX],idx[MAX], arr[MAX];
ll findPar(ll v){ if(par[v] == v) return v;
  return par[v] = findPar(par[v]); }
void union_sets(ll v, ll p){ //new par=p
  v=findPar(v); p=findPar(p); par[v]=p; }
void translate(ll x, ll y){ //x-->y
  ll id_x = idx[x]; ll id_y = idx[y];
  if(x == y || id_x == -1) return;
  if(id_y == -1){ //1st occu of y
    idx[y] = id_x; arr[id_x] = y; //update value
  } else { //merge x's with old y
      union_sets(id_x, id_y); }
  idx[x]=-1; }
void init(ll n){
  memset(idx, -1, sizeof idx);
  for(int i=0; i<MAX; i++) par[i]=i;
  for(int i=1; i<=n; i++){
      int id = idx[arr[i]];//index of current element
      if(id == -1) idx[arr[i]] = i; //1st occurence
      else union_sets(i, id); //par[i] = old occu
  } }
//main: translate(x,y); arr[findPar(idx)]
