// Read at the below, how this code is running

class Solution {
public:
    bool check(int mid,int div1,int div2,int cnt1,int cnt2)
    {
        int a=mid-mid/div1;
        int b=mid-mid/div2;
        int c=mid/((1LL * div1*div2)/(1LL*__gcd(div1,div2)));
        if(a<cnt1 || b<cnt2 || (mid-c)<(cnt1+cnt2))
        return false;
        return true;
    }
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        int low=0;
        int high=INT_MAX;
        int ans=0;
        while(low<=high)
        {
            int mid=(1LL * low+ 1LL * high)/2;
            if(check(mid,divisor1,divisor2,uniqueCnt1,uniqueCnt2))
            {
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};


// check function:
// The check function evaluates whether it's possible to construct arrays arr1 and arr2 that satisfy the conditions with a given mid value.
// It calculates three variables: a, b, and c.
// a: Represents the count of numbers not divisible by divisor1 in the range [1, mid].
// b: Represents the count of numbers not divisible by divisor2 in the range [1, mid].
// c: Represents the count of numbers not divisible by both divisor1 and divisor2 in the range [1, mid].
// It checks whether there are enough numbers not divisible by divisor1, divisor2, and both divisors combined to fill arr1 and arr2.
// minimizeSet function:
// Initializes low to 0 and high to INT_MAX (maximum integer value).
// Enters a while loop that continues until low is less than or equal to high.
// Calculates the mid value as the average of low and high.
// Calls the check function to verify if it's possible to construct arrays that satisfy the conditions with the current mid value.
// If possible (check returns true), updates the ans (potential answer) to the current mid and narrows the search space by updating high to mid - 1.
// If not possible, shifts the search space by updating low to mid + 1.
// Returning the Result:
// Once the while loop ends (low > high), returns the ans, which represents the minimum possible maximum integer that satisfies the conditions for arrays arr1 and arr2.
// This code employs a binary search strategy to find the minimum possible maximum integer that can be present in either array, ensuring that the conditions regarding divisibility 
// and count of elements for both arrays are met simultaneously by utilizing the check function.
