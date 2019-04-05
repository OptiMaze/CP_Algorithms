ld tsearch(ld l,ld r){
    int itr=100;
    while(itr--){
        ld l1=l+(r-l)/3;
        ld r1=r-(r-l)/3;
        if(f(l1)<f(r1))
            r=r1;
        else
            l=l1;
    }
    return l;
}
