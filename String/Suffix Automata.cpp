struct SuffixAutomata {
  struct node { int len, link, firstpos;
    map<char, int> nxt;  };
  int sz, last;  vector<node> t;
  SuffixAutomata() {}
  SuffixAutomata(string &s) {
    int n = s.size(); sz = 1; last = 0;
    t.resize(2 * n); t[0].len = 0;
    t[0].link = -1; t[0].firstpos = 0;
    for (auto x: s)  extend(x); }
  void extend(char c) {
    int p = last; if (t[p].nxt.count(c)){
      int q = t[p].nxt[c];
      if(t[q].len == t[p].len + 1) {
         last = q; return;  }
      int clone = sz++;  t[clone] = t[q];
      t[clone].len = t[p].len + 1;
      t[q].link = clone; last = clone;
      while (p != -1 && t[p].nxt[c] == q) {
         t[p].nxt[c] = clone; p = t[p].link; }
      return; }
    int cur = sz++; t[cur].len = t[last].len + 1;
    t[cur].firstpos = t[cur].len; p = last;
    while (p != -1 && !t[p].nxt.count(c)) {
      t[p].nxt[c] = cur;  p = t[p].link; }
    if(p == -1) t[cur].link = 0;
    else { int q = t[p].nxt[c];
      if(t[p].len + 1 == t[q].len) t[cur].link = q;
      else { int clone = sz++;  t[clone] = t[q];
        t[clone].len = t[p].len + 1;
        while (p != -1 && t[p].nxt[c] == q) {
          t[p].nxt[c] = clone; p = t[p].link; }
        t[q].link=t[cur].link=clone; }} last=cur;}
  ll unique_substrings() { /*O(N)*/ ll tot = 0;
    for(int i = 1; i < sz; i++)
        tot += t[i].len - t[t[i].link].len;
    return tot;
    /*vector<int> unq; // unq[i] = unique substring in prefix of length i
      unq.push_back(0);
      for(int i = 0; i < n; i++) { extend(s[i]);
	      ans.push_back(unq.back() + i + 1 - t[t[last].link].len);
    }*/  }
  ll tot_len_diff_substings() { ll tot = 0;
    for(int i = 1; i < sz; i++) {
      ll shortest = t[t[i].link].len + 1;
      ll longest = t[i].len;
      ll num_strings = longest - shortest + 1;
      ll cur = num_strings * (longest + shortest)/2;
      tot += cur; } return tot; }
  int first_occurrence(string &s) { int u = 0;
    for(auto ch : s) { if(!t[u].nxt.count(ch))
      return -1; u = t[u].nxt[ch]; }
    return t[u].firstpos - s.size() + 1; } };
//lexicographically_kth_distinct
ll dp[MAX]; SuffixAutomata sa;
ll dfs_path_count(int u = 0) {
  if(dp[u]) return dp[u];  dp[u] = 1;
  for(auto [ch, v] : sa.t[u].nxt)
      dp[u] += dfs_path_count(v);
  return dp[u]; }
void kth_lexi(ll k, int u = 0) {
  if(!k) {cout << "\n"; return;}  k--;
  for(auto [ch, v] : sa.t[u].nxt) {
    if(dp[v] <= k) k -= dp[v];
    else {cout<<ch; return kth_lexi(k, v); }}}
main() { sa = SuffixAutomata(s);
  dfs_path_count(); kth_lexi(k);}
