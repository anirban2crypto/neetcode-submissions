class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       	if (nums.empty()) return 0;
        int longest=0;
        std::unordered_map<int,bool> element_exists;
        for (int num : nums){
            element_exists[num]=true;
        }
        for(int num : nums){
            if(element_exists.find(num-1) == element_exists.end()){
                int currentNum = num;
                int seqlength=1;
                while(element_exists.find(currentNum +1) != element_exists.end()){
                    currentNum++;
                    seqlength++;
                }
                longest=std::max(longest,seqlength);
            }
        }
        
        return longest; 
    }
};
