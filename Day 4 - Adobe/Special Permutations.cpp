
const int MOD = 1e9 + 7;
class Solution {
public:
    // Recursive function to calculate the number of special permutations
    int calperm(const vector<int>& nums, int prev, int index, int mask, vector<vector<int>>& dp) {
        // Base case: all elements have been placed in the permutation
        if (index == nums.size()) {
            return 1;
        }
        // Check if the result for the current state has already been computed
        if (dp[prev + 1][mask] != -1) {
            return dp[prev + 1][mask];
        }
        int total = 0;
        // Try adding each remaining element to the permutation
        for (int i = 0; i < nums.size(); ++i) {
            // Skip if the element has already been included
            if (!(mask & (1 << i)) && (prev == -1 || nums[i] % nums[prev] == 0 || nums[prev] % nums[i] == 0)) {
                // Recursive call to calculate the number of special permutations with the current element included
                total = (total + calperm(nums, i, index + 1, mask | (1 << i), dp)) % MOD;
            }
        }
        // Store the computed result in the dp table for memoization
        dp[prev + 1][mask] = total;
        return total;
    }

    // Main function to calculate the total number of special permutations
    int specialPerm(const vector<int>& nums) {
        // Create a 2D dp table to store the intermediate results
        vector<vector<int>> dp(nums.size() + 1, vector<int>((1 << nums.size()), -1));
        // Call the solve function with initial state (prev = -1, index = 0, mask = 0)
        return calperm(nums, -1, 0, 0, dp);
    }
};
