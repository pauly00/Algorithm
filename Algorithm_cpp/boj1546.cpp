// B1
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N; // ���� ����
	cin >> N;

	vector<int> point; // �� ���� �� ����

	long M = 0; // �ִ밪
	// ���� �Է¹ޱ�
	for (int i = 0; i < N; i++) {
		int score = 0; // �Է¹��� ����
		cin >> score;

		point.push_back(score);

		// ���� ���
		if (score > M)
			M = score;
	}

	// ���� ���
	double sum = 0; // ����
	for (int i = 0; i < N; i++) {
		sum += ((double)point[i] / M);
	}

	// ��հ� ���
	double result = sum / N * 100;
	cout << result;
}
