class Solution {
public:
    int coinChange(vector<int>& coins, int target) {
        int MAX_CHANGE = target + 1 ;
        int tc = coins.size();
        if ( tc == 0) return 0;
        if ( target == 0) return 0;

        //  totalCoin[i] : Optimal number of coin when amount is i 
        std::vector<int> totalCoin(target+1, MAX_CHANGE );
        
        //Base case 
        totalCoin[0] = 0;
        
        //start with amount smaller to larger 	
        for (int i=1; i <= target; i++ ){

            for ( int j=0; j < tc; j++){
                        //need to handle larger coin value make target negative
                            // We can not use the coin which can not be further reduced 
                if ((i >= coins[j]) && (totalCoin[i - coins[j]] != MAX_CHANGE) ){
                    //std::cout << totalCoin[i] << " " << 1 + totalCoin[i - coins[j]] <<"\n";
                    totalCoin[i] = std::min(totalCoin[i], 1 + totalCoin[i - coins[j]]);
                }
            }
            //std::cout << "Optimal coin change for amount: " << i << " is: " << totalCoin[i] << "\n";
        }
        if (totalCoin[target] == MAX_CHANGE )	return -1;
        return totalCoin[target];	
        
    }
};
