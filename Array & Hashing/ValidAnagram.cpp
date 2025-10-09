#https://neetcode.io/problems/is-anagram?list=neetcode150

# Space Complexity : O(1)
# Time Complexity : O(n)

class Solution {
public:

    string removeSpaces(string str){
        str.erase(remove(str.begin(),str.end(),' '),str.end());
        return str;
    }

    bool isAnagram(string s, string t) {
        
        s = removeSpaces(s);
        t = removeSpaces(t);

        if(s.length() != t.length()){
            return false;
        }
        for(int i = 0; i<s.size(); i++){
            if(s[i]>='A' && s[i]<='Z')
            {
                s[i]+=32;
            }
            if(t[i]>='A' && t[i]<='Z')
            {
                t[i]+=32;
            }
        }
        int freq[26] = {0};
        for(int i = 0; i<s.size(); i++){
            freq[s[i]-97]++;
            freq[t[i]-97]--;
        }
        for(int i = 0; i<26; i++){
            if(freq[i]!=0){
                return false;
            }
        }
        return true;
    }
};
