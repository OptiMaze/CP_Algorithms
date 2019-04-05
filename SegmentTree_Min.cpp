int seg[4*maxn];

void u(int node,int idx,int l,int r){
    if(idx<l||idx>r) return ;
    if(l==r){
        seg[node]=ar[idx];
        return ;
    }
    int m=(l+r)/2;
    u(2*node+1,idx,l,(l+r)/2);
    u(2*node+2,idx,(l+r)/2+1,r);
    seg[node]=min(seg[2*node+1],seg[2*node+2]);
}

int q(int node,int l,int r,int ql,int qr){
    if(r<ql||l>qr) return INT_MAX;
    if(l>=ql&&r<=qr) return seg[node];
    return min(q(2*node+1,l,(l+r)/2,ql,qr),q(2*node+2,(l+r)/2+1,r,ql,qr));
}
