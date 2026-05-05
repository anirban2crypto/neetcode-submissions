class Solution {
public:
    int maxArea(vector<int>& bars) {
        int max_area=0;
        int left=0;
        int right=bars.size()-1;
        while(left < right){
            int ht = std::min(bars[left],bars[right]);	
            int wd = right - left;
            int area=ht*wd;
            max_area=std::max(max_area,area);
            if (bars[left] < bars[right]){
                left++;
            } else if (bars[left] > bars[right]){
                right--;
            } else {
                left++;
                right--;
            }
        }
        return max_area;
    }
};
