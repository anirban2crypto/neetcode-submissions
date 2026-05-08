class Solution {
public:
    int uniquePathsRec(int r, int c, std::vector<std::vector<int>> &upath)
    {
        // Base case
        if (r ==0 && c == 0) return 1;

        // Boundary case 
        if (r < 0 || c < 0) return 0;

        //Check Memoization
        if (upath[r][c] != -1) return upath[r][c];

        // Calculate, STORE in upath, and return
        upath[r][c] = uniquePathsRec(r-1, c, upath) + uniquePathsRec(r, c-1, upath);
        return upath[r][c];
        
    }
    int uniquePaths(int m, int n) {
        if ( m == 0 && n == 0 ){
            return 0;
        }    
        std::vector<std::vector<int>> upath(m, std::vector<int>(n, -1));
        upath[0][0] = 1;
        int result = uniquePathsRec(m-1, n-1, upath);
        return result;
    }

};
