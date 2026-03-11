class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size() % 2 != 0) return {};
        sort(changed.begin(),changed.end());
        unordered_map<int,int> mp;
        for(int i=0;i<changed.size();i++){
            mp[changed[i]]++;
        }
        bool check=false;
        vector<int> result;
        for(int i=0;i<changed.size();i++){
            int sq=changed[i]*2;
            if(mp[changed[i]]==0) continue;//we lets say 1,2,3,4,6,8 for 1 2 is its square and afterwards we decrement bot of them so in map 1 and 2 both becomes 0 so when i comes to 2 we dont need to find the square of 2 because 2 has already been assigned as a sqare value of 1 so that's why skip the element 
            if(!mp.count(sq) || mp.count(sq)==0){
                return {};
            }
            result.push_back(changed[i]);
            mp[sq]--;
            mp[changed[i]]--;
        }
        return result;
    }
};