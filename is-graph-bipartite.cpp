class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colour(graph.size(), -1); 
        for(int i = 0; i < graph.size(); i++) {
            if(colour[i] == -1) {
                if(!dfs(i, 0, colour, graph)) return false;
            }
        }
        return true; 
    }

    bool dfs(int node, int color, vector<int>& colour, vector<vector<int>>& graph) {
        colour[node] = color; 
        for(auto it: graph[node]) {
            if(colour[it] == -1) {
                if(!dfs(it, !color, colour, graph)) return false;
            } else if(colour[it] == color) {
                return false;
            }
        }
        return true;
    }
};
