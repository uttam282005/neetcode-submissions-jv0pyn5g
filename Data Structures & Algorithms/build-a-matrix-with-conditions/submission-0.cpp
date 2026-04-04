class Solution {
public:
vector<int> toposort(int k, vector<vector<int>> &edges) {
    vector<vector<int>> G(k + 1);
    vector<int> ind(k + 1); 
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0]; int v = edges[i][1];
        G[u].push_back(v);
        ind[v]++;
    }

    queue<int> q;
    for(int i = 1; i <= k; i++) if (ind[i] == 0) q.push(i);
    vector<int> order;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);
        for(int c : G[node]) {
            ind[c]--;
            if (ind[c] == 0) q.push(c);
        }
    }

    if (order.size() != k) return {};
    return order;
    
}
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowOrder = toposort(k, rowConditions);
        vector<int> colOrder = toposort(k, colConditions);

        if (rowOrder.size() == 0 or colOrder.size() == 0) return {};

        unordered_map<int, int> row, col;
        for(int i = 0; i < rowOrder.size(); i++) row[rowOrder[i]] = i;
        for(int i = 0; i < colOrder.size(); i++) col[colOrder[i]] = i;

        vector<vector<int>> res(k, vector<int> (k, 0));
        for(int i = 1; i <= k; i++) {
            int r = row[i];
            int c = col[i];

            res[r][c] = i;

        }

        return res;
    }
};