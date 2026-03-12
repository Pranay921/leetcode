class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()==1) return "0";
        stack<char> s;
        for(int i=0;i<num.size();i++){
            while(k>=0 && !s.empty() && s.top()>num[i]){
                if(k<=0) break;
                k--;
                s.pop();

            }
            s.push(num[i]);
        }
        while(k>0 && !s.empty()){
            s.pop();
            k--;
        }// yeh wala look tabh maanlo 112 iss case mein koi bhi digit pop hoga hi nahi upare wale for loop ke hisab se toh issliye yeh bhi ek extra check
        string result="";
        while(!s.empty()){
            result+=s.top();
            s.pop();
        }
        reverse(result.begin(),result.end());
        bool numberFound=false;
        int index=0;
        for(int i=0;i<result.size();i++){
            if(result[i]!='0') {
                numberFound=true;
            }
            else if(result[i]=='0' && numberFound!=true){
                index++;
            }
        }
        result=result.substr(index);
        if(result=="") return "0";
        return result;
    }   
};