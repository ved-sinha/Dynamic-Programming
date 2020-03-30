#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int solve(int a[],int n) {
    
    vector<int> dp(100,1);
    int best=-1;
    
    for(int i=1;i<n;i++) {
        for(int j=0;j<i;j++) {
            if(a[j]<=a[i])
                dp[i]=max(dp[i],dp[j]+1);
        }
        best=max(best,dp[i]);
    }
    
    return best;
}

int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) 
	    cin>>a[i];
	cout<<solve(a,n)<<endl;
}
