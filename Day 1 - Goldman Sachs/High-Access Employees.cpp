class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& nums) {
        sort(nums.begin(),nums.end());
        vector<string> ans;
        for(int i=0;i<nums.size();i++){
            int cnt=1;
            int j = i+1;
            if(!ans.empty()){
                if(ans[ans.size()-1]==nums[i][0]){
                    continue;
                }
            }
            while(j<nums.size() && nums[i][0]==nums[j][0]){
                int t1= stoi(nums[i][1]);
                int t2 = stoi(nums[j][1]);
                int time = t2-t1;
                if(time<100){
                    cnt++;
                }
                else{
                    break;
                }
                j++;
            }
            if(cnt>2){
                ans.push_back(nums[i][0]);
            }
        }
        return ans;
    }
};
