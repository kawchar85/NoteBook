void add(int cur){ cnt[col[cur]]++; }
void remove_sack(int cur){ cnt[ col[cur]]--; }
void query(){
  int i,x,y,p; cin >> m;
  for(i=0;i<m;i++){
      cin>>x>>y;
      p=parent_find(x,y); if(p>0) q[p].push_back({i,y});
  } }
void dfs(int node, bool keep){
  int i,start,end_time; start=t; sack[t]=node; t++;
  int mx=0,bigchild=-1;
  for(i=0;i<graph[node].size();i++){
    if(sz[ graph[node][i] ] > mx){         
    	mx=sz[ graph[node][i] ]; bigchild=graph[node][i]; }}
  for(i=0;i<graph[node].size();i++){
    if(graph[node][i] == bigchild) continue;
    dfs(graph[node][i],false); }
  end_time=t;	
  if(bigchild!=-1) dfs(bigchild, true);
  for(i=start;i<end_time;i++) add(sack[i]);
  for(i=0;i<q[node].size();i++)
    ans[ q[node][i].first] = cnt[ jeta jante chacchi ]; 
  if(keep) return;
  for(i=start;i<t;i++) remove_sack(sack[i]); }
