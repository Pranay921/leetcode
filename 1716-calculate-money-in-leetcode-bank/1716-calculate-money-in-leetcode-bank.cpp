class Solution {
public:
    int totalMoney(int n) {
        int i=0,x=1,s=0;
        while(n>0){
            s+=x;
            i++;
            x++;
            if(i==7){
                i=0;
                x=x-6;
            }
            n--;
        }
        return s;
    }
};