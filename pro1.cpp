
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

// ###INSERT CODE HERE -
class Graph
{
private:
    vector<vector<int>> matrix;
    vector<string> names;
    map<string, int> v_index;

public:
    void nhap(int v, int e)
    {
        matrix = vector<vector<int>>(v, vector<int>(v, 0));
        names = vector<string>(v, "");
        for (int i = 0; i < v; i++)
        {
            string s;
            cin >> s;
            names[i] = s;
            v_index[s] = i;
        }
        for (int i = 0; i < e; i++)
        {
            string x, y;
            cin >> x >> y;
            int u_index = v_index[x];
            int y_index = v_index[y];
            matrix[u_index][y_index] = 1;
        }
    }
    void myProcess(int n)
    {
        for (int i = 0; i < n; i++)
        {
            int op;
            cin >> op;

            if (op == 1)
            {
                string u, v;
                cin >> u >> v;
                int u_index = v_index[u];
                int y_index = v_index[v];

                if (matrix[u_index][y_index] == 1)
                    cout << "TRUE" << endl;
                else
                    cout << "FALSE" << endl;
            }
            else if (op == 2)
            {
                string u;
                cin >> u;
                int u_index = v_index[u];

                vector<string> neighbors;
                for (int j = 0; j < names.size(); j++)
                {
                    if (matrix[u_index][j] == 1)
                        neighbors.push_back(names[j]);
                }
                if (neighbors.size() == 0)
                    cout << "NONE" << endl;
                else
                {
                    for (int j = 0; j < neighbors.size(); j++)
                        cout << neighbors[j] << " ";
                    cout << endl;
                }
            }
        }
    }
};
int main()
{
    Graph G;
    int v, e, n;
    cin >> v >> e >> n;
    G.nhap(v, e);
    G.myProcess(n);
    return 0;
}