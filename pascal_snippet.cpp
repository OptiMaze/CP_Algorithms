ll dp[61][61];

void pascal(){
  for(int i=0;i<=60;i+=1){
    for(int j=0;j<=i;j+=1){
      if(i==j||j==0) dp[i][j]=1;
      else dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
    }
  }
}

ll ncr(ll n,ll r){
  if(r>n) return 0;
  return dp[n][r];
}
