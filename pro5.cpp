#include <bits/stdc++.h>

using namespace std;

int main() {
    map<string, map<string, int>> adj_list;
    int e, n;
    cin >> e >> n;

   
    string x, y;
    int w;
    for (int i = 0; i < e; i++) {
        cin >> x >> y >> w;
        adj_list[x][y] = w;
    }

    
    for (int i = 0; i <n; i++) {
        vector<string> walk;
        string check;
        while (cin >> check && check != ".") {
            walk.push_back(check);
        }

        bool isHave = true;
        int path_length = 0;
        
        for (int j = 0; j < walk.size() - 1; j++) {
            string y = walk[j+1];
            string x = walk[j];
            
            if (adj_list[x].count(y) != 0) { 
                
                path_length += adj_list[x][y];
            }
            else {
                isHave = false;
                break;
            }
        }

        
        if (isHave) {
            cout << path_length << endl;
        } else {
            cout << "FALSE" << endl;
        }
    }

    return 0;
}