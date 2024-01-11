/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    using int2=pair<int, int>;
    vector<int> adj[100001];
    void build_adj(TreeNode* root){
        if (!root) return;
        int x=root->val;
        if (root->left){
            int l=root->left->val;
            adj[x].push_back(l);
            adj[l].push_back(x);
            build_adj(root->left);
        }
        if (root->right){
            int r=root->right->val;
            adj[x].push_back(r);
            adj[r].push_back(x);
            build_adj(root->right);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        fill(adj, adj+100001, vector<int>());
        build_adj(root);
        bool viz[100001]={0};
        queue<int2> q;
        q.emplace(start, 0);
        viz[start]=1;
        int d=0;
        while(!q.empty()){
            auto [x, dd]=q.front();
            d=max(d, dd);
            q.pop();
            for(int y: adj[x]){
                if (viz[y]) continue;
                q.emplace(y, dd+1);
                viz[y]=1;
            }
        }
        return d;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
