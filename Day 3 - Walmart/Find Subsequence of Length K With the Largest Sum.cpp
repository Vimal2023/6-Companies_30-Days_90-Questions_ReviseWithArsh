class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(pq.size()<k) pq.push({nums[i],i});
            else if(pq.size()==k && pq.top().first<nums[i]){
                pq.pop();
                pq.push({nums[i],i});
            } 
        }
        vector<pair<int,int>> vec;
        while(pq.size()>0){
            int val=pq.top().first, idx=pq.top().second;
            pq.pop();
            vec.push_back({idx,val});
        }
        sort(vec.begin(),vec.end());
        vector<int> ans;
        for(int i=0;i<k;i++) ans.push_back(vec[i].second);
        return ans;
    }

};
