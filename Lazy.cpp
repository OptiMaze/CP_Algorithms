const ll maxn=5*(1e5+1);
ll seg[maxn],lazy[maxn];

void propogate(int node,int curl,int curr){
    if(lazy[node]!=0){
        seg[node]+=(curr-curl+1)*lazy[node];
        if(curr!=curl){
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
}
void update(int node,int curl,int curr,int l,int r,ll val){
    propogate(node,curl,curr);
    if(curl>r||curr<l) return;
    if(curl>=l&&curr<=r){
        seg[node]+=(curr-curl+1)*val;
        if(curr!=curl){
            lazy[2*node]+=val;
            lazy[2*node+1]+=val;
        }
        return;
    }
    update(2*node,curl,(curl+curr)/2,l,r,val);
    update(2*node+1,(curl+curr)/2+1,curr,l,r,val);
    seg[node]=seg[2*node]+seg[2*node+1];
}

ll query(int node,int curl,int curr,int l,int r){
    propogate(node,curl,curr);
    if(curl>r||curr<l) return 0;
    if(curl>=l&&curr<=r) return seg[node];
    return query(2*node,curl,(curl+curr)/2,l,r)+query(2*node+1,(curl+curr)/2+1,curr,l,r);
}
