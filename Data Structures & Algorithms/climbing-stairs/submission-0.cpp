class Solution {
public:
    int climbStairs(int n) {
    	if (n <= 1){
            return 1;
        }        
            std::vector<int> comb(n+1, 0);
        comb[0] = 1;
        comb[1] = 1;
        for(int i=2; i<= n; i++){
            comb[i] = comb[i-1] + comb[i-2]; 
        }
        return comb[n];
        
    }
};
