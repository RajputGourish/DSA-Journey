#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/longest-common-suffix-queries/submissions/2015663134/?envType=daily-question&envId=2026-05-28
*/


class Solution {
public:
    struct Node {
        int child[26];
        int bestLen;
        int bestIdx;

        Node() {
            memset(child, -1, sizeof(child));
            bestLen = INT_MAX;
            bestIdx = INT_MAX;
        }
    };

    vector<Node> trie;

    Solution() {
        trie.push_back(Node()); // root
    }

    void update(int node, int len, int idx) {
        if (len < trie[node].bestLen) {
            trie[node].bestLen = len;
            trie[node].bestIdx = idx;
        }
        else if (len == trie[node].bestLen &&
                 idx < trie[node].bestIdx) {
            trie[node].bestIdx = idx;
        }
    }

    void insert(string &s, int idx) {
        int cur = 0;
        int len = s.size();

        update(cur, len, idx);

        for (int i = len - 1; i >= 0; --i) {
            int c = s[i] - 'a';

            if (trie[cur].child[c] == -1) {
                trie[cur].child[c] = trie.size();
                trie.push_back(Node());
            }

            cur = trie[cur].child[c];
            update(cur, len, idx);
        }
    }

    int query(string &s) {
        int cur = 0;

        for (int i = s.size() - 1; i >= 0; --i) {
            int c = s[i] - 'a';

            if (trie[cur].child[c] == -1)
                break;

            cur = trie[cur].child[c];
        }

        return trie[cur].bestIdx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        for (int i = 0; i < wordsContainer.size(); i++)
            insert(wordsContainer[i], i);

        vector<int> ans;

        for (auto &q : wordsQuery)
            ans.push_back(query(q));

        return ans;
    }
};

int main(){
    
    return 0;
}