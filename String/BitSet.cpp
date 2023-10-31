bitset<MAX> mask[26];
void computeMask(string &text) {
  for(int i=1; i<(int)text.size(); ++i) {
    int c=text[i]-'a'; mask[c].set(i);  } }
int StringMatchingInRange(string &pattern, string &text, ll l, ll r) {
  if(((int)pattern.size() - 1 )> (r-l+1)) return 0;
  /*computeMask(text);*/
  bitset<MAX> startMask;  startMask.set();
  for(int i=1; i<(int)pattern.size(); ++i) {
    int c=pattern[i]-'a'; startMask &= (mask[c] >> i); }
  for(int i=l-1; i<r; i++) if(startMask[i]) cout<<i+1<<" ";
  return (startMask>>(l-1)).count()-(startMask >> (r-(int)pattern.size()+2)).count();}
//set text[idx]=ch, 1-based idx
void update(int idx, char ch, string &text) {
  char old=text[idx];  mask[old-'a'][idx]=0;
  text[idx]=ch;  mask[ch-'a'][idx]=1; }
main(){  s="#"+s;  t="#"+t; computeMask(t); update(idx,ch,t);
cout<<StringMatchingInRange(s,t,l,r)<<endl;}//search s in t[l..r]
