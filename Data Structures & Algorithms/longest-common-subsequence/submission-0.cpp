class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {        
        int n1 = text1.size();
        int n2 = text2.size();
        if (n1 == 0 || n2 == 0 ) return 0;
        // the array lcs[i][j]  store lcs between text1[i] and text2[j]
        std::vector<std::vector<int>> lcs (n1+1,std::vector<int>(n2+1,0)); 
        for (int i=1; i<=n1; i++){
            for(int j=1; j <=n2; j++){
                if (text1[i-1] == text2[j-1]){
                    lcs[i][j] = 1 + lcs[i-1][j-1];
                }
                else {
                    lcs[i][j] = std::max(lcs[i-1][j],lcs[i][j-1]);
                }
            }
        }	

        return lcs[n1][n2];

    }
};
