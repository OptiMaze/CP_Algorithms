
void update(ll node,ll l,ll r,ll idx){

  if(r<idx||l>idx) return ;
  if(l==r){
    seg[node].fi=idx;
    seg[node].se=idx;
    return ;
  }
  ll m=(l+r)/2;
  update(2*node,l,m,idx);
  update(2*node+1,m+1,r,idx);
  if(depthh[seg[2*node].fi]<depthh[seg[2*node+1].fi]){
    seg[node].fi=seg[2*node].fi;
  }
  else{
    seg[node].fi=seg[2*node+1].fi;
  }
  if(depthh[seg[2*node].se]<depthh[seg[2*node+1].se]){
    seg[node].se=seg[2*node+1].se;
  }
  else{
    seg[node].se=seg[2*node].se;
  }


}

ll query_MIN(ll node,ll l,ll r,ll ql,ll qr){  
  if(r<ql||l>qr){
    return 1e5+1;
  }
  if(r<=qr&&l>=ql){
    return seg[node].fi;
  }
  ll m=(l+r)/2;
  ll a=query_MIN(2*node,l,m,ql,qr);
  ll b=query_MIN(2*node+1,m+1,r,ql,qr);
  if(depthh[a]<depthh[b]) return a;
  else return b;
}


ll query_MAX(ll node,ll l,ll r,ll ql,ll qr){
  if(r<ql||l>qr){
    return 1e5+2;
  }
  if(r<=qr&&l>=ql){
    return seg[node].se;
  }
  ll m=(l+r)/2;
  ll a=query_MAX(2*node,l,m,ql,qr);
  ll b=query_MAX(2*node+1,m+1,r,ql,qr);
  if(depthh[a]<depthh[b]) return b;
  else{
    return a;
  }
}