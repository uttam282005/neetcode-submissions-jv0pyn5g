class UnionFind {
private:
    int n;
    vector<int> Parent;
    vector<int> Size;

public:
    UnionFind(int n) : n(n), Parent(n + 1), Size(n + 1, 1) {
        for (int i = 0; i <= n; i++) {
            Parent[i] = i;
        }
    }

    int find(int node) {
        if (Parent[node] != node) {
            Parent[node] = find(Parent[node]);
        }
        return Parent[node];
    }

    bool unionNodes(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return false;
        n--;
        if (Size[pu] < Size[pv]) swap(pu, pv);
        Size[pu] += Size[pv];
        Parent[pv] = pu;
        return true;
    }

    bool isConnected() {
        return n == 1;
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        UnionFind uf(n);

        unordered_map<int, int> factor_index;

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int f = 2;
            while (f * f <= num) {
                if (num % f == 0) {
                    if (factor_index.count(f)) {
                        uf.unionNodes(i, factor_index[f]);
                    } else {
                        factor_index[f] = i;
                    }
                    while (num % f == 0) {
                        num /= f;
                    }
                }
                f++;
            }
            if (num > 1) {
                if (factor_index.count(num)) {
                    uf.unionNodes(i, factor_index[num]);
                } else {
                    factor_index[num] = i;
                }
            }
        }

        return uf.isConnected();
    }
};