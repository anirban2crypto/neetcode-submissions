class Solution {
public:
    int charToIndex(char telement){
        int index = 0;
        if ( telement > 'Z'){
            //lower case
            index = telement - 'a' + 26;
        }
        else{
            //upper case  
            index = telement - 'A';
        }
        return index;
    }
    string minWindow(string s, string t) {       
        int slen = s.size();
        int tlen = t.size();
        if (slen == 0 || tlen == 0 ) return "";
        if (tlen > slen) return "";

        std::vector<int> tCFreq(52,0); // A..Z, a..z
        //build the frequency table from string t
        for (char telement : t){
                tCFreq[charToIndex(telement)]++;
        }

        int optimal_start_index = -1 ; 
        int optimal_finish_index = -1;
        int min_matching_len = slen + 1; 

        //Repeat the matching from a start position of source string             
        for (int start=0; start <= (slen - tlen); start++){   
                                   
            std::vector<int> backup = tCFreq;
            int match_counter = tlen;
            int finish_index = 0;

            // matching logic start
            for (int j=start; j<slen; j++){  // traverse source string 

                // check if source character exists in t string and not previously matched 
                if (tCFreq[charToIndex(s[j])] != 0 ){
                    //match
                    match_counter --;
                    tCFreq[charToIndex(s[j])] --;
                }
                
                //
                if (match_counter == 0){
                    finish_index = j;
                    break;
                } 
            } //matching logic complete
            
            // optimality check of the matching
            if(match_counter != 0){
                // from starting position there is no match possible    
                 break;
            } else {
                // matched, check if it is the optimal matching
                if ( (finish_index - start) < min_matching_len ){
                    // record  start index and finish index
                    min_matching_len = finish_index - start;
                    optimal_start_index = start;
                    optimal_finish_index = finish_index;
                }
            }     
            tCFreq = backup;
        }
        // Brute force completed

        std::string result;
        if (optimal_start_index == -1) return "";
        else {
            for(int j=optimal_start_index; j<=optimal_finish_index;j++){
                result.push_back(s[j]);
            }
        }
        return result;
 
    }
};
