#include <unordered_map>
#include <algorithm>
#include <string>
class Solution {
public:
    string buildKey(const string &word){
        vector<int> dict_alphabets(26,0);
        for(char c : word){
            dict_alphabets[c -'a']++;
        }
        string key;
        for (int count: dict_alphabets){
            key += "#" + to_string(count);
        }
        return key;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> ang_groups;
        // for(string str : strs){
        //     string key = str;
        //     std::sort(key.begin(),key.end());
        //     ang_groups[key].push_back(str);
        // }
        for(string str : strs){
             string key = buildKey(str);        
             ang_groups[key].push_back(str);
        }
        
        vector<vector<string>> anagram_list;
        for (auto &entry : ang_groups) {
            anagram_list.push_back(entry.second);
        }
        return anagram_list;
    }
};
