class Solution {
public:
    // time/space: O(nm + nlogn)/O(n)
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        // find the indices in the string `s` that contain string `a`/`b`
        vector<int> matchA, matchB;
        for (int i = 0; (i + a.size()) <= s.size(); i++) {
            if (s.substr(i, a.size()) == a) matchA.push_back(i);
        }
        for (int i = 0; (i + b.size()) <= s.size(); i++) {
            if (s.substr(i, b.size()) == b) matchB.push_back(i);
        }
        
        // find the index [i, j] meets the conditions using binary search
        vector<int> result;
        for (auto& i : matchA) {
            auto it = lower_bound(matchB.begin(), matchB.end(), i - k);
            if ((it != matchB.end()) && (abs(*it - i) <= k)) result.push_back(i);
        }
        return result;
    }
};
