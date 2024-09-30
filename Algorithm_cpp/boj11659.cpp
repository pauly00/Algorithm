// S3
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int numbers, sum_num; // ��, ���� ����
	cin >> numbers >> sum_num;
	long long sum[numbers + 1]; // �հ� ���� �迭(0���� �ʱ�ȭ)
	sum[0] = 0; // �ʱ� �迭 0

	// i=1���� �ִ� 100001������ ������ �����
	for (int i = 1; i <= numbers; i++) {
		long long tmp;
		cin >> tmp;
		sum[i] = sum[i - 1] + tmp; // ���� �� ���ϱ�
	}


	for (int i = 0; i < sum_num; i++) {
		int start, end;
		cin >> start >> end; // ���� �� ���� �Է�
		int ans = sum[end] - sum[start - 1];
		cout << ans << "\n";
	}
}