ll counter=1; //don't forget to ADD(0)
struct node{
  ll cnt[2],next[2];
  node() { cnt[0]=cnt[1]=0; next[0]=next[1]=0; }
}tree[MAX];
void ADD(ll n){
  ll i,now,cur=0;
  for(i=31; i>=0; i--){
    now=getbit(n,i); tree[cur].cnt[now]++;
    if(tree[cur].next[now]==0)
        tree[cur].next[now]=counter++;
    cur=tree[cur].next[now];  } }
ll xor_less_than_k(ll n, ll k){
  //n-->cum xor till now
  ll cur=0,i,now_n,now_k,ans=0;
  for(i=31; i>=0; i--){
    now_k=getbit(k,i); now_n=getbit(n,i);
    if(now_k){ ans+=tree[cur].cnt[now_n];
      if(tree[cur].next[now_n^1]==0) break;
      cur=tree[cur].next[now_n^1];
    } else { if(tree[cur].next[now_n]==0)  break;
        cur=tree[cur].next[now_n]; }  }  return ans; }
int find_min(int n){
  int i,now,ans=0,cur=0;
  for(i=31; i>=0; i--){
    now=getbit(n,i); ans<<=1;
    if(data[cur].next[now]!=0) cur=data[cur].next[now];
    else{ cur=data[cur].next[now^1]; ans++; }} return ans;}
int find_max(int n){
  int cur=0,now,ans=0;
  for(int i=31; i>=0; i--){ now=getbit(n,i); ans<<=1;
    if(data[cur].next[now^1]!=0){
        cur=data[cur].next[now^1];  ans++;
    } else cur=data[cur].next[now];  }  return ans; }
void deleteFromTrie(int n){
  int i,now,cur=0;
  for(i=31; ~i; i--){ now=getbit(n,i); data[cur].cnt[now]--;
    if(data[cur].cnt[now]==0){data[cur].next[now]=0; break;}
    cur=data[cur].next[now]; } }
void delete_trie(){ counter=1; memset(tree,0,sizeof tree); }
//Samaun Bhai
int n,m,k,a[siz],t[siz][26],node = 1;
void in(string s){/*inserting string into the trie*/
  int cur = 0;
  for(int i = 0;i<s.size();i++){
    if(t[cur][s[i]-'a'] == 0){ t[cur][s[i]-'a'] = node++;}
    cur = t[cur][s[i]-'a']; //go to new node
  } }
