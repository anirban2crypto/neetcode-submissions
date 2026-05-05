class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price= INT_MAX;
        int max_profit=0;
        for(int price : prices){
            // update the lowest price we've seen so far
            min_price=std::min(min_price, price);
            //Calculate the profit if we sold today
            int curr_profit = price-min_price;
            //update the best profit if found
            max_profit = std::max(max_profit,curr_profit); 		
        }
        return max_profit;

}

};
