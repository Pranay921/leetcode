class Solution {
public:
    int hammingDistance(int x, int y) {
        int xo=x^y;
        int count=0;
        while(xo>0){
            count+=(xo&1);
            xo=xo>>1;
        }
        return count;
    }
};