
pair<int,int> seg[4*maxn];

void upd(int node,int l,int r,int idx){
    if(idx<l||idx>r) return ;
    if(l==r){
        seg[node].fi=idx;
        seg[node].se=idx;
        return ;
    }
    upd(2*node,l,(l+r)/2,idx);
    upd(2*node+1,(l+r)/2+1,r,idx);
    if(a[seg[2*node].fi]>a[seg[2*node+1].fi]) seg[node].fi=seg[2*node].fi;
    else seg[node].fi=seg[2*node+1].fi;

    if(a[seg[2*node].se]>a[seg[2*node+1].se]) seg[node].se=seg[2*node+1].se;
    else seg[node].se=seg[2*node].se;
}
pair<int,int> query(int node,int l,int r,int cl,int cr){
    if(r<cl||l>cr) return make_pair(1e6-2,1e6-1);
    if(l>=cl&&r<=cr) return seg[node];
    pair<int,int> lul = query(2*node,l,(l+r)/2,cl,cr);
    pair<int,int> lol = query(2*node+1,(l+r)/2+1,r,cl,cr);
    int ar,br;
    if(a[lul.fi]>a[lol.fi]) ar=lul.fi;
    else ar=lol.fi;
    if(a[lul.se]<a[lol.se]) br=lul.se;
    else br=lol.se;
    return make_pair(ar,br);
}
