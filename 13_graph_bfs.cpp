#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    // Đọc dữ liệu từ input
    int v, n;
    cin >> v >> n;

    vector<string> vertices(v);
    for (int i = 0; i < v; i++) {
        cin >> vertices[i];
    }

    vector<vector<int>> graph(v, vector<int>(v));
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cin >> graph[i][j];
        }
    }

    // Duyệt tất cả các yêu cầu tìm kiếm
    for (int i = 0; i < n; i++) {
        string s, u;
        cin >> s >> u;

        // Tìm chỉ số của đỉnh bắt đầu và đỉnh kết thúc
        int start = -1, end = -1;
        for (int j = 0; j < v; j++) {
            if (vertices[j] == s) {
                start = j;
            }
            if (vertices[j] == u) {
                end = j;
            }
        }

        // Khởi tạo các biến cần thiết cho thuật toán BFS
        vector<int> dist(v, INF);
        vector<int> parent(v, -1);
        vector<bool> visited(v, false);
        queue<int> q;

        // Bắt đầu từ đỉnh bắt đầu, đánh dấu là đã khám phá và đưa vào hàng đợi
        q.push(start);
        visited[start] = true;
        dist[start] = 0;

        // Duyệt BFS
        int num_expanded = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            num_expanded++;

            // Nếu tìm thấy đỉnh kết thúc, dừng thuật toán
            if (cur == end) {
                break;
            }

            // Duyệt qua tất cả các đỉnh kề với đỉnh hiện tại
            for (int j = 0; j < v; j++) {
                if (graph[cur][j] > 0 && !visited[j]) {
                    visited[j] = true;
                    dist[j] = dist[cur] + graph[cur][j];
                    parent[j] = cur;
                    q.push(j);
                }
            }
        }

        // In kết quả
        if (dist[end] == INF) {
            cout << "-unreachable-" << endl;
            cout << "0 0" << endl;
        } else {
            vector<string> path;
            int cur = end;
            while (cur !=start) {
                path.push_back(vertices[cur]);
                cur = parent[cur];
            }
            path.push_back(vertices[start]);
            reverse(path.begin(), path.end());
            for (string vertex : path) {
                cout << vertex << " ";
            }
            cout << endl;
            cout << num_expanded << " " << dist[end] << endl;
        }
    }

    return 0;
}