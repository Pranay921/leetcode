class Solution {
    public int jump(int[] nums) {
        int []dp=new int[nums.length];
        Arrays.fill(dp,-1);
        int sum=0,minSum=0;
        dp[nums.length-1]=0;
        for(int i=nums.length-2;i>=0;i--){
            for(int jump=1;jump<=nums[i] && i+jump<nums.length;jump++){
                if(dp[i+jump]!=-1){
                     if (dp[i]==-1)
                        dp[i]=dp[i + jump] + 1;
                    else
                        dp[i]=Math.min(dp[i], dp[i + jump] + 1);
                }
            }
        }
        return dp[0];
    }
}