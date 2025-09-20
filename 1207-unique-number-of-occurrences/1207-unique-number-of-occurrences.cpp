class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int ,int > map;
        for(int i=0;i<arr.size();i++){
            map[arr[i]]++;
        }
        unordered_set<int> set;
        for(auto i:map){
            if(set.contains(i.second)) return false;
            else{
                set.insert(i.second);
            }
        }
        return true;
    }
};