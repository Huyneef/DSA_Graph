#include <bits/stdc++.h>
using namespace std;

int main() {
    int v, e;
    cin >> v >> e;
    vector<string> names;
    map<string, int> v_index;
    names = vector<string>(v, "");
    for (int i = 0; i < v; i++) {
        string s;
        cin >> s;
        names[i] = s;
        v_index[s] = i;
    }

    vector<int> degree(v, 0);
    for (int i = 0; i < e; i++) {
        string x, y;
        cin >> x >> y;
        degree[v_index[x]]++;
        degree[v_index[y]]++;
    }

    for (int i = 0; i < v; i++) {
        cout << degree[i] << " ";
    }
    cout << endl;

    return 0;
}