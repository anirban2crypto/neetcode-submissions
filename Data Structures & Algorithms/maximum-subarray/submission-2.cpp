class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int curr_sum = 0;
        int max_sum = nums[0];
        
        for (int num : nums){
            curr_sum = std::max(num, curr_sum + num);
            max_sum = std::max(max_sum, curr_sum);
        }
        return max_sum;
    }
};
