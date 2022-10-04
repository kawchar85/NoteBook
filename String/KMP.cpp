/* longest suffix ending at pos i which is also a prefix
pattern t and text s, so to find make new string 
ss = t+"#"+s and see which ind gives len = size of t*/
/*π[i]=the longest length of a substring ending in position
i, that coincides with the prefix.
search: if(pi[i]==n) pos=i-2n.
compress: k=n-pi[n-1],if(n%k==0) ans=k
pali pref: s=s+'#'+rev, pi[s.size()-1];
pali suf: s=rev+'#'+s, pi[s.size()-1]; */
vector<int> prefix_function(string s){
  int n = (int)s.length(); vector<int> pi(n);
  for(int i = 1; i < n; i++) {
    int j = pi[i-1];
    while(j>0 && s[i] != s[j]) j = pi[j-1];
    if(s[i] == s[j]) j++;
    pi[i] = j; }  return pi;  }
/*Given a string s of length n. Count the number of
 appearances of each prefix s[0…i] in string T. */
vi count_prefix(string s, string t){
  int n=s.size(),i,m=t.size(); string S=s;  S+="#";  S+=t;
  vi ans(S.size()+2); vi pi = prefix_function(S);
  for(int i=n+1; i<S.size(); i++)  ans[pi[i]]++;
  for(i=S.size()-1; i>n+1; i--) ans[pi[i-1]]+=ans[i];
  for(int i=n+1; i<=S.size(); i++) ans[i]++;
  return ans; }
