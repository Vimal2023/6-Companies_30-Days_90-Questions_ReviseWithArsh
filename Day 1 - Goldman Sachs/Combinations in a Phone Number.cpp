class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> ans;
        pad("", digits, ans);
        return ans;
    }

    vector<string> pad(string p, string str, vector<string>& ans) {
        if(str.empty()) {
            ans.push_back(p);
            return ans;
        }
        int digit = str[0] - '0';
        if(digit < 7) {
            for(int i=(digit - 2)*3;i<(digit - 1)*3;i++) {
                char ch = 'a' + i;
                pad(p + ch, str.substr(1), ans);
            }
        }
        else if(digit == 7) {
                for(int i=(digit - 2)*3;i<=(digit - 1)*3;i++) {
                    char ch = 'a' + i;
                    pad(p + ch, str.substr(1), ans);
            }
        }
        else if(digit == 8) {
                for(int i=(digit - 2)*3 + 1;i<=(digit - 1)*3;i++) {
                    char ch = 'a' + i;
                    pad(p + ch, str.substr(1), ans);
            }
        }
        else if(digit == 9) {
                for(int i=22;i<=25;i++) {
                    char ch = 'a' + i;
                    pad(p + ch, str.substr(1), ans);
            }
        }
        return ans;
    }
};


// This code is an implementation of a recursive approach to generate letter 
// combinations corresponding to a given sequence of digits, similar to a phone keypad.
// Here's a breakdown of the code:

// letterCombinations function:
// Takes in a string of digits.
// If the input string is empty, returns an empty vector.
// Initializes an empty vector ans to store generated combinations.
// Calls the pad function to generate combinations, passing an empty string "", 
// the input digits, and the ans vector.
// Returns the ans vector containing all the generated combinations.
// pad function:
// Takes in three parameters: p (partial combination), str (remaining digits), and a reference to the vector ans.

// Base Case:

// If str (remaining digits) becomes empty, it means a valid combination is formed.
// Adds the current combination p to the ans vector and returns.
// Recursive Case:

// Extracts the first digit from the input str.
// Checks the digit and generates corresponding letter combinations based on the digit's
// value.
// Iterates through different letters corresponding to the digit by calculating the range
// of characters on the phone keypad associated with that digit.
// For each character, calls the pad function recursively, passing the updated combination
// p + ch, the remaining digits (str.substr(1)), and the ans vector.
// Process Explanation:
// For each digit in the input digits, the pad function generates combinations by iterating
// through the letters associated with that digit on a standard phone keypad.
// It builds combinations recursively by appending each character associated with the digit
// to the partial combination (p) and continues this process until it forms combinations for all digits in the input string.
// Returning the Result:
// The letterCombinations function returns the ans vector containing all the generated letter
// combinations for the given sequence of digits.
// This code uses recursion to systematically explore and construct combinations of letters 
// based on the digits provided, following the pattern of a standard phone keypad.
