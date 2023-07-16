//count unique
#define B_SIZE 550 ///sqrt(MAX)
struct query{ int l,r,id; };
query Q[MAX]; int ar[MAX], ans[MAX], fre[1000006],cnt=0;
bool cmp(query &a, query &b){
  if(a.l/B_SIZE != b.l/B_SIZE) return a.l<b.l;
  return a.l/B_SIZE%2?a.r>b.r:a.r<b.r;  }
void add(int pos) {
  fre[ar[pos]]++; if(fre[ar[pos]]==1) cnt++;  }
void sub(int pos) {
  fre[ar[pos]]--; if(!fre[ar[pos]]) cnt--;  }
int get_ans() { return cnt; }
void MO(int q) {
  sort(Q, Q+q, cmp); int cur_l=0, cur_r=-1;
  for(int i=0; i<q; i++) {
    int L=Q[i].l; int R=Q[i].r;
    while(cur_l>L)  add(--cur_l);
    while(cur_r<R)  add(++cur_r);
    while(cur_l<L)  sub(cur_l++);
    while(cur_r>R)  sub(cur_r--);
    ans[Q[i].id]=get_ans();  } }
//most frequent value
void add(int pos){
  if(cnt[ar[pos]] != 0) fre[cnt[ar[pos]]]--;
  cnt[ar[pos]]++; fre[cnt[ar[pos]]]++;
  max_cnt=max(max_cnt, cnt[ar[pos]]);}
void sub(int pos){
  if(cnt[ar[pos]] != 0) fre[cnt[ar[pos]]]--;
  if(fre[max_cnt]==0) max_cnt--;
  if(max_cnt<1) max_cnt=1;  cnt[ar[pos]]--;
  if(cnt[ar[pos]] != 0) fre[cnt[ar[pos]]]++; }
//cnt sub-array of xor K
void add(int pos){cnt+=fre[ar[pos]^k];fre[ar[pos]]++;}
void sub(int pos){fre[ar[pos]]--;cnt-=fre[ar[pos]^k];}
main(){ ar[i]^=ar[i-1]; Q[i].r=R;
Q[i].l=L-1; //cum[1...x]^cum[1...L-1]=cum[1...L]
