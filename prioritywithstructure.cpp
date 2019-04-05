#include<bits/stdc++.h>
using namespace std;
struct ipc{
int d,l,s;
};

bool cmp(struct ipc a,struct ipc b){
return a.s<b.s;
}

bool cmp1(struct ipc a,struct ipc b){
return a.d<b.d;
}
int main(){
ios_base::sync_with_stdio(0);
cin.tie(NULL);
cout.tie(NULL);
int t;
cin>>t;
while(t--){
int n,D,i,j;
cin>>n>>D;
priority_queue <ipc,vector<ipc>,function <bool(ipc,ipc)> > q(cmp);
struct ipc a[n];
for(int i=0;i<n;i++){
    cin>>a[i].d>>a[i].l>>a[i].s;
}
sort(a,a+n,cmp1);
j=0;
for(i=a[0].d;i<=D;i++){

 while(a[j].d==i){
    q.push(a[j]);
    j++;
 }
if(q.empty())
    continue;
//q.top().l-=1;
struct ipc c;
c=q.top();
q.pop();
c.l-=1;
if(c.l)
q.push(c);
}
int ans=0;
while(!q.empty()){
        struct ipc d;
d=q.top();
q.pop();
    ans=ans+(d.l*d.s);
    //q.pop();
}
cout<<ans<<endl;
}
return 0;
}
