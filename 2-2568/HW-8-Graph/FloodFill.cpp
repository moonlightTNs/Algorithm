#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ฟังก์ชัน BFS สำหรับ Flood Fill
int BFS(vector<string>& image, int N, int M, int startX, int startY) {

    char originalColor = image[startX][startY];

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<pair<int,int>> q;

    q.push({startX, startY});
    visited[startX][startY] = true;

    int count = 0;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        count++;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (!visited[nx][ny] && image[nx][ny] == originalColor) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    return count;
}

int main() {

    int N, M;
    cin >> N >> M;

    vector<string> image(N);

    for (int i = 0; i < N; i++) {
        cin >> image[i];
    }

    int X, Y;
    cin >> X >> Y;

    // แปลงเป็น 0-based index
    X--;
    Y--;

    cout << BFS(image, N, M, X, Y) << endl;

    return 0;
}