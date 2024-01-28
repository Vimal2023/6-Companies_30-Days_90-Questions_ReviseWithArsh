class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        return a[0]>b[0];
    }
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int i,n = aliceValues.size(),sum = 0;
        vector<vector<int>> temp;
        for(i = 0; i < n; i++){
            sum = aliceValues[i]+bobValues[i];
            temp.push_back({sum,i});
        }
        int sum1 = 0,sum2 = 0;
        sort(temp.begin(),temp.end(),cmp);
        // for(auto &i: temp){
        //     cout<<i[0]<<" "<<i[1]<<endl;
        // }
        int x = 1;
        for(auto &i: temp){
            if(x){
                sum1+=aliceValues[i[1]];
            }else{
                sum2+=bobValues[i[1]];
            }
            x ^= 1;
        }
        // cout<<endl;
        // cout<<sum1<<" "<<sum2;
        if(sum1==sum2){
            return 0;
        }else if(sum1>sum2){
            return 1;
        }return -1;
    }
};
