class Solution {
public:
    int compute(int n,vector<int> &dp){
        if(n==0) return 0;
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=compute(n-1,dp)+compute(n-2,dp);
    }
    int fib(int n) {
      vector<int> dp(n+1,-1);
      return compute(n,dp);
    }
};