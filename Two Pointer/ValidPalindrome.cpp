// https://neetcode.io/problems/is-palindrome?list=neetcode150

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    char toLowerCase(char ch) {
        // Check if character is uppercase (A–Z)
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + ('a' - 'A'); // convert to lowercase
        }
        // else leave it unchanged (for lowercase or non-alphabetic)
        return ch;
    }
    bool isPalindrome(string s) {

        int st = 0, en = s.size() - 1;
        while(st < en){
            if(!(s[st]>=48 && s[st]<=57) && !(s[st]>=65 && s[st]<=90) && !(s[st]>=97 && s[st]<=122))
            {
                st++;
                continue;
            }
            if(!(s[en]>=48 && s[en]<=57) && !(s[en]>=65 && s[en]<=90) && !(s[en]>=97 && s[en]<=122)){
                en--;
                continue;
            }
            if(toLowerCase(s[st]) != toLowerCase(s[en])){
                return false;
            }
            st++;
            en--;
        }
        return true;
        
    }
};
