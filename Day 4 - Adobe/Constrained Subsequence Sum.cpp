
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        //maxTillThis will represent the max sum of sub seq ending at a particular index 
        vector<int> maxTillThis = nums;//account for sub seq of size one i.e. the element itself
        //used to form a slding window which will in decreasing order
        deque<int> maxSbSqUptSzK;
        int res = maxTillThis[0];
        for (int indx = 0; indx < maxTillThis.size(); ++indx) {

            //from all subseq ending at this index what is maximum sum
            maxTillThis[indx] += maxSbSqUptSzK.size() ? maxTillThis[maxSbSqUptSzK.front()] : 0;
            
            //along that will we updating our final result
            res = max(res, maxTillThis[indx]);
            
            //remove all the sub seq sums that are lesser than current one
            while (maxSbSqUptSzK.size() && maxTillThis[indx] > maxTillThis[maxSbSqUptSzK.back()])
                maxSbSqUptSzK.pop_back();
            
            //current sub seq sum ending at 'indx' is non zero
            if (maxTillThis[indx] > 0)
                maxSbSqUptSzK.push_back(indx);
            //remove all the sub seq sums to which current element cannot make contributions to    
            if (indx >= k && maxSbSqUptSzK.size() && maxSbSqUptSzK.front() == indx - k)
                maxSbSqUptSzK.pop_front();
        
        }
        //returning maximum sum of valid sub seq
        return res;
    }
};
