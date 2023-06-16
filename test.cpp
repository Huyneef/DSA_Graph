#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int n, m; // số đỉnh và số thao tác tìm kiếm
string vertices[MAXN]; // danh sách đỉnh
int adjMat[MAXN][MAXN]; // ma trận kề của đồ thị
bool visited[MAXN]; // danh sách các đỉnh đã được ghé thăm
int parent[MAXN]; // danh sách đỉnh cha của các đỉnh trong cây tìm kiếm
int dist[MAXN]; // khoảng cách từ đỉnh bắt đầu đến các đỉnh khác

void dfs(int start, int end) {
    stack<int> st;
    st.push(start);
    visited[start] = true;
    dist[start] = 0;
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        for (int v = 0; v < n; v++) {
            if (adjMat[u][v] > 0 && !visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + adjMat[u][v];
                parent[v] = u;
                st.push(v);
            }
        }
    }
}

int main() {
    // Nhập dữ liệu
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> vertices[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adjMat[i][j];
        }
    }
    // Xử lí các yêu cầu tìm kiếm
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
        // Khởi tạo các biến cho mỗi yêu cầu tìm kiếm
        memset(visited, false, sizeof(visited));
        memset(parent, -1, sizeof(parent));
        memset(dist, -1, sizeof(dist));
        // Tìm kiếm theo chiều sâu
        dfs(start, end);
        // In kết quả
        if (!visited[end]) {
            cout << "-unreachable-" << endl;
            cout << "0 0" << endl;
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
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (visited[i]) {
                    count++;
                }
            }
            cout << count << " " << dist[end] << endl;
        }
    }
    return 0;
}