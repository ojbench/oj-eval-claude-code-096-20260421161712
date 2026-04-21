#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    // Read first non-empty line as q
    int q = 0;
    while (getline(cin, line)) {
        if (!line.empty()) {
            istringstream iss(line);
            if (iss >> q) break;
        }
    }
    if (q <= 0) {
        // If q is 0, still attempt to read traversal line to handle edge cases
        // But per problem, q >= 1 typically
    }

    vector<pair<int,int>> queries;
    queries.reserve(max(0, q));
    for (int i = 0; i < q; ++i) {
        // Read next non-empty line containing two ints
        while (getline(cin, line)) {
            if (line.empty()) continue;
            istringstream iss(line);
            int x, y;
            if (iss >> x >> y) {
                queries.emplace_back(x, y);
                break;
            }
        }
    }

    // Read the last non-empty line as preorder traversal with -1 placeholders
    string traversalLine;
    while (getline(cin, line)) {
        if (!line.empty()) traversalLine = line;
    }
    if (traversalLine.empty()) {
        // No traversal provided; nothing to answer
        return 0;
    }

    vector<int> tokens;
    {
        istringstream iss(traversalLine);
        int v;
        while (iss >> v) tokens.push_back(v);
    }

    // Parse expanded preorder and record depth and parent for each non -1 value
    unordered_map<int, pair<int,int>> info; // value -> {depth, parent}

    function<void(size_t&, int, int)> dfs = [&](size_t &idx, int depth, int parent){
        if (idx >= tokens.size()) return;
        int val = tokens[idx++];
        if (val == -1) return;
        info[val] = {depth, parent};
        dfs(idx, depth + 1, val);
        dfs(idx, depth + 1, val);
    };

    size_t idx = 0;
    dfs(idx, 0, -1);

    // Answer queries
    for (auto [x, y] : queries) {
        auto itx = info.find(x);
        auto ity = info.find(y);
        int ans = 0;
        if (itx != info.end() && ity != info.end()) {
            int dx = itx->second.first;
            int dy = ity->second.first;
            int px = itx->second.second;
            int py = ity->second.second;
            if (dx == dy && px != py) ans = 1;
        }
        cout << ans << "\n";
    }

    return 0;
}
