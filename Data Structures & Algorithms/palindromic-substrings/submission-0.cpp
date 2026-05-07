class Solution {
public:

    // work for both odd and even pallindrome
    // odd length pallindrome starting position, left=right
    // even length pallindrom starting position, right=left+1
    int getMaxlenExpandFromMid(const std::string &in_str, int left, int right){
        int length=in_str.size();
            int pall_ctr=0;
        while( left >=0 && right <= (length-1) &&  in_str[left] == in_str[right] ){
            left--;
            right++;
            pall_ctr++;
        }
        return pall_ctr;
    }

    int countSubstrings(const std::string &in_str){	
        int start=0;
        int end=0;
        int length=in_str.size();
        if (length == 0) return 0;
            int pall_str_ctr=0;
        for(int i=0; i < length; i++){
            //search odd pallindrome starting from i            
            int len1= getMaxlenExpandFromMid(in_str,i,i);		
            // search even pallindrom starting from i,i+1
            int len2= getMaxlenExpandFromMid(in_str,i,i+1);
            pall_str_ctr += len1 + len2;
        }	
        return pall_str_ctr;
    }
};
