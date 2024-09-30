// G3
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	// N���� ���� M���� ���������
	int N, M;
	cin >> N >> M;

	long sum = 0;
	long count = 0; // ����������� ������ ����

	vector<long> remainder_count(M, 0); // ������ ���� ���� �迭

	// N���� �� �Է¹ް� �չ迭�� �߰�
	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		sum += tmp; // ���� �� ������Ʈ
		remainder_count[sum % M]++; // ������ ������ ��� �� �߰�
	}

	// ���� �������� ����� �� (nC2)
	for (int i = 0; i < M; i++) {
		count += (remainder_count[i] * (remainder_count[i] - 1) / 2);
	}

	cout << remainder_count[0] + count;
}