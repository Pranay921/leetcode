class Solution {
    public int maxArea(int[] arr) {
        int n=arr.length;
        int left=0;
        int right=n-1;
        int maxwater=Integer.MIN_VALUE;
        while(left<right){
            int height=Math.min(arr[left],arr[right]);
            int width=right-left;
            int watertrapped=height*width;
            maxwater=Math.max(watertrapped,maxwater);
            if(arr[left]<arr[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxwater;
    }
}