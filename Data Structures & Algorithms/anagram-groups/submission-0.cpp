#include <unordered_map>
#include <algorithm>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> ang_groups;
        for(string str : strs){
            string key = str;
            std::sort(key.begin(),key.end());
            ang_groups[key].push_back(str);
        }
        
        vector<vector<string>> anagram_list;
        for (auto &entry : ang_groups) {
            anagram_list.push_back(entry.second);
        }
        return anagram_list;
    }
};
