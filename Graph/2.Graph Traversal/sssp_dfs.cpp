#include <bits/stdc++.h>
using namespace std;

//Single Source Shortest Path in an unweighted Graph
//t.c-o(v+e)
class Graph {

    map<int, list<int>> adj;

public:

    void add_edges(int src, int dest, bool bidir = true) {
        adj[src].push_back(dest);
        if (bidir) {
            adj[dest].push_back(src);
        }
    }

    void print() {

        //Iterate over the map
        for (auto i : adj) {
            cout << i.first << "->";

            //i.second is LL
            for (auto entry : i.second) {
                cout << entry << ",";
            }
            cout << endl;
        }
    }
    // This String we have Used to store the Best Path
    string ans = "";
    void dfs(vector<int> &visited, vector<int> &path, int &d, int src, int dest) {
        visited[src] = 1;
        path.push_back(src);

        if (src == dest) {
            int len = path.size() - 1;
            if (len < d) {
                d = len;
                ans = "";
                for (auto i : path) {
                    int node = i;
                    char ch = node + '0';
                    ans += ch;
                }
            }
            return;
        }

        for (auto nbr : adj[src]) {
            if (!visited[nbr]) {
                dfs(visited, path, d, nbr, dest);
                //Backtracking
                visited[nbr] = 0;
                path.pop_back();
            }
        }
    }

    void sssp_dfs(int src, int dest) {

        vector<int> path;
        vector<int> visited(adj.size(), 0);
        int d = INT_MAX;

        dfs(visited, path, d, src, dest);

        cout << "The Required Distance and Path Is " << endl;
        cout << d << endl;
        for (int i = 0; i < ans.length(); i++) {
            cout << ans[i] << "->";
        }
        cout << endl;
    }
};

int main() {

    Graph g;

//     g.add_edges(0, 1);
//     g.add_edges(0, 2);
//     g.add_edges(1, 2);
//     g.add_edges(1, 3);
//     g.add_edges(2, 3);
//     g.add_edges(2, 4);
//     g.add_edges(2, 5);
//     g.add_edges(3, 4);
//     g.add_edges(3, 5);
//     g.add_edges(4, 5);
//     g.add_edges(4, 6);
//     g.add_edges(5, 6);

    // g.add_edges(0, 1);
    // g.add_edges(1, 2);
    // g.add_edges(0, 4);
    // g.add_edges(2, 4);
    // g.add_edges(2, 3);
    // g.add_edges(3, 5);
    // g.add_edges(3, 4);

    g.add_edges(0, 1);
    g.add_edges(1, 2);
    g.add_edges(2, 3);
    g.add_edges(3, 4);
    g.add_edges(0, 3);
    g.add_edges(4, 5);

    cout << "The Required Graph representation is" << endl;
    g.print();
    g.sssp_dfs(0, 5);


    return 0;
}