class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> leftprod(nums.size(),1);
        std::vector<int> rightprod(nums.size(),1);
	    std::vector<int> res(nums.size(),1);
	
        //front scanning        
        for(int i=1;i < nums.size();i++){
            leftprod[i] = leftprod[i-1]*nums[i-1];		
        } 
        
        //back scanning
            for(int i=nums.size()-2; i >= 0; i--){
            rightprod[i] = rightprod[i+1]*nums[i+1];		
        } 

        //find product
        for(int i=0; i < nums.size(); i++){
            res[i]=leftprod[i] * rightprod[i];
        }
        return res;
    }
};
