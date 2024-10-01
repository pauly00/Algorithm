// S1
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N, M; // 배열 크기 N, 구해야 하는 부분 합의 개수 M
    cin >> N >> M;

    // 초기 입력 배열 (초기값 0으로 설정)
    vector<vector<int>> inputNum(N + 1, vector<int>(N + 1, 0));
    // 구간 합을 저장할 배열
    vector<vector<int>> calcNum(N + 1, vector<int>(N + 1, 0));

    // 배열 입력 및 구간 합 계산
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> inputNum[i][j]; // 배열 입력
            // 구간 합 계산 (i, j까지의 합)
            calcNum[i][j] = calcNum[i][j - 1] + calcNum[i - 1][j] - calcNum[i - 1][j - 1] + inputNum[i][j];
        }
    }

    // M개의 쿼리 입력 및 처리
    for (int i = 1; i <= M; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // 구간 합 계산: (x1, y1)에서 (x2, y2)까지의 합
        // 전체 합에서 x1-1, y1-1을 제외하고 중복 부분을 더함
        int result = calcNum[x2][y2] - calcNum[x1 - 1][y2] - calcNum[x2][y1 - 1] + calcNum[x1 - 1][y1 - 1];
        cout << result << "\n";
    }
}