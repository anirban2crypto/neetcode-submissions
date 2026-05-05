class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> lastSeen;
        int start = 0;
        int global_len = 0;
        for (int end=0; end < s.length(); ++end){
            char c = s[end];
            // c not found, new char seen, add it to map substr
            if(lastSeen.find(c) != lastSeen.end() && lastSeen[c] >= start){
                start = lastSeen[c] + 1;
            }
            lastSeen[c] = end;
            global_len = std::max(global_len, end -start +1);
        }
        return global_len;
    }
};
