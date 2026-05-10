class Solution {
public:
    bool validTree(int n, std::vector<std::vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }
        if (n <= 1) return true;

        std::vector<std::vector<int>> adj_list(n);

        for (auto & edge : edges){
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }
        std::vector<int> visit_status(n,0);
        int visited_count = 0;
        
        std::stack<int> stck;
        visit_status[0] = 1;
        stck.push(0);

        while(!stck.empty()){
            int curr = stck.top();
            stck.pop();
            visited_count++;
            for(int neighbor : adj_list[curr]){
                if (visit_status[neighbor] == 0){
                    visit_status[neighbor] = 1;
                    stck.push(neighbor);
                }
            }                
        }            
                
        return visited_count == n;
    }
};
