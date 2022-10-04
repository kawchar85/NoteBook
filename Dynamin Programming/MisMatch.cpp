how far back to go from i,j to find first mismatch in a string
int n,a,b,dp[siz],bck[siz][siz]; string s;
int32_t main(){
  cin>>n>>a>>b>>s;  s = "0"+s;
  for(int i = 1;i<=n;i++){
    for(int j = 1;j<=n;j++)
      if(s[i] == s[j]) bck[i][j]=1+bck[i-1][j-1];
  }
  /// bck[i][j] = 4, means s[i] = s[j], a[i-1] = s[j-1],....,s[i-3] = s[j-3] and s[i-4] !=s[j-4]
  /// or from i and j previous 4 are same substring
  dp[0] = 0;
  for(int i = 1;i<=n;i++){
    dp[i] = a+dp[i-1];
    for(int j = 1;j<i;j++){
      int go_back = min(i-j,bck[i][j]);
      dp[i] = min(dp[i],b+dp[i-go_back]);
    }
  }
  cout<<dp[n]<<endl;  }
