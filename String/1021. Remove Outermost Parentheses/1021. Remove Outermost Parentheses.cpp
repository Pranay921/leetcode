// Problem: 1021. Remove Outermost Parentheses
// Runtime: 0 ms (Beats 100.00%)
// Memory: 8.9 MB (Beats 81.73%)

class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        string result="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                count++;
                if(count>1){
                    result+=s[i];
                }
            }
            else{
                count--;
                if(count!=0){
                    result+=s[i];
                }
            }
        }
        return result;
    }
};