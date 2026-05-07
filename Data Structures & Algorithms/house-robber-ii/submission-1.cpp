class Solution {
public:
    int robdp(const std::vector<int> &nums){
        int n=nums.size();

        if (n < 1) return 0;

        std::vector<int> sum_rob(n+1, 0);

        sum_rob[0] =nums[0];
        sum_rob[1] =std::max(nums[0],nums[1]);

        for(int i=2; i < n; i++){
            sum_rob[i] = std::max(nums[i] + sum_rob[i-2], sum_rob[i-1]);		
        }

        return sum_rob[n-1];
        
    }


    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        std::vector<int> slice1(nums.begin(), nums.end() - 1);
	    std::vector<int> slice2(nums.begin() + 1, nums.end());
	    int max_value = std::max(robdp(slice1),robdp(slice2));
        return max_value;
    }
};
