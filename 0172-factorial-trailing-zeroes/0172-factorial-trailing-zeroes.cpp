class Solution {
public:
    int trailingZeroes(int n) {
        long long dem=5,s=0;
        while(dem<=n){
            int rem=n/dem;
            s=s+rem;
            dem*=5;
        }
        return s;
    }
};