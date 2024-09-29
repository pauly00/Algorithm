#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N, M; // 배열수, 구해야 하는 연산개수
	cin >> N >> M;

	// 초기 저장 배열(초기값 0)
	vector<vector<int>> inputNum(N + 1, vector<int>(N + 1, 0));
	// 구간 합 저장 배열
	vector<vector<int>> calcNum(N + 1, vector<int>(N + 1, 0));

	// 배열 저장 및 구간 합 계산
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> inputNum[i][j]; // 배열 저장
			// 구간 합 계산
			calcNum[i][j] = calcNum[i][j - 1] + calcNum[i - 1][j] - calcNum[i - 1][j - 1] + inputNum[i][j];
		}
	}

	// 문제의 조건 입력 및 계산
	for (int i = 1; i <= M; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		// 전체 구간합에서 x1-1, y1-1의 범위에 있는 구간을 빼고
		// 중복으로 뺀 앞부분을 더한다
		int result = calcNum[x2][y2] - calcNum[x1 - 1][y2] - calcNum[x2][y1 - 1] + calcNum[x1 - 1][y1 - 1];
		cout << result << "\n";
	}
}