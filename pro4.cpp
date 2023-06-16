#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main() {
    int e;
    cin >> e;

    map<string, vector<string>> adj_list;
    for (int i = 0; i < e; i++) {
        string u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
    }
    bool flag = true;
    for (auto it = adj_list.begin(); it != adj_list.end(); it++) {
        for (int i = 0; i < it->second.size(); i++) {
            string u = it->first;
            string v = it->second[i];
            if (adj_list.find(v) == adj_list.end()) {
                flag = false;
                cout << "FALSE" << endl;
                return 0;
            }
            bool has_reverse_edge = false;
            for (int j = 0; j < adj_list[v].size(); j++) {
                if (adj_list[v][j] == u) {
                    flag = false;
                    has_reverse_edge = true;
                    break;
                }
            }
            if (!has_reverse_edge) {
                cout << "FALSE" << endl;
                return 0;
            }
        }
    }
    if(!flag)
    cout << "TRUE";
}