int p[maxn],sz[maxn];

void init(int n){
    for(int i=0;i<=n;i++){
        p[i]=i;
        sz[i]=1;
    }
}
int root(int a){
    while(a!=par[a]){
        par[a]=par[par[a]];
        a=par[a];
    }
    return a;
}
void uni(int a,int b){
    a=find(a);
    b=find(b);
    if(b>a) swap(a,b);
    par[b]=a;
    sz[a]+=sz[b];
}
