
void dfs(int cur,int par){

int mx1=0,mx2=0;

for(auto it:g[cur]){
    if(it==par) continue;
    dfs(it,cur);
    int val=dp[it]+1;
    mx2=max(val,mx2);
    if(mx1<mx2) swap(mx1,mx2);
}

dia=max(dia,mx1+mx2);
dp[cur]=mx1;

}
