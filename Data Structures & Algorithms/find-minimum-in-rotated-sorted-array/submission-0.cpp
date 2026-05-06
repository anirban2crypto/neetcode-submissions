class Solution {
public:
    int findMinRec(std::vector<int> &nums, int start, int end){

        //small case, one element
        if ( start == end ){
            return nums[start];
        }
        //small case, two elements
        if ((end - start +1 ) == 2){
            return std::min(nums[start],nums[end]);
        }
    
        // is start the minimum

        // is end the minumum

        // decide half based on start, mid , end
        int mid=(int)((start + end )/2);


        if( nums[start] <= nums[mid]  && nums[end] <= nums[mid] ){
            return findMinRec(nums,mid,end);
        } else if( nums[start] <= nums[mid]  && nums[end]  >= nums[mid] ){
            return nums[start];	
        } else {
            return findMinRec(nums,start,mid);
        }	
        return -1;
    }
    int findMin(vector<int> &nums) {
        int n=nums.size();	
	    return findMinRec(nums,0,n-1);
    }
};
