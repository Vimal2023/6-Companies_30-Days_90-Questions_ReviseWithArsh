class Solution {
int dp[1001];
#define mod 1000000007
public:
    int solve(int idx,int d,int f,int n){
        if(idx+d>n)return 1;
        if(dp[idx]!=-1)return dp[idx];
        int ans=1;
        for(int i=idx+d;i <= min(n,idx+f);i++){
            if(i==idx+f){
                ans-=1;
                break;
            }
            ans= (ans%mod + solve(i,d,f,n)%mod)%mod;
        }
        return dp[idx]=ans;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        memset(dp,-1,sizeof(dp));
       return solve(1,delay,forget,n); 
    }
};
