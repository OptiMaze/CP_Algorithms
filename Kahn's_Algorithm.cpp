#include<bits/stdc++.h>
using namespace std;


#define fi first 
#define se second
#define mp make_pair
#define forn(i,n) for(ll i=0;i<n;i++)
#define sync ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;
const ll maxn = 1e5+1;

int main(){

        #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
        #endif
        int n,m;
        cin>>n>>m;
        vector<int> g[n+1];
        int store[n+1];
        for(int i=1;i<=n;i++) store[i] = 0;
        while(m--){
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);
        }
        queue<int> que;
        forn(i,n){
            if(store[i+1]==0) que.push(i+1);
        }
        int nodes = 0;
        vector<int> topo;
        while(!que.empty()){w
            nodes++;
            int val = que.front();
            topo.push_back(val);
            que.pop();
            for(auto it:g[val]){
                if(--store[it]==0) que.push(it);
            }
        }
        if(nodes!=n){
            cout<<"DAG"<<endl;
        }
        else{
            for(auto it:topo) cout<<it<<endl;
        }
        
    return 0;

}
