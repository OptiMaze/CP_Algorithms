#include<bits/stdc++.h>
using namespace std;


int main(){

	string s;
	cin>>s;
	int n;
	n=s.size();
	int lps[n];
	memset(lps,0,sizeof(lps));

	int i=1;
	int len=0;
	while(i<n){
		if(s[i]==s[len]){
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
				len=0;
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<lps[i]<<" ";
	}

	return 0;
}