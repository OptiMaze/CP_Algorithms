const int maxn = 1e5+1,logN = 20;

vector<int> g[maxn];
int dp[maxn][logN+1],in[maxn],out[maxn];
int timer=0;

void dfs(int cur,int par){
    in[cur]=++timer;
    dp[cur][0]=par;
    for(int i=1;i<=logN;i++){
        dp[cur][i]=dp[dp[cur][i-1]][i-1];
    }
    for(auto it:g[cur]){
        if(it==par) continue;
        dfs(it,cur);
    }
    out[cur]=++timer;
}

bool is_ancestor(int u,int v){
    return in[u]<=in[v]&&out[u]>=out[v];
}

int find_lca(int u,int v){
    if(is_ancestor(u,v)) return u;
    if(is_ancestor(v,u)) return v;
    for(int i=logN;i>=0;i--){
        if(!is_ancestor(dp[u][i],v))
            u=dp[u][i];
    }
    return dp[u][0];
}
