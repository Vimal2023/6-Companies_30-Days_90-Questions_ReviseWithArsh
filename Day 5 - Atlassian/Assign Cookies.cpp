class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
       
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int count = 0;
        int i = 0, j = 0;
        while (i < g.size() && j < s.size()) {
            
            if (g[i] <= s[j]) {
                count++;
                i++;
            }
            
            j++;
        }
        
        return count;
    }
};
