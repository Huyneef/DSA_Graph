#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int n, m; 
string vertices[MAXN]; 
int adjMat[MAXN][MAXN]; 
bool visited[MAXN]; 
int parent[MAXN]; 
int dist[MAXN]; 

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    dist[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++) {
            if (adjMat[u][v] > 0 && !visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + adjMat[u][v];
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

int main() {
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> vertices[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adjMat[i][j];
        }
    }
    
    while (m--) {
        string s, u;
        cin >> s >> u;
        int start = -1, end = -1;
        for (int i = 0; i < n; i++) {
            if (vertices[i] == s) {
                start = i;
            }
            if (vertices[i] == u) {
                end = i;
            }
        }
        
        memset(visited, false, sizeof(visited));
        memset(parent, -1, sizeof(parent));
        memset(dist, -1, sizeof(dist));
        
        bfs(start);
        // In káº¿t quáº£
        if (!visited[end]) {
            cout << "-unreachable-" << endl;
            cout << "1 0" << endl;
        } else {
            vector<int> path;
            int cur = end;
            while (cur != start) {
                path.push_back(cur);
                cur = parent[cur];
            }
            path.push_back(start);
            reverse(path.begin(), path.end());
            for (int i = 0; i < path.size(); i++) {
                cout << vertices[path[i]] << " ";
            }
            cout << endl;
            int count = 0, length = dist[end];
            for (int i = 0; i < n; i++) {
                if (visited[i]) {
                    count++;
                }
            }
            cout << count << " " << length << endl;
        }
    }
    return 0;
}