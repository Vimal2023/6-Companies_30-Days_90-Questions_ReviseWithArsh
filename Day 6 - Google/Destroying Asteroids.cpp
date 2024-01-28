class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        long mass_new = mass;
            
        sort(asteroids.begin(),asteroids.end());
        
        for(int j = 0; j < n; j++){
            if(asteroids[j] <= mass_new)
                mass_new +=  asteroids[j];
            else
                return false;
                
        }
        return true;
        
        
    }
};
