class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dictSet;
        int sz = s.size();
        for(auto word : dictionary){
            dictSet.insert(word);
        }
        vector<int> delCount(sz+1);
        for(int right = 1; right<=sz; right++){
                delCount[right] = 1 + delCount[right-1];
                for(int left = right; left > 0; left--){
                    string word = s.substr(left-1, right - left+1);
                    if(dictSet.count(word)){
                        delCount[right] = min(delCount[right], delCount[left-1]);
                    }
                }
        }
        return delCount[sz];
    }
};
