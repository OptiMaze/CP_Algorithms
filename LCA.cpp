#include<bits/stdc++.h>
using namespace std;
const int maxn = 1030,pw=10;  // Remember value of pw will change with maxn. pw = ceil(log(maxn)/log(2))
vector<int> g[maxn];          
int up[maxn][pw],depth[maxn];

void dfs(int cur,int par,int dep){
    depth[cur]=dep;
    up[cur][0]=par;
    for(auto it:g[cur]){
        if(it==par) continue;
        dfs(it,cur,dep+1);
    }
}

int LCA(int a,int b){
    if(depth[a]<depth[b])
        swap(a,b);
    int diff=depth[a]-depth[b];
    for(int i=0;i<=pw;i++){     // Depth of node a and node b should be same before finding the LCA
        if(diff&(1<<i))
        a=up[a][i];
    }
    if(a==b) return a;          // Check if node b is LCA of a or not 
    for(int i=0;i<=pw;i++){     //Find the LCA of nod e a and node b
        if(up[a][i]!=up[b][i]){
            a=up[a][i];
            b=up[b][i];
        }
    }
    return up[a][0];            // LCA of node a and node b
}

int main(){

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif

int t;
cin>>t;
int ctr=0;
while(t--){
    // Make tree    
    memset(up,-1,sizeof(up));
    memset(depth,0,sizeof(depth));
    dfs(1,1,0);                             // DFS to set the base values of nodes and calculate 
    for(int i=1;i<=pw;i++){                 // depth of every node.
        for(int j=1;j<=n;j++){
            up[j][i]=up[up[j][i-1]][i-1];   // Precalculating the table by using dynamic programming.
        }
    }
    int m;
    cin>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        cout<<LCA(a,b)<<endl;
    }
}
return 0;
}