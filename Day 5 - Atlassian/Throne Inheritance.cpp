class ThroneInheritance {
public:
    unordered_map<string, vector<string>> map;
    unordered_set<string> dead;
    string nameOfKing;
    
    ThroneInheritance(string kingName) {
        nameOfKing= kingName;
    }
    
    void birth(string par, string child) {
        map[par].push_back(child);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    
    void helper(string par, vector<string> &ans){
        if(dead.count(par)==0) ans.push_back(par);
        for(auto child:map[par]) helper(child, ans);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        helper(nameOfKing, ans);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
