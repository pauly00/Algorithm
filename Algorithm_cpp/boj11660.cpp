// S1
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N, M; // �迭��, ���ؾ� �ϴ� ���갳��
	cin >> N >> M;

	// �ʱ� ���� �迭(�ʱⰪ 0)
	vector<vector<int>> inputNum(N + 1, vector<int>(N + 1, 0));
	// ���� �� ���� �迭
	vector<vector<int>> calcNum(N + 1, vector<int>(N + 1, 0));

	// �迭 ���� �� ���� �� ���
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> inputNum[i][j]; // �迭 ����
			// ���� �� ���
			calcNum[i][j] = calcNum[i][j - 1] + calcNum[i - 1][j] - calcNum[i - 1][j - 1] + inputNum[i][j];
		}
	}

	// ������ ���� �Է� �� ���
	for (int i = 1; i <= M; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		// ��ü �����տ��� x1-1, y1-1�� ������ �ִ� ������ ����
		// �ߺ����� �� �պκ��� ���Ѵ�
		int result = calcNum[x2][y2] - calcNum[x1 - 1][y2] - calcNum[x2][y1 - 1] + calcNum[x1 - 1][y1 - 1];
		cout << result << "\n";
	}
}