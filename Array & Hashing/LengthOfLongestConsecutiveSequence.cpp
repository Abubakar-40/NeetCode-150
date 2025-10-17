//https://neetcode.io/problems/longest-consecutive-sequence?list=neetcode150


// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> map(nums.begin(),nums.end());

        int longest = 0;
        for(int num : nums){

            if(map.count(num - 1) == 0){ // means num is start of new sequence 

                int curr = num;
                int streak = 1;
                while(map.count(curr + 1) == 1){
                    curr++;
                    streak++;
                }
                longest = max(longest,streak);
            }
            
        }
        return longest;
    }
};
