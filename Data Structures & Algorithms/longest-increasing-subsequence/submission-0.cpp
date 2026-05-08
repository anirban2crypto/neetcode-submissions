class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int nums_len = nums.size();

        if (nums_len == 0) return 0;

        //lis_so_far[i] is longest strictly increasing subsequence eding at position i
        std::vector<int> lis_so_far (nums_len+1,1);

        for (int i=0; i < nums_len; i++){
            for( int j=0; j < i; j++ ){
                if ( nums[j] < nums[i] ){
                    lis_so_far[i] = std::max(lis_so_far[i], 1 + lis_so_far[j]);
                }    
            }
        } 
        return *std::max_element(lis_so_far.begin(),lis_so_far.end());
    }
};
