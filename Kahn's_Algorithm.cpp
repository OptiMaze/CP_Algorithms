#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000;
vector<int> g[maxn];
int indeg[maxn];
int main(){
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("o.txt", "w", stdout);
#endif
int n,m;
cin>>n>>m;
multiset< pair<int,int> > pq;
while(m--){
    int x,y;
    cin>>x>>y;
    g[x].push_back(y);
    indeg[y]++;
}
for(int i=1;i<=n;i++){
    pq.insert(make_pair(indeg[i],i));
}
vector<int> topo;
while(!pq.empty()){
    pair<int,int> p=*pq.begin();
    pq.erase(pq.begin());
    if(p.first!=0){
        cout<<"Impossible : Not DAG";
        return 0;
    }
    topo.push_back(p.second);
    for(auto it:g[p.second]){
        auto iit=pq.find(make_pair(indeg[it],it));
        pair<int,int> ph=*iit;
        ph.first--;
        indeg[ph.second]=ph.first;
        pq.erase(iit);
        pq.insert(ph);
    }
}
for(auto it:topo){
    cout<<it<<" ";
}
}