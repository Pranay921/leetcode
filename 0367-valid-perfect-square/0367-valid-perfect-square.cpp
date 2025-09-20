class Solution {
public:
    bool isPerfectSquare(int n) {
          long long low=0,high=n;
        while(low<=high){
            long long mid=(low+high)/2;
            long long sqmid=mid*mid;
            if(sqmid==n) return true;
            else if(n<sqmid){
                high=mid-1;
            }
            else if(n>sqmid){
                low=mid+1;
            }
        }
        return false;
    }
};
