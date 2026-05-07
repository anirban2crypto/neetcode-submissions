class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int len = nums.size();
        int global_maxp = nums[0];  // maximum positive so far
        int global_minn = nums[0];  // minimum negative so far
        int prev_maxp = nums[0];
        int prev_minn = nums[0];

        for(int i=1; i< len; i++ ){
            //std::cout << "index i: " << i << " Numbers " << nums[i] <<"\n";
            // maximum of previous maximum positive, curr is positive ,
            // curr is negative and multiplied with previos min negative, current number. 
            //std::cout <<"prev max: " <<prev_maxp <<" prev min: " <<prev_minn << "\n";
            int temp = prev_maxp;
            int curr_maxp=std::max({prev_maxp*nums[i], prev_minn * nums[i], nums[i]});
            //std::cout << "current maxp: "<< curr_maxp <<"\n";
            // found a new max
            if(curr_maxp >= global_maxp) {
                global_maxp = curr_maxp;
                prev_maxp = curr_maxp;			
            } else{
                //reset previous maximum positive			
                prev_maxp = curr_maxp;
            }
            // previous largest negative product
            // current is negative mulitplies with previous max positive
            // current is positive multiplies with previos min negative
            // current is largest negative number
            int curr_minn=std::min({temp*nums[i], prev_minn*nums[i], nums[i]});
            //std::cout << "current minn: "<< curr_minn <<"\n";
            if (curr_minn <= global_minn) {
                global_minn = curr_minn;
                prev_minn = curr_minn;
            } else {
                prev_minn = curr_minn;
            }		
        }	
        return std::max(global_maxp,global_minn);

    }

};
