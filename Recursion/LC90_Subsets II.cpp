class Solution {
public:
    void getAllSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allsubsets) {
        if (i == nums.size()) {
            allsubsets.push_back(ans);
            return;
        }

        // Include
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i + 1, allsubsets);
        ans.pop_back(); // Backtracking

        // Exclude
        int idx = i + 1;
        while (idx < nums.size() && nums[idx] == nums[idx - 1]) {
            idx++;
        }
        getAllSubsets(nums, ans, idx, allsubsets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // O(n log n)
        vector<vector<int>> allSubsets;
        vector<int> ans;
        getAllSubsets(nums, ans, 0, allSubsets);
        return allSubsets;
    }
};
