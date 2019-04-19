//GCD,Minimum and Maximum in constant time.
//Sparse Tables

#include<bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<n;i++) 

const int maxn = 3*1e5+1, LOGN = 21;
int ar[maxn],n,Logn;
int sp_min[LOGN][maxn],sp_gcd[LOGN][maxn],Log[maxn];

int gl,gr;

int gcd(int a,int b){
    if(a<b) swap(a,b);
    if(b==0) return a;
    return gcd(a%b,b);
}

void cal_log(){
    Log[1]=0;
    for(int i=2;i<maxn;i++) Log[i]=Log[i/2]+1;
}

void sparse_min(){
    forn(i,n) sp_min[0][i]=ar[i];

    forn(i,Logn){
        if(i==0) continue;
        forn(j,n){
            if(j+(1<<(i-1))>=n) break;
            sp_min[i][j] = min(sp_min[i-1][j],sp_min[i-1][j+(1<<(i-1))]);
        }
    }
}

void sparse_gcd(){
    forn(i,n) sp_gcd[0][i]=ar[i];
    forn(i,Logn){
        if(i==0) continue;
        forn(j,n){
            if(j+(1<<(i-1))>=n) break;
            sp_gcd[i][j]=gcd(sp_gcd[i-1][j],sp_gcd[i-1][j+(1<<(i-1))]);
        }
    }
}

int q_min(int l,int r){
    int len = r-l+1;
    len = Log[len];
    return  min(sp_min[len][l],sp_min[len][r-(1<<len)+1]);
}

int q_gcd(int l,int r){
    int len = r-l+1;
    len = Log[len];
    return gcd(sp_gcd[len][l],sp_gcd[len][r-(1<<len)+1]);
}   

int main(){

    cin>>n;
    forn(i,n) cin>>ar[i];
    Logn = log2(n)+1;
    cal_log();
    sparse_min();
    sparse_gcd();
    

    return 0;

}