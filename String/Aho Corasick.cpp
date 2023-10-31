#define t_sz 26
struct node{
  int ending,link,par,next[t_sz]; vector<int> idx;
  node(){
    ending=0; par=-1; link=-1; clean(next,-1); } };
struct aho_corasick{
  vector< node > aho;
  aho_corasick(){ aho.emplace_back(); }
  int ID(char ch){  if('a'<=ch && ch<='z') return ch-'a';
    return ch-'A'; }
  void ADD(string &s,int id=0){
    int now,u=0;
    for(auto ch:s){
      now=ID(ch);
      if(aho[u].next[now]==-1) {
        aho[u].next[now]=aho.size(); aho.emplace_back();}
      u=aho[u].next[now]; }
    aho[u].ending++; aho[u].idx.push_back(id); }
  int transition(int u, int i) {
    if(u==-1) return 0;
    if(~aho[u].next[i]) return aho[u].next[i];
    return aho[u].next[i]=transition(aho[u].link, i); }
  void push_links(){
    queue<int> q; q.push(0);
    while(!q.empty()){
      int u=q.front();q.pop();
      for(int i=0; i<t_sz; i++){
        int v=aho[u].next[i]; if(v==-1) continue;
        aho[v].par=u; aho[v].link=transition(aho[u].link,i);
        aho[v].ending+=aho[aho[v].link].ending;
        for(auto &id : aho[aho[v].link].idx)
            aho[v].idx.push_back(id);
        q.push(v); } } }
  int process(string &s, vector<string> &v){
    //v: list of pattern,int n=v.size();vector<int>pos[n];
    int u=0,sum=0;
    for(int i=0; i<s.size(); i++){
      int x=ID(s[i]); u=transition(u, x);
      sum+=aho[u].ending;
      //for(auto id : aho[u].idx) pos[id].push_back(i);
    }
    /*for(int i=0; i<n; i++){
      for(auto p : pos[i]){
        cout<<" "; cout<<p-v[i].size()+1;} cout<<endl; }*/
    /*vector< int > st[s.size() + 10]; pref[0] = 1;
		i=0...s.size(): pref[i+1] += pref[i+2-v[id].size()];
		st[i-v[id].size()+1].push_back(v[id].size());
		suff[s.size() + 1] = 1;
		i=s.size()-1 ... 0 //#way to make suffix
		for(len : st[i]) suff[i + 1] += suff[i + len + 1];*/
    return sum; }
  void clear(){
    aho.clear();aho.emplace_back();  } };
//min delete from s to avoid the set of string
//pos in s, state in aho-corasick call:solve(0,0)
int solve(int pos, int state) {
  if(ac.aho[state].ending) return INF;
  if(pos==s.size()) return 0;
  if(~dp[pos][state]) return dp[pos][state];
  int x=solve(pos+1, ac.transition(state, ac.ID(s[pos])));
  int y = 1+solve(pos+1, state);
  return dp[pos][state]=min( x , y); }
main() { aho_corasick ac; ac.ADD(s, i);
    ac.push_links(); ac.process(text); ac.clear();}
