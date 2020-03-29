#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int minCoin(int N,int coins[],int T,int dp[]) {
    if(N==0) return 0;
    if(dp[N]!=0) return dp[N];
    int res=INT_MAX;
    for(int i=0;i<T;i++) {
        if(N-coins[i]>=0) {
            int subprob=minCoin(N-coins[i],coins,T,dp);
            res=min(res,subprob+1);
        }
    }
    return dp[N]=res;
}

int minCoinBottomUp(int N,int coins[],int T) {
    int dp[N+1]={0};
    for(int i=1;i<=N;i++) {
        dp[i]=INT_MAX;
        for(int j=0;j<T;j++) {
            if(i-coins[j]>=0) {
                dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }
    }
    return dp[N];
}

int main() {
	int N=15;
	int coins[]={1,7,10};
	int dp[100]={0};
	int T=sizeof(coins)/sizeof(int);
	cout<<minCoin(N,coins,T,dp);
	cout<<endl;
	cout<<minCoinBottomUp(N,coins,T);
}
