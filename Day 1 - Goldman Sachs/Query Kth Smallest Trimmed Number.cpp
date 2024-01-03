class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            vector<pair<string,int>>tmp;         
            for(int j=0;j<nums.size();j++)   
                tmp.push_back({nums[j].substr(nums[j].length()-queries[i][1]),j});
                sort(tmp.begin(),tmp.end());
                ans.push_back(tmp[queries[i][0]-1].second);
        }
        return ans;
    }
};
