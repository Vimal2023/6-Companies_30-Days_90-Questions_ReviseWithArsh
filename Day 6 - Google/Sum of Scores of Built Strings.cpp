class Solution {

public:
    long long sumScores(string s) {

        // pattern detection
        int start {0};
        int end {0};
        int patternScore = 0;
        int prepeat = 0;

        long long total = 0;
        for (int i = 1; i < s.size(); i++) {
            int score {0};
            int j = i; 
            for (auto a : s) {
                if (a == s[j]) {
                    score++;
                    j++;
                } else {
                    break;
                }
            }
            // If pattern is detected, then extrapolate it, compute it's resulting score,
            // continue from where the pattern ends. 
            if (start > 0 && end > 0 && i < end && j-1 == end ) {
                prepeat = i - start;
                long long newScore = 0;
                auto patternValue = sumScores(s.substr(0, prepeat)) - prepeat;
                for (int x = i; x < j; x+=prepeat) {
                    newScore += j-x;
                    if (patternValue< prepeat) {
                        newScore += patternValue;
                    }
                }
                
                total += (long long) newScore;
                i = end;
                continue;
            
            }
            total += (long long)score;
            if (score > patternScore) {
                start = i;
                end = j-1;
                patternScore = score;
            }
        }
        return total + (long long)s.size();
    }
};
