//https://neetcode.io/problems/string-encode-and-decode?list=neetcode150

class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        
        for(string s : strs){
            encoded+= to_string(s.size()) + "#" + s;            
        }
        return encoded;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> result;
        while(i < s.size()){
            
            int j = i;
            while(s[j] != '#'){
                j++;
            }

            int length = stoi(s.substr(i,j - i));

            string temp = s.substr(j+1,length);

            result.push_back(temp);
            i = j + length + 1;
        }
        return result;
    }
};
