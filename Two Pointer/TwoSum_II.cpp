// https://neetcode.io/problems/two-integer-sum-ii?list=neetcode150

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int s = 0;
        int e = numbers.size() - 1;
        vector<int> v;
        while(s<e){
            if(numbers[s] + numbers[e] == target){
                break;
            }
            else if(numbers[s] + numbers[e] < target){
                s++;
            }
            else if(numbers[s] + numbers[e] > target){
                e--;
            } 
        }
        v.push_back(s+1);
        v.push_back(e+1);
        return v;

    }
};
