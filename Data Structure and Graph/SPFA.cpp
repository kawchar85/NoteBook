//SPFA is a improvement of the Bellman-Ford algorithm
vector< pair<int,int> > adj[MAX]; int d[MAX], cnt[MAX];
bool inqueue[MAX];
bool spfa(int n, int s){
  for(int i=1; i<=n; i++){
    d[i]=inf; inqueue[i]=0; cnt[i]=0; }
  queue<int> q; q.push(s); inqueue[s] = 1; d[s] = 0;
  while(!q.empty()){
    int u = q.front(); q.pop(); inqueue[u] = 0;
    for(auto edge : adj[u]){
      int v = edge.first; int w = edge.second;
      if(d[u] + w < d[v]){
        d[v] = d[u] + w;
        if(!inqueue[v]){
          q.push(v); inqueue[v] = 1; cnt[v]++;
          if(cnt[v] > n) return 0;/*negative cycle*/
        } } } } return 1;  }
