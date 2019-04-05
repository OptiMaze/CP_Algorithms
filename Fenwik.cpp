
#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for(i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define f first
#define s second
using namespace std;


ll query(ll idx,ll BIT[]){
ll s=0;
ll i;
while(idx>0){

    s+=BIT[idx];
    idx-=(idx&(-idx));

}

return s;
}

void update(ll idx,ll BIT[],ll n){

while(idx<=n){
    BIT[idx]+=1;
    idx+=(idx&(-idx));
}

}
//cout<<query(3,BIT)<<endl
int main(){

ll t;
cin>>t;
while(t--){

    ll n;
    cin>>n;
    ll i;
    vector <pair<ll,ll> > v;
    ll x;
    rep(i,n){
    cin>>x;
    v.pb(mp(x,i+1));
    }
    sort(v.begin(),v.end());
    ll a[n+1];
    ll ct=1;
    for(auto it:v){
        a[it.s]=ct;
        ct++;
    }
    ll BIT[n+1];
    rep(i,n+1)
    BIT[i]=0;
    ll idx;
    ll ans=0;
   // cout<<"yes"<<endl;
    for(i=n;i>0;i--){
         //   cout<<a[i]<<endl;
        idx=a[i];
        ans+=query(idx,BIT);
        update(idx,BIT,n);
    }
   // cout<<query(3,BIT);
  //  for(i=0;i<=n;i++){
    //    cout<<BIT[i]<<endl;
    //}
    cout<<ans<<endl;
}
return 0;
}
