class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n % 2 != 0) return {};
        sort(changed.begin(),changed.end());
        vector<int> left;
        vector<int> right;

        for (int i = 0; i < n/2; i++)
            left.push_back(changed[i]);

        for (int i = n/2; i < n; i++)
            right.push_back(changed[i]);

        int leftCount = 0, rightCount = 0;

        for (int i = 0; i < n/2; i++) {
            if (find(right.begin(), right.end(), left[i] * 2) != right.end())
                leftCount++;

            if (find(left.begin(), left.end(), right[i] * 2) != left.end())
                rightCount++;
        }

        if (leftCount == left.size()) return left;
        if (rightCount == right.size()) return right;

        return {};
    }
};
