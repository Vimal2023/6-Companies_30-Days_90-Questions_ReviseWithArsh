class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
       sort(ages.begin(),ages.end());
        int count =0;
        for(int i=0;i<ages.size();i++)
        {
             int val=ages[i]/2+7;
            if(ages[i]<=val) //invalid condition
                continue;
            
            int ind1=upper_bound(ages.begin(),ages.end(),val)-ages.begin();
            int ind2=upper_bound(ages.begin(),ages.end(),ages[i])-ages.begin();
            
            ind2--;         //because upper bound will give val greater than ages[i] soo we need to decrement ind2 to get 
            if(ind2>=ind1)    // val<=ages[i]
                count+=ind2-ind1;
            
         }
        
        return count;
    }
};
