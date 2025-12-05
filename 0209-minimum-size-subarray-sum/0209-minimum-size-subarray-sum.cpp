class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        int minL=n;
        int sum=0,sum1=0;
        for(int i=0;i<n;i++){
            sum1+=nums[i];
        }
        if(sum1<target) return 0;
        while(j<n){
            sum+=nums[j];
            //window ko chota kar rahe hain 
            while(sum>=target){
                minL=min(minL,j-i+1);
                sum-=nums[i];
                i++;
            }
            j++;
        }  
        return minL;        
    }
};