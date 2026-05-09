class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int sum = 0;
        int max_sum = nums[0];
        
        for (int num : nums){
            sum += num;
            if (sum <= num ){
                sum = num;
            }    
            max_sum = std::max(max_sum,sum);
            std::cout << "sum: " << sum << " max sum:" << max_sum << "\n"; 
        }
        return max_sum;
    }
};
