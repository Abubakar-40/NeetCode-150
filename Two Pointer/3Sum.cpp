// https://neetcode.io/problems/three-integer-sum?list=neetcode150

//Approach # 1
// Time complexity : O(n^2)
// Space Complexity : O(1)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> v;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0; i<n - 2; i++){

            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }

            int left = i + 1;
            int right = n - 1;
            while(left<right){

                int sum = nums[i] + nums[left] + nums[right];

                if(sum == 0){
                    v.push_back({nums[i],nums[left],nums[right]});

                    while(left < right && nums[left] == nums[left + 1]){
                        left++;
                    }
                    while(left<right && nums[right] == nums[right - 1]){
                        right--;
                    }
                    left++;
                    right--;
                }
                else if(sum<0){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return v;
    }
};














