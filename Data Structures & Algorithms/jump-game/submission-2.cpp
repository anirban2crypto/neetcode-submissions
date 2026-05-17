class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if (n  == 0) return false; //empty array
        if (n  == 1) return true; // single element
        int targetPos = n-1;
        // dp[i] stored canReach from array position
        std::vector<int> dp(n,false);
        dp[targetPos] = true; // base case 
        for (int i=n-2; i>=0; i--){
            for (int j=1; j<=nums[i] && i+j <= targetPos; j++){
                if (dp[i+j]){ // can reach target from position i+j
                    dp[i] = true;
                    break;
                }
            }    	    
        }
    return dp[0];
    }
};
