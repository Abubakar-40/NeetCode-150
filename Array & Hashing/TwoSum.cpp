// https://neetcode.io/problems/two-integer-sum?list=neetcode150

// Approach # 1
// Time Complexity : O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        v.push_back(-1);
        v.push_back(-1);
        for(int i = 0;i<nums.size() - 1; i++){
            for(int j = i + 1; j<nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    v[0] = i;
                    v[1] = j;
                    break;
                } 
            }
        }
        return v;
    }
};

// Approach # 2
// Time Complexity : O()
// Space Complexity : O()