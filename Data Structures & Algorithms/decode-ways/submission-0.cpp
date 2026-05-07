class Solution {
public:

    int numDecodings(std::string in_str){
        int len=in_str.size();
        if ( len == 0 || in_str[0] == '0' ) return 0;

        // ways[i] represents the number of ways to decode a string of length i
        std::vector<int> ways(len+1,0);
        ways[0] = 1; // Base case: empty string
        ways[1] = 1; // Base case: first char

        for(int i=2; i<=len; i++){
            // Option 1: Single digit (must not be '0')
            if (in_str[i-1] != '0'){
                ways[i] = ways[i-1];
            }
            // Option 2: Two digits (must be between 10 and 26)	
            std::string two_digits=in_str.substr(i-2, 2);
            int combined = std::stoi(two_digits);			
            if (combined <= 26 && combined >= 10) {				
                    ways[i] +=  ways[i-2];
            }             
        }
        return ways[len];  
        
    }
};
