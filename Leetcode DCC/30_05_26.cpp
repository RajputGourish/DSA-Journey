#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/block-placement-queries/submissions/2017383613/?envType=daily-question&envId=2026-05-30
*/

class SegmentTree {
    int n;
    vector<int> tree;

public:
    SegmentTree(int n) : n(n), tree(4 * n, 0) {}

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }

        int mid = (l + r) >> 1;

        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return tree[node];

        int mid = (l + r) >> 1;

        return max(
            query(node * 2, l, mid, ql, qr),
            query(node * 2 + 1, mid + 1, r, ql, qr)
        );
    }

    int query(int l, int r) {
        if (l > r) return 0;
        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<int> coords = {0};

        for (auto &q : queries)
            coords.push_back(q[1]);

        sort(coords.begin(), coords.end());
        coords.erase(unique(coords.begin(), coords.end()), coords.end());

        auto getIdx = [&](int x) {
            return lower_bound(coords.begin(), coords.end(), x) - coords.begin();
        };

        int m = coords.size();

        set<int> obstacles;
        obstacles.insert(0);

        for (auto &q : queries) {
            if (q[0] == 1)
                obstacles.insert(q[1]);
        }

        SegmentTree seg(m);

        for (auto it = next(obstacles.begin()); it != obstacles.end(); ++it) {
            int cur = *it;
            int prv = *prev(it);
            seg.update(getIdx(cur), cur - prv);
        }

        vector<bool> ans;

        for (int i = (int)queries.size() - 1; i >= 0; --i) {
            auto &q = queries[i];

            if (q[0] == 2) {
                int x = q[1];
                int sz = q[2];

                auto it = obstacles.upper_bound(x);
                --it;

                int p = *it;

                int mx = seg.query(0, getIdx(p));
                int tail = x - p;

                ans.push_back(max(mx, tail) >= sz);
            }
            else {
                int p = q[1];

                auto it = obstacles.find(p);

                auto pit = prev(it);
                auto nit = next(it);

                int prv = *pit;

                if (nit != obstacles.end()) {
                    int nxt = *nit;
                    seg.update(getIdx(nxt), nxt - prv);
                }

                seg.update(getIdx(p), 0);
                obstacles.erase(it);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};


int main(){
    
    return 0;
}