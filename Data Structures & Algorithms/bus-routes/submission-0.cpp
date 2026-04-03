class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
               if (source == target) return 0;
        int n = routes.size();
        unordered_map<int, vector<int>> stops;
        for (int bus = 0; bus < n; bus++) {
            for (int stop : routes[bus]) {
                stops[stop].push_back(bus);
            }
        }

        unordered_set<int> seenBus;
        unordered_set<int> seenStop;
        seenStop.insert(source);
        queue<int> q;
        q.push(source);
        int res = 0;

        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i  < sz; i++) {
                int s = q.front(); q.pop();
                if (s == target) return res;

                for(int bus : stops[s]) {
                    if (seenBus.count(bus)) continue;

                    seenBus.insert(bus);
                    for(int nStop : routes[bus]) {
                        if (seenStop.count(nStop)) continue;

                        seenStop.insert(nStop);
                        q.push(nStop);
                    }
                }

            }
            res++;
        }

        return -1;
    }
};