const int manx=1000001;
int n;

int BIT[maxn];

void init(int n){
    forn(i,n+1)
    BIT[i]=0;
}
void upd(int idx,int val){
while(idx<=n){
    BIT[idx]+=val;
    idx+=(idx&-idx);
}
}

int query(int idx){
int sum=0;
while(idx>0){
    sum+=BIT[idx];
    idx-=(idx&-idx);
}
return sum;
}

