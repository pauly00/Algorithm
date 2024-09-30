// S5
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n; // ��ǥ ��
	cin >> n;

	int start = 1; // ���� �ε���
	int end = 1; // �� �ε���

	int sum = 1; // �� ���ϱ� (1���� ����)
	int ans = 1; // ��°�(������ �� n�� �ڵ��߰�)

	// �� ������ �̵�
	while (end != n) {
		// ����
		if (sum == n) {
			ans++;
			end++; // ������ �� ����
			sum += end; // �� ����
		}

		// ���� �ʰ�
		else if (sum > n) {
			sum -= start; // ù��° �ε��� ����, �� ����
			start++; // ù��° �� ����
		}

		// ���亸�� ����
		else if (sum < n) {
			end++; // ������ �� �̵� ��
			sum += end; // �� ����
		}
	}

	cout << ans;
}