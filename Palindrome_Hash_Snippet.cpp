
const ll maxn=1000001,mod=1e9+7,p=31;

ll pw[maxn],pre[maxn],su[maxn],n;

void power(ll n){
pw[0]=1;
fore(i,1,n) pw[i]=(pw[i-1]*p)%mod;
}

void c_pre(string s){
forn(i,n){
if(i==0) pre[i]=((s[i]-'a')*pw[i])%mod;
else pre[i]=(pre[i-1]+((s[i]-'a')*pw[i])%mod)%mod;
}
}

void c_suf(string s){
forn(i,n){
if(i==0) su[n-1-i]=((s[i]-'a')*pw[i])%mod;
else{
    su[n-1-i]=(su[n-i]+((s[i]-'a')*pw[i])%mod)%mod;
}
}
}

bool check(ll l,ll h){

ll h1=pre[h];
if(l!=0) h1-=pre[l-1];
if(h1<0) h1+=mod;
ll h2=su[l];
if(h!=n-1) h2-=su[h+1];
if(h2<0) h2+=mod;

h1=(h1*pw[n-1-h])%mod;
h2=(h2*pw[l])%mod;

if(h1==h2) return true;
return false;

}
