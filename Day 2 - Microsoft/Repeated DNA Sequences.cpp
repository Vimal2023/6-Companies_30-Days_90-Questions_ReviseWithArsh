class Solution {
public:
vector<string> findRepeatedDnaSequences(string s) {
        vector<string> l;
        long long hash=0;
        int n=s.size();
        int inp[n];
        unordered_map<long long,int> m;
        if(n<10) return l;
        for(int i=0;i<n;i++){
            if(s[i]=='A') inp[i]=1;
            else if(s[i]=='C') inp[i]=2;
            else if(s[i]=='G') inp[i]=3;
            else inp[i]=4;
        }
        for(int i=0;i<10;i++){
            hash=hash*4+inp[i];
        }
        m[hash]++;
        for(int i=1;i<n-9;i++){
            hash=hash*4-inp[i-1]*pow(4,10)+inp[i+9];
            m[hash]++;
            if(m[hash]==2) l.push_back(s.substr(i,10));

        }
        return l;
      }

};
