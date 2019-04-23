    
    /* m is the size of pattern to be searched and n is size of the string */

    if(m>n){    
        cout<<0;
        return 0;
    }
    if(m==0){
        cout<<n+1;
        return 0;
    }
    int lps[m];
    memset(lps,0,sizeof(lps));
    lps[0]=0;
    int i=1;
    int len=0;
    while(i<m){                 // Creating LPS array 
        if(b[i]==b[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=lps[len-1];
            }
            else{
                i++;
            }
        }
    }

    int ans=0;          // ans is the number of substrings matched with the pattern
    i=0;
    int j=0;
    while(j<n){         // Search Begins ;)
        if(a[j]==b[i]){
            if(i==m-1){
                ans++;
                i=lps[i];
                j++;
            }
            else{
                i++;
                j++;
            }
            }      
            else{
                if(i!=0){
                    i=lps[i-1];
                }
                else{
                    j++;
                }
            }
        }
    
    cout<<ans;
