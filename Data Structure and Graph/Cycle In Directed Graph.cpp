vector<int>g[siz]; set<int>s,have[siz];
int t,n,m,k,cnt,a[siz],vis[siz]; stack<int>path;
/* code is messy ,dont copy code; its almost same as 
undirected graph, just keep an extra set which whill keep
all vertices still on visiting,and if a see a visited node
which is on the set then its a cycle. */
void go(int u){
  vis[u] = cnt; path.push(u); s.insert(u);
  for(auto x:g[u]){
    if(vis[x] == cnt and s.count(x)){ /// cycle found
        vector<int>v;
        while(path.top()!=x) v.pb(path.top()),path.pop();
        v.pb(path.top()); reverse(v.begin(),v.end());
        if(v.size() == 3){
            cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl; exit(0);
        }
        for(int i = v.size()-1;i>1;i--){ 
          ///i-1 to i, i to 0, 0 to i-1(check)
          int y = v[i],x = v[i-1],god = v[0];
          /// see if exists edge god to x
          if(have[god].count(x)){
              cout<<god<<" "<<x<<" "<<y<<endl; exit(0);
          }
        }
    }
    if(vis[x] == 0) go(x);
  }
  if(path.size()) path.pop();
  s.erase(u);
}
int32_t main(){
  for(int i = 1;i<=n;i++){
    for(int j = 1;j<=n;j++){
      char c; cin>>c;
      if(c == '1'){
          g[i].pb(j); have[i].insert(j); } } }
  for(int i = 1;i<=n;i++){
      if(vis[i]) continue;
      ++cnt; go(i);
  } cout<<-1<<endl; }
