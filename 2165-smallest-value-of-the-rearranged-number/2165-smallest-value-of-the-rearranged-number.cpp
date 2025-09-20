class Solution {
public:
    long long smallestNumber(long long num) {
        if(num==0) return 0;
        string str=to_string(num);
        sort(str.begin(),str.end());
        if(num>0){
            if(str[0]=='0'){
                int index=-1;
                for(int i=1;i<str.length();i++){
                    if(str[i]!='0'){
                        index=i;
                        break;
                    }
                }
                char temp=str[0];
                str[0]=str[index];
                str[index]=temp;
            }
        }
       else{
        str=str.substr(1);
        sort(str.begin(),str.end(),greater<char>());
        str='-'+str;
       }
        return stoll(str);
    }
};