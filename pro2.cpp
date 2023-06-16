#include <bits/stdc++.h>
using namespace std;



int main() {
    map<string, set<string>> adj_list;
    int e, n;
    cin >> e >> n;
    string x, y;
    for (int i = 0; i < e; i++) {
        cin >> x >> y;
        adj_list[y];
        adj_list[x].insert(y);
    }
    int op; 
    for(int i = 0; i < n ; i++) {
        cin >> op;
        if(op == 1) {
            cin >> x >> y;
            set<string> p = adj_list[x];
            if(p.find(y) == p.end()) cout << "FALSE" << endl;
            else cout << "TRUE" << endl;
        }
        else if(op == 2) {
            cin >> x;
            set<string> p = adj_list[x];
            cout << p.size() << endl;
        }
    }

    

    return 0;
}