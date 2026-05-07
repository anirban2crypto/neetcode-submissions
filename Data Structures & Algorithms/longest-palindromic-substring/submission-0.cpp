class Solution {
public:
    // work for both odd and even pallindrome
    // odd length pallindrome starting position, left=right
    // even length pallindrom starting position, right=left+1
    int getMaxlenExpandFromMid(const std::string &in_str, int left, int right){
        int length=in_str.size();
        while( left >=0 && right <= (length-1) &&  in_str[left] == in_str[right] ){
            left--;
            right++;
        }
        return (right - left - 1);
    }
    string longestPalindrome(string in_str) {
        int start=0;
        int end=0;
        int length=in_str.size();
        if (length == 0) return "";
            int max_pall_len=0;
        for(int i=0; i < length; i++){

                    //search odd pallindrome starting from i
            int len1= getMaxlenExpandFromMid(in_str,i,i);		

            // search even pallindrom starting from i,i+1
            int len2= getMaxlenExpandFromMid(in_str,i,i+1);

            // select maximum 
            max_pall_len = std::max(len1,len2);		

            // remember start and end position of the new find maximum
            // old maximum length is (end -start)
                    // update new start and end positon from max_pall_len and mid position i(i, i+1 for even)
            if (max_pall_len > (end - start)){
                start = i - (max_pall_len - 1) / 2;
                end = i + max_pall_len/2;
            }		
        }	
        // substr (start, length)
        return in_str.substr(start, (end- start+1));
    }
};
