class Solution {
    public int compute(int [] cost,int index,int[] dp){
        if(index>=cost.length){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        dp[index]=cost[index]+Math.min(compute(cost,index+1,dp),compute(cost,index+2,dp));
        return dp[index];
    }
    public int minCostClimbingStairs(int[] cost) {
        int[] dp=new int[cost.length];
        Arrays.fill(dp,-1);
        return Math.min(compute(cost,0,dp),compute(cost,1,dp));
    }
}