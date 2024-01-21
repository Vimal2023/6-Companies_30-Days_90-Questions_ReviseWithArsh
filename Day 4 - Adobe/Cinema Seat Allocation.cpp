class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,bool> mp_left;
        unordered_map<int,bool> mp_right;
        unordered_map<int,bool> mp_middle;
        int ans=2*n;
        for(auto it:reservedSeats){
        if(it[1]==2 || it[1]==3 || it[1]==4 || it[1]==5){
                if(!mp_left[it[0]]){
                    mp_left[it[0]]=true;
                    ans-=1;
                }
            }
        if(it[1]==6 || it[1]==7 || it[1]==8 || it[1]==9){
            if(!mp_right[it[0]]){
                mp_right[it[0]]=true;
                ans-=1;
            }
        }
        if(it[1]==4 || it[1]==5 || it[1]==6 || it[1]==7){
            mp_middle[it[0]]=true;
        }
        }
        for(auto it:reservedSeats){
            if(!mp_middle[it[0]] && mp_right[it[0]] && mp_left[it[0]]){
                mp_middle[it[0]]=true;
                ans+=1;
            }
        }
        return ans;


    }
};
