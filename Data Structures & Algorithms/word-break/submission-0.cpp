class Solution {
public:
    bool wordBreak(std::string words, std::vector<std::string> &dict){
        std::unordered_set<std::string> dict_set(dict.begin(),dict.end());
        int wlen = words.size();

        //if  segm_stat[i] = true, means words[0 .. i-1] can be segmented
        std::vector<bool> segm_stat(wlen+1,false);
        segm_stat[0] = true; //index zero means words is empty

        // i=1, starting from first index of words
        // Calculate segm_stat[i] , upto length i can be segmented 
        for(int i=1; i<=wlen; i++){

            // break the words two parts words[0 ..j] and words[j..i-1] and checks they can be segmented recursively
            // if any such j exists then fine
            for(int j=0; j<i; j++){
                if(segm_stat[j] == true && dict_set.find(words.substr(j,i-j)) != dict_set.end() ){
                    segm_stat[i] = true;
                    break;
                }	
            }
        } 
        return segm_stat[wlen];

    }
};
