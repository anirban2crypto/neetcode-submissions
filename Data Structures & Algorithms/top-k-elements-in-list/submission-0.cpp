#include <unordered_map>
#include <queue>
#include <vector>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::vector<int> top_k_list;
        std::unordered_map<int,int> freq;         
        std::priority_queue<std::pair<int,int>> maxHeap;
        for(int num : nums){
            freq[num]++;
        }
        for(auto &[num,fr] : freq){
            maxHeap.push({fr,num});
        }
        for(int i=0; i<k; i++){
            if(maxHeap.empty()) break;
            top_k_list.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return top_k_list;
    }
};
