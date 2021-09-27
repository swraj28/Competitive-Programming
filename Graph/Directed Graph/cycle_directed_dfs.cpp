#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Graph {

    map<int, list<int>> adj;
public:

    void add_edges(int src, int dest) {
        adj[src].push_back(dest);
    }

    bool dfs(int src, bool*visited, bool*stack) {

        visited[src] = true;
        stack[src] = true;

        for (auto nbr : adj[src]) {
            if (stack[nbr] == true) {
                return true;
            } else if (visited[nbr] == false) {
                bool cycle_mila = dfs(nbr, visited, stack);
                if (cycle_mila) {
                    return true;
                }
            }
        }

        stack[src] = false;

        return false;
    }

    bool contain_cycle() {

        bool*visited = new bool[adj.size()];
        bool*stack = new bool[adj.size()];

        for (int i = 0; i < adj.size(); i++) {
            visited[i] = stack[i] = false;
        }

        return dfs(0, visited, stack);
    }

};


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    Graph g;

    g.add_edges(0, 1);
    g.add_edges(1, 2);
    g.add_edges(2, 3);
    g.add_edges(3, 4);
    g.add_edges(4, 5);
    g.add_edges(1, 5);
    g.add_edges(5, 6);
    // g.add_edges(4, 2);//Back Edge

    if (g.contain_cycle() == true) {
        cout << "The Cycle Is Present" << endl;
    } else {
        cout << "No Cycle Is Present" << endl;
    }



    return 0;
}