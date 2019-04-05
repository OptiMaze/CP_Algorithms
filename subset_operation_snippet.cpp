#include<bits/stdc++.h>
using namespace std;

void subsetSums(int arr[], int n)
{
    long long total = 1<<n;

    for (long long i=0; i<total; i++)
    {
        long long sum = 0;

        for (int j=0; j<n; j++)

            if (i & (1<<j))

                sum += arr[j];
            
            cout<<sum<<" ";
    }

}

int main(){
    int arr[3] = {1,2,3};
    subsetSums(arr,sizeof(arr)/sizeof(int));
    return 0;
}