ll fast_pow(ll n,ll exp){

if(exp==0) return 1;
if(exp==1) return n%mod;
ll temp=fast_pow(n,exp/2);
temp=(temp*temp)%mod;
if(exp%2==1)
temp=(temp*n)%mod;
return temp;

}

