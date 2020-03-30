#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int dp[100][100];


int solve(int a[],int i,int j) {
    if(i==j) {
        dp[i][j]=0;
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=INT_MAX;
    for(int k=i;k<j;k++) {
        ans=min(ans,solve(a,i,k)+solve(a,k+1,j)+a[i-1]*a[k]*a[j]);
    }
    return dp[i][j]=ans;
}

int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	    cin>>a[i];
	memset(dp,-1,sizeof(dp));
	cout<<solve(a,1,n-1)<<endl;
}
