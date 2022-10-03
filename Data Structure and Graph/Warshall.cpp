void warshall(ll n){
  for(k=1; k<=n; k++)
    for(i=1; i<=n; i++)
      for(j=1; j<=n; j++){
        ll x=v[k].second;
        dp[k][i][j]=min(dp[k-1][i][j], dp[k-1][i][x]+dp[k-1][x][j]); dp[k][j][i]=dp[k][i][j]; }	}
