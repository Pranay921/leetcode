class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1=num1.size();
        int n2=num2.size();
        int i=n1-1,j=n2-1;
        int carry=0;
        string result;
        while(i>=0 || j>=0 || carry>0){
            int val1=0,val2=0;
            if(i>=0) val1=num1[i]-'0'; 
            if(j>=0) val2=num2[j]-'0';
            int sum=val1+val2+carry; 
            result=char((sum%10)+'0')+result;
            carry=sum/10;
            if(i>=0) i--;
            if(j>=0) j--;
        }
        return result;
    }
};