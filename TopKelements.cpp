// https://neetcode.io/problems/top-k-elements-in-list?list=neetcode150

// Approach # 1
// Time Complexity : O(nlogn)
// Space Complexity : O(n)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        
        for(int i = 0; i<nums.size(); i++){
            map[nums[i]]++;             // value , frequency
        }

        vector<pair<int,int>> temp;
        for(auto &e : map){
            temp.push_back({e.second,e.first});  // frequency, value
        }
        
        sort(temp.rbegin(),temp.rend());

        vector<int> ans;
        for(int i = 0; i<k; i++){
            ans.push_back(temp[i].second);
        }
        return ans;

    }
};

// Approach # 2 (Bucket Sort Approach)
// Time Complexity : O(n)
// Space Complexity : O(n)


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        
        for(int i =0; i<nums.size(); i++){
            map[nums[i]]++;
        }

        vector<vector<int>> bucket(nums.size()+1);
        for(auto &e : map){
            bucket[e.second].push_back(e.first);
        }

        vector<int>results;
        for(int i = nums.size(); i>=0 && results.size()<k; i--){
            for(int num : bucket[i]){
                results.push_back(num);
                if(results.size() == k){
                    break;
                }
            }
        }
        return results;

    }
};


