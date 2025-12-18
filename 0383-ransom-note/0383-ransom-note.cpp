class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int,int> map;
        for(int i=0;i<magazine.length();i++){
            map[magazine[i]]++;
        }
        // int c=0;
        for(int i=0;i<ransomNote.length();i++){
            // if(map.find(ransomNote[i])!=map.end()){
                if(map[ransomNote[i]]--==0) return false;
                // c++;
                // map[ransomNote[i]]--;
            // }
        }
        // if(c==ransomNote.length()) return true;
        return true;
    }
};