class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<int> minDist(n, INT_MAX);
        vector<bool> used(n, false);

        minDist[0] = 0;
        int totalCost = 0;

        for (int i = 0; i < n; i++) {
            int u = -1;

            // pick minimum unused node
            for (int j = 0; j < n; j++) {
                if (!used[j] && (u == -1 || minDist[j] < minDist[u])) {
                    u = j;
                }
            }

            used[u] = true;
            totalCost += minDist[u];

            // update distances
            for (int v = 0; v < n; v++) {
                if (!used[v]) {
                    int cost = abs(points[u][0] - points[v][0]) +
                               abs(points[u][1] - points[v][1]);

                    minDist[v] = min(minDist[v], cost);
                }
            }
        }

        return totalCost;
    }
};