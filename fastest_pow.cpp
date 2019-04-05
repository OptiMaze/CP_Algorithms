ll multiply(ll aax,ll bby){
    ll r=0LL;
    aax%=mod2;
    while(bby>0){
    	if(bby&1LL==1LL)
    		r=(r+aax)%mod2;
    	aax=(aax+aax)%mod2;
    	bby=bby>>1;
    }
    return r;
}
ll fast_pow(ll aax,ll n){
    ll r=1LL;
    aax%=mod2;
    while(n>0){
    	if(n&1LL==1LL)
    		r=multiply(r,aax);
    	aax=multiply(aax,aax);
    	n=n>>1;
    }
    return r;
}
