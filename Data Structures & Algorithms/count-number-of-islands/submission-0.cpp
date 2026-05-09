class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int nrow = grid.size();
        int ncol = grid[0].size();
        int nislands = 0; 
        enum class State : uint8_t { NVISIT, VISIT};
        std::vector<std::vector<State>> grid_state(nrow,std::vector<State>(ncol,State::NVISIT));
        std::stack<std::pair<int,int>> grid_in_visit;

        for (int i=0; i<nrow; i++) {
            for (int j=0; j<ncol; j++){
                if ( grid[i][j] == '1'  && grid_state[i][j] == State::NVISIT) {
                    nislands ++;
                    grid_state[i][j] = State::VISIT;
                    grid_in_visit.push({i,j});
                    while(!grid_in_visit.empty()) {
                        auto [row,col] = grid_in_visit.top();
                        grid_in_visit.pop();

                        // 4-directional neighbors
                        const int dr[4] = {-1, 1, 0, 0};
                        const int dc[4] = {0, 0, -1, 1};
                        for (int k = 0; k < 4; k++) {
                            int nr = row + dr[k];
                            int nc = col + dc[k];
                            if (nr >= 0 && nr < nrow && nc >= 0 && nc < ncol) {
                                if (grid[nr][nc] == '1' && grid_state[nr][nc] == State::NVISIT) {
                                    grid_state[nr][nc] = State::VISIT;
                                    grid_in_visit.push({nr,nc});
                                }
                            }                             
                        }    
                    } 
                }
            }
        }
        return nislands;    
    } 
};
