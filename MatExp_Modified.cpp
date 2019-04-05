const ll maxn=1000001,mod=1e9+7;


ll f[3][3]={{0,0,1},{1,0,1},{0,1,1}};
ll a,b,c;

void mul_t(ll a[3][3],ll b[3][3]){

ll mul[3][3];
    forn(i,3)
    {
        forn(j,3)
        {
            mul[i][j] = 0;
            forn(k,3)
            {
                ll temp=((a[i][k]%mod)*(b[k][j]%mod))%mod;
                mul[i][j] = ((mul[i][j]%mod)+(temp%mod))%mod;
            }
        }
    }
    forn(i,3)
        forn(j,3)
            a[i][j] = mul[i][j]%mod;

}

void mat_pow(ll n){

ll m[3][3]={{0,0,1},{1,0,1},{0,1,1}};

if(n==0||n==1) return ;

mat_pow(n/2);

mul_t(f,f);

if(n%2==1)

mul_t(f,m);

}


ll nthfibo(ll n){

 //ll f[3][3]={{0,0,1},{1,0,1},{0,1,1}};

 if(n==1) return a;
 if(n==2) return b;
 if(n==3) return c;

 mat_pow(n-3);

 return ((a*f[0][2])%mod+(b*f[1][2])%mod+(c*f[2][2])%mod)%mod;

}

int main(){

ll t;
cin>>t;

ll temp[3][3];
    forn(i,3) forn(j,3) temp[i][j]=f[i][j];

while(t--){

    ll n;
    cin>>n;
    forn(i,3) forn(j,3) f[i][j]=temp[i][j];
    a=2;
    b=4;
    c=7;
    cout<<nthfibo(n)<<endl;

}
return 0;
}
