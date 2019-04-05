/*
We will not return to the countless mistakes of the past
I will not relive the failures of the man I once was

Only through dedication will I destroy all preconception

No longer will I let myself be truly satisfied with the standard
We will not return to the countless mistakes of the past

Only through dedication will I destroy all preconception

Let this be
Be the day
Day of my
My declaration
Let this be the day of my declaration

Join me,
Walk with me

Shatter the bonds that tie us
To what we strive to never be

Join me,
Walk with me
*/
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

const int maxn=1e8+1;



int lp[maxn];
vi prime;

int main(){
    int n=100000;
    cin>>n;
    memset(lp,0,sizeof(lp));
fore(i,2,n){
if(lp[i]==0){
    lp[i]=i;
    prime.pb(i);
}

for(int j=0;j<prime.size()&&i*prime[j]<n&&prime[j]<=lp[i];j++){
    lp[i*prime[j]]=prime[j];
}
}
for(auto it:prime) cout<<it<<" ";
return 0;
}
