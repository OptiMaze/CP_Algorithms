// Devarshi

#include<bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i,n) for(i=0;i<n;i++)
#define forn(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define for1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define ford(i, n) for (ll i = (ll)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (ll i = (ll)(a); i <= (ll)(b); ++i)
#define fora(it,x) for(auto it:x)
#define PI 3.14159265
#define sync ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn=1000001;

vvi g(maxn),tg(maxn),comp(maxn);              //SCC by Kosaraju's Algorithm
vpi vp;
int cmp[maxn];
stack<int> stk;
bool vis[maxn];
int edge[maxn];

int cnt=0;


void mark(int x,int kun){

int kah=cmp[x];

if(kun==1){

    if(edge[kah]==0){
        edge[kah]=1;
    }
    else if(edge[kah]==2){
        edge[kah]=3;
    }

}
else{

    if(edge[kah]==0){
        edge[kah]=2;
    }
    else if(edge[kah]==1){
        edge[kah]=3;
    }

}

}

void dfs(int cur){
if(!vis[cur]){
    vis[cur]=true;
    for(auto it:g[cur]){
        dfs(it);
    }
stk.push(cur);
}
}

void dfs_(int cur){
if(!vis[cur]){
    vis[cur]=true;
    comp[cnt].pb(cur);
    cmp[cur]=cnt;
    for(auto it:tg[cur]){
        dfs_(it);
    }
}
}

int main(){

int n;
cin>>n;

fore(i,1,n) vis[i]=false;

int a[n+1];

fore(i,1,n){
cin>>a[i];
}

fore(i,1,n){
int x;
cin>>x;
g[i].pb(x);
tg[x].pb(i);
vp.pb(mp(i,x));
}

fore(i,1,n){
if(!vis[i]){
    dfs(i);                         //Topological sorting
}
}

fore(i,1,n) vis[i]=false;

while(!stk.empty()){
    int val=stk.top();
    stk.pop();
    if(!vis[val]){
        ++cnt;
        dfs_(val);
    }

}

memset(edge,0,sizeof(edge));

for(auto it:vp){

    if(cmp[it.fi]!=cmp[it.se]){
        mark(it.fi,1);
        mark(it.se,2);
    }

}
int ans=0;

fore(i,1,cnt){
if(comp[i].size()>1){
    edge[i]=-1;
    int choose=INT_MAX;
    for(auto it:comp[i]){
        choose=min(choose,a[it]);
    }
    ans+=choose;
}
}
//cout<<ans<<endl;
//fore(i,1,cnt) cout<<edge[i]<<endl;

fore(i,1,cnt){
if(edge[i]==0||edge[i]==2){
    ans+=a[comp[i][0]];
}
}
cout<<ans;
return 0;
}
