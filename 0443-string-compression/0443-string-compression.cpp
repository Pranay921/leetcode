class Solution {
public:
    int compress(vector<char>& chars) {
       int n=chars.size();
       int idx=0;
       for(int i=0;i<n;i++){
            char currChar=chars[i];
            int c=0;
            while(i<n && chars[i]==currChar){
                c++;
                i++;
            }
            chars[idx++]=currChar;
            if(c>1){
                string counter=to_string(c);
                for(char str:counter){
                    chars[idx++]=str;
                }
            }
            i--;
       }
       return idx;
    }
};
