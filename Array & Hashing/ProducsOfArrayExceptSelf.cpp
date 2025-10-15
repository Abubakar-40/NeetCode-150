//https://neetcode.io/problems/products-of-array-discluding-self?list=neetcode150

//Approach # 1(using product of Prefix and suffix)
// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pref(nums.size(),1),suff(nums.size(),1);
        pref[0] = 1;
        for(int i = 1; i<nums.size();i++){
            pref[i] = pref[i - 1]*nums[i - 1];
        }
        suff[nums.size() - 1] = 1;
        for(int i = nums.size() - 2; i>=0; i--){
            suff[i] = suff[i+1]*nums[i+1];
        }
        for(int i = 0; i<nums.size(); i++){
            pref[i]*=suff[i];
        }
        return pref;
    }
};


//Approach # 2(using product of Prefix and suffix)
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(),1);

        output[0] = 1;
        for(int i = 1; i<nums.size();i++){
            output[i] = output[i - 1]*nums[i - 1];
        }

        int suffix = 1;
        for(int i = nums.size() - 1; i>=0; i--){
            output[i] = output[i] * suffix;
            suffix = suffix * nums[i];
        }
        return output;
    }
};
