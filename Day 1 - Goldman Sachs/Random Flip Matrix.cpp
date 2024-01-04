class Solution {
private:
    int n;
    int total;
    int flipped;
    unordered_map<int, int> flipmap;

    inline vector<int> getIndex(int key) {
        return vector<int>({key/n, key%n});
    }

public:
    Solution(int m, int _n) {
        n = _n;
        total = m*n;
        flipped = 0;
        flipmap.clear();
    }
    
    vector<int> flip() {
        int k = rand() % (total - flipped) + flipped;

        int key = (flipmap.count(k) > 0) ? flipmap[k] : k;
        flipmap[k] = (flipmap.count(flipped) > 0) ? flipmap[flipped] : flipped;
        flipped++;

        return getIndex(key);
    }
    
    void reset() {
        flipmap.clear();
        flipped = 0;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
