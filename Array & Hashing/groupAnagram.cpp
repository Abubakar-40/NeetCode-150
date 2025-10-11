//https://neetcode.io/problems/anagram-groups?list=neetcode150

// Approach # 1(Bruite Force)
// Time complexity: O(m^2 * n)
// Space Complexity: O(m * n)

class Solution {
public:
    string removeSpaces(string str){
        str.erase(remove(str.begin(),str.end(),' '),str.end());
        return str;
    }
    bool isAnagram(string s, string t){
        s = removeSpaces(s);
        t = removeSpaces(t);
        if(s.length()!=t.length()){
            return false;
        }
        for(int i = 0; i<s.length(); i++){
            if(s[i]>='A' && s[i]<='Z'){
                s[i]+=32;
            }
            if(t[i]>='A' && t[i]<='Z'){
                t[i]+=32;
            }
        }
        int count[26] = {0};
        for(int i = 0; i<s.length(); i++){
            count[s[i]-97]++;
            count[t[i]-97]--;   
        }
        for(int i = 0; i<26; i++){
            if(count[i]!=0){
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> v;
        unordered_set<string> map;
        for(int i = 0; i<strs.size(); i++){
            if(map.count(strs[i]))
            {
                continue;
            }
            vector<string> grp;
            grp.push_back(strs[i]);
            map.insert(strs[i]);
            for(int j = i +1; j<strs.size(); j++){
                if(isAnagram(strs[i],strs[j])){
                    grp.push_back(strs[j]);
                    map.insert(strs[j]);
                }
            }
            v.push_back(grp);
        }
        return v;
    }
};


// Approach # 2
// Space Complexity: O(m)
// Time Complexity: O(m * n)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        for(string s : strs){

            int count[26] = {0};

            for(char c : s){
                c = tolower(c);
                count[c - 97]++;
            }
            string key="";
            for(int i =0; i<26; i++){
                key+=to_string(count[i])+"#";
            }            
            map[key].push_back(s);
        }
        vector<vector<string>> v;
        for(auto &element : map){
            v.push_back(element.second);
        }
        return v;
    }
};
