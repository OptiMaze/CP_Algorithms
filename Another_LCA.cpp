// Devarshi

#include<bits/stdc++.h>
using namespace std;

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

typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef long double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn=1000001;


vvi g(maxn);
int dp3[100000][100];
int depth[100000],pre[100000];

void dfs(ll curr,ll prev1=-1,ll depth1=0)
{
    dp3[curr][0]=prev1;
    depth[curr]=depth1;
    for(auto it:g[curr]){
        if(it!=prev1){
            dfs(it,curr,depth1+1);
        }
    }
}

ll findLca(ll u,ll v)
{
    if(u==v)
        return u;


    if(depth[u]<depth[v])
        swap(u,v);


    ll rem=depth[u]-depth[v];

    for(ll i=0;i<20;i++)
    {
        if(rem&(1<<i))
        {
            u=dp3[u][i];
        }
    }

    if(u==v)
        return u;
    for(ll i=19;i>=0;i--)
    {
        if(dp3[u][i]!=dp3[v][i])
        {
            u=dp3[u][i];
            v=dp3[v][i];
        }
    }
    return dp3[u][0];
}



int main(){

sync

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("out.txt", "w", stdout);
#endif

memset(dp3,-1,sizeof(dp3));
memset(depth,0,sizeof(depth));
memset(pre,0,sizeof(pre));

    g[1].pb(2);
    g[2].pb(1);
    g[1].pb(3);
    g[3].pb(1);
    g[2].pb(4);
    g[4].pb(2);
    g[3].pb(5);
    g[5].pb(3);
    g[6].pb(2);
    g[2].pb(6);
    g[3].pb(7);
    g[7].pb(3);

    int n=7;
    
    dfs(1);
    for(ll i=1;i<=19;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            if(dp3[j][i-1]!=-1)
            dp3[j][i]=dp3[dp3[j][i-1]][i-1];
        }
    }

cout<<findLca(6,5)<<endl;
return 0;
}
