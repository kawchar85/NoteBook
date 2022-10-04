/*Count number of pali in s[L...R],If the size of palindrome
centered at i is x, then d1[i] stores (x+1)/2. If the size
of palindrome centered at i is x, then d0[i] stores x/2;*/
int d[2][MAX];
void manachar(string &s) {
  int n=(int)s.size();
  for(int t=0; t<2; t++) {
    for(int i=0,l=0,r=-1; i<n; i++){
      int k=(i>r)? 0:min(d[t][l+r-i+(t^1)], r-i+1);
      while(0<=i-k-(t^1) && i+k<n && s[i-k-(t^1)]==s[i+k]) 
        k++;
      d[t][i]=k--;
      if(i+k>r) {  l=i-k-(t^1); r=i+k;  }  } }  }
bool isPalindrom(int l, int r) {//0-based
  if(l>r) return 0; int len=r-l+1; int center=(l+r+1)>>1;
  return (d[(len&1)][center]>=((len+1)>>1));  }
int dp[MAX][MAX]; //cnt pal in s[l--r] = dp[l][r];
void preCalculate(string &s) {
  manachar(s); int n=(int)s.size();
  for(int i=1; i<=n; i++) {
    for(int j=i; j<=n; j++) {
      if(isPalindrom(i-1, j-1)){
        dp[1][j]++; dp[1][n+1]--;
        dp[i+1][j]--;dp[i+1][n+1]++;  }  }  }
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
      dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]; }
