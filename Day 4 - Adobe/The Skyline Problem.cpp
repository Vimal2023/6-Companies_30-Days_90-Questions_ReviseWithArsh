class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& ar) {
        vector<pair<int,int>> v;
        for(auto it:ar){
            int l=it[0],r=it[1],h=it[2];
            v.emplace_back(l,-h);
            v.emplace_back(r,h);
        }
        sort(v.begin(),v.end());
        multiset<int> s;
        vector<vector<int>> ans;
        for(auto it:v){
            if(it.second<0){
                s.insert(it.second);
                ans.push_back({it.first,-(*s.begin())});
            }
            else{
                s.erase(s.find(-it.second));
                if(s.size()==0){
                    ans.push_back({it.first,0});
                }
                else{
                    ans.push_back({it.first,-(*s.begin())});
                }
            }
        }
        vector<vector<int>> anss;
        int n=ans.size();
        for(int i=0;i<n;i++){
            if(i && ans[i][1] == ans[i-1][1]){continue;}
            anss.push_back(ans[i]);
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
        }
        return anss;
    }
};
