class Solution {
public:
    int searchRec(const std::vector<int> &nums, int target,int start,int end){
        if (start == end){
            if (nums[start] == target){
                return start;
            }
            else{
                return -1;
            }
        }

        int mid=start + (end - start )/2;	
        if (nums[mid] == target){
            return mid;
        }
        //whole array is sorted
        if( nums[start] <= nums[end] ){
            if ( target > nums[mid] ){
                return searchRec(nums, target,mid+1,end);
            }
            else {
                return searchRec(nums, target,start,mid);
            }
            
        }
            // array is rotated, two cases possible either right half sorted or left half sorted
        else{
            // left side sorted
            if( nums[start] <= nums[mid]){
                // target must be in left half
                if (target <= nums[mid] && target >= nums[start] ){
                    return searchRec(nums, target,start,mid);			
                } else{
                    return searchRec(nums, target,mid+1,end);
                }
            }

            //right side sorted 
            else if (nums[mid] <= nums[end]){
                // target must be in right half
                if (target >= nums[mid] && target <= nums[end]){
                    return searchRec(nums, target,mid+1,end);
                }else {
                    return searchRec(nums, target,start,mid);				
                }	
            }
            else{
                return -1;
            }
        }	
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
	    return searchRec(nums,target,0,n-1);
    }
};
