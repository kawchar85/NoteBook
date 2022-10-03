struct Edge{
  int u,v,w; Edge(){}
  Edge(int x,int y,int z){ u=x;v=y;w=z; } };
bool operator<(Edge a,Edge b){ return a.w<b.w; }
vector<Edge>E; int par[MAX],Size[MAX];
int find_par(int x){
  return par[x]==x?x:par[x]=find_par(par[x]); }
void union_sets(int a, int b){
  a=find_set(a); b=find_set(b);
  if(a!=b) { if(Size[a]<Size[b]) swap(a,b);
    parent[b]=a; Size[a]+=Size[b]; } }
int MST(int n) {
  int i,cnt=0,u,v,total=0;
  for(i=1; i<=n; i++) par[i]=i;
  sort(E.begin(),E.end());
  for(auto now : E){
    u=find_par(now.u);  v=find_par(now.v);
    if(u==v) continue;  union_sets(u,v);
    total+=now.w;  cnt++; }
  if(cnt!=n-1) total=-1;  return total; }
