class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> inMst(n, false);
        int cost = 0;
        vector<int> dis(n, INT_MAX);

        dis[0] = 0;
        for(int i = 0; i < n; i++) {
            int u = -1;

            for(int j = 0; j < n; j++) {
                if (!inMst[j] and (u == -1 || (dis[j] < dis[u]))) {
                    u = j;
                }
            }

            inMst[u] = true;
            cost += dis[u];
            for(int j = 0; j < n; j++) {
                if (!inMst[j]) {
                    dis[j] = min(
                        dis[j],
                        abs(points[u][0] - points[j][0]) + abs(points[j][1] - points[u][1])
                    );
                }
            }
        }

        return cost;
    }
};
