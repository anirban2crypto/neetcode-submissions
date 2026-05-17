class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
	    if (n < 2) return {};
        std::vector<int> result;
	    int left = 0;
	    int right = n-1;
	    while(left < right){
		    if (nums[left] + nums[right] == target){
			    result.push_back(left+1);
                result.push_back(right+1);	
                break;
            }
            else if (nums[left] + nums[right] > target){
	            right--;
            }
            else{
	            left ++;
            }
        }
        return result;
    }
};
