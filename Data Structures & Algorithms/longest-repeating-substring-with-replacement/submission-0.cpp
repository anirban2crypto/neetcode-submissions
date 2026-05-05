class Solution {
public:
    int characterReplacement(string s, int k) {
        std::vector<int> sl_freq(26,0);
        int n=static_cast<int>(s.length());
        int max_window = 0;
        int max_freq = 0;
            int start = 0;

        //Replacements = Window Length - Count of the Most Frequent Character
        //check how much we can extend the window, when exausted, slide the window
        for(int i=0; i <n; i++){	
            

            //insert the new char in window map
            sl_freq[s[i] -'A']++;	

            //std::cout << s[i] << " : " <<sl_freq[s[i] -'A'] <<"\n";		
            
            //calculate the max frequency
            max_freq = std::max(max_freq,sl_freq[s[i] -'A']);
            
            //std::cout << "maximum frequency: " << max_freq << "\n";
            
            //std::cout << "Exaust conditon: " << ( i -start + 1)<< " : "  << ((i - start + 1) - max_freq) << "\n";

            //if window exausted
            if ( ((i - start + 1) - max_freq) > k){
                sl_freq[s[start] -'A']--;
                start++;			
            }
            
            // update the max windows
            max_window= std::max(max_window, i-start+1);	
            //std::cout << "max window " << max_window << "\n";

                            
        }
        //calculate the last windows 

        return max_window;
 
    }
};
