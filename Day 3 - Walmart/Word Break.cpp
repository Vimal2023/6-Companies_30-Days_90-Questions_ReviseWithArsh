class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();

        // Create a queue for BFS
        queue<int> q;
        q.push(0); // Start with index 0 of the input string

        // Create a vector to mark visited indices
        vector<bool> visited(n, false);
        visited[0] = true;

        while (!q.empty()) {
            int start = q.front();
            q.pop();

            // Explore all possible substrings starting from the current index
            for (int end = start + 1; end <= n; end++) {
                string word = s.substr(start, end - start);

                // If the current substring is present in the dictionary
                if (dict.find(word) != dict.end()) {
                    // If we reached the end of the string, return true
                    if (end == n)
                        return true;

                    // If the next index has not been visited, mark it as visited and add it to the queue
                    if (!visited[end]) {
                        q.push(end);
                        visited[end] = true;
                    }
                }
            }
        }

        // If we have explored all possibilities and did not reach the end, return false
        return false;
    }
};
