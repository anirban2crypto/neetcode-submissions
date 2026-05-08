class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int nums_len = nums.size();
        if (nums_len == 0) return 0; 
        std::vector<int> lis_so_far;
        for(auto num : nums){
            // binary search in lis_so_far , find first element >= num
            auto it = std::lower_bound(lis_so_far.begin(),lis_so_far.end(),num);
            if (it == lis_so_far.end()){
                // num is larger than all elements in lis_so_far, append at end, extend LSIS
                lis_so_far.push_back(num);
            } else{
                // Replace existing elment with num to mainin increasing order
                *it = num;
            }
        }
        return lis_so_far.size();
    }
};
