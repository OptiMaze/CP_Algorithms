#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+1;

vector< vector<int> > g(maxn),tg(maxn);
vector<int> vis(maxn,false);
stack<int> stk;
vector<int> component_collection(maxn);

int component = 0;

void dfs(int cur){
    vis[cur] = true;
    for(auto it:g[cur]){
        if(vis[it]) continue;
        dfs(it);
    }
    stk.push(cur);

}

void tdfs(int cur){
    vis[cur] = true;
    component_collection[cur] = component;
    for(auto it:tg[cur]){
        if(vis[it]) continue;
        tdfs(it);
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    int n,m;
    cin>>n>>m;
    int people[n+1];
    for(int i=1;i<=n;i++) cin>>people[i];
    vector<pair<int,int> > edges; 
    while(m--){
        int x,y;
        cin>>x>>y;
        edges.push_back(make_pair(x,y));
        g[x].push_back(y);
        tg[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    fill(vis.begin(),vis.end(),false);
    while(!stk.empty()){
        int val = stk.top();
        stk.pop();
        if(vis[val]) continue;
        ++component;
        tdfs(val);
    }
    // Component of each node is stored in component_collection 
    return 0;
}
