class Solution {
public:
    void floydWarshall(vector<vector<int>>&g){ // adjust for list form
        int n=g.size();
        for(int k=0;k<n;++k){
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    if(g[i][k]<INT_MAX && g[k][j]<INT_MAX){
                        g[i][j]=min(g[i][j], g[i][k]+g[k][j]);
                    }
                }
            }
        }
    }
    long long minimumCost(string src, string tar, vector<char>&from, vector<char>&to, vector<int>& cost) {
        int n=src.size(), m=cost.size();
        vector<vector<int>>g(26, vector<int>(26, INT_MAX));
        for(int i=0; i<m; ++i){
            int x = from[i]-'a', y=to[i]-'a';
            g[x][y] = min(g[x][y], cost[i]);
        }
        floydWarshall(g);
        long long ans=0;
        for(int i=0; i<n; ++i){
            int x = src[i]-'a', y = tar[i]-'a';
            if(x==y) continue;
            if(g[x][y]==INT_MAX) return -1;
            ans+=g[x][y];
        }
        return ans;
    }
};
