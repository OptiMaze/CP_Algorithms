const ll maxn=1000001;

ll n;

ll BIT[maxn];

void init(ll n){
    forn(i,n+1)
    BIT[i]=0;
}

void upd(ll idx,ll val){
while(idx<=n){
    BIT[idx]=max(BIT[idx],val);
    idx+=(idx&-idx);
}
}

ll query(ll idx){
ll ret=0;
while(idx>0){
    ret=max(ret,BIT[idx]);
    idx-=(idx&-idx);
}
return ret;
}


