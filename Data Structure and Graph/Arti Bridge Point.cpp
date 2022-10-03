vl adj[MAX],point; vector<pll> span_edge,back_edge,bridge;
bool arti_point[MAX],vis[MAX]; ll d[MAX],low[MAX],timer=0;
void arti_BP(ll u=1, ll par=-1){
  low[u]=d[u]=++timer; vis[u]=1; ll child=0;
  for(auto now : adj[u]) { if(now==par)continue;
    if(vis[now]){
      low[u]=min(low[u],d[now]);
      if(d[now]<d[u]) back_edge.push_back({u,now});
    } else { span_edge.push_back({u,now}); arti_BP(now,u);
      low[u]=min(low[u],low[now]);
      if(d[u]<low[now]) bridge.push_back({u,now});
      if(d[u]<=low[now] && par!=-1) arti_point[u]=1;
      child++; }
    if(child>1 && par==-1) arti_point[u]=1; } }
