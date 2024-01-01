class Solution {
public:
set<vector<int>> st;
void solve(int k,int n,vector<int> v,int idx)
{
    if(k==0&&n!=0)
    return;
    if(n==0&&k!=0)
    return;
    if(n==0&&k==0)
    {
        st.insert(v);
        return;
    }

    for(int i=idx+1;i<=9;i++)
    {
        if(i<=n)
        {
            v.push_back(i);
            solve(k-1,n-i,v,i);
            v.pop_back();
        }
        else
        break;
    }
}

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;


       if(n>45||n==0)
       return ans;


       
       for(int i=1;i<=9;i++)
       {
              vector<int> v;
              if(i<=n)
              {
                  v.push_back(i);
              solve(k-1,n-i,v,i);
              v.pop_back();
              }
              else
              break;

       }
       for(auto itr:st)
       ans.push_back(itr);


return ans;

        
    }
};

// This code aims to find combinations of integers from 1 to 9 that sum up to a 
// given value n, considering a specific count k of elements in each combination.
// The primary approach involves a recursive function solve to generate combinations meeting the criteria.

// Here's a breakdown of the code:

// solve function:
// Base Cases:

// Checks for different scenarios:
// If k reaches 0 and n is not 0: It means the required count of elements (k) has been 
// exhausted before reaching the target sum (n). Returns without processing further.
// If n reaches 0 and k is not 0: It means the target sum (n) has been reached before 
// achieving the required count of elements (k). Returns without processing further.
// If both n and k are 0: It means a valid combination is found. Adds the combination (v) 
// to the set st (ensuring uniqueness) and returns.
// Recursive Combinations:

// Iterates from idx+1 to 9 (inclusive) to explore different combinations.
// Checks if i is less than or equal to n to avoid exceeding the target sum.
// Adds i to the current combination (v), calls solve with decremented k and reduced n, 
//   and then removes i from the combination before exploring further combinations.
// combinationSum3 function:
// Initializes an empty set st to store unique combinations.
// Handles edge cases:
// If n is greater than 45 (sum of numbers from 1 to 9) or if n is 0, returns an empty answer.
// Generates combinations for each number from 1 to 9 using the solve function.
// Populates the answer vector ans with the combinations stored in the set st.
// Returning the Result:
// Returns the ans, which contains all unique combinations of size k that sum up to n using 
// integers from 1 to 9.
// This code employs a recursive approach to explore different combinations of integers
// within the given constraints and collects unique valid combinations to be returned as the final result.
