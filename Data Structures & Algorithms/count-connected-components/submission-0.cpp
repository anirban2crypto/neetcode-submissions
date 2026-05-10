class UnionFind {
    public:
        std::vector<int> parent;
        std::vector<int> rank; 

        UnionFind(int n){
            parent.resize(n);
            rank.resize(n,0);
            for (int i=0; i<n; i++) parent[i] = i;
        }

        int find(int x){
            if (parent[x] != x){
                parent[x] = find(parent[x]); //path compression
            }
            return parent[x];
        }
        
        void unite(int x, int y){
            int rootX = find(x);
            int rootY = find(y);

            if(rootX == rootY) return;

            //union by rank
            if(rank[rootX] < rank[rootY]){
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]){
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
            }
        }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int cc;
        UnionFind uf(n);
        std::unordered_set<int> roots;

        for (auto &edge : edges){
            uf.unite(edge[0],edge[1]);
        }

        //counting the distinct root
        for(int i=0; i<n; i++){
            roots.insert(uf.find(i));
        }
        return roots.size();
    }
};
