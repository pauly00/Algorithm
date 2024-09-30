// S4
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n, m; // ��� n�� ������ �� m
	cin >> n >> m;
	vector<int> num(n, 0); // n���� ���� ��ȣ

	// n���� ���� �Է�
	for (int i = 0; i < n; i++)
		cin >> num[i];

	sort(num.begin(), num.end()); // �������� ����

	int ans = 0; // ��°�

	int first_pointer = 0;
	int second_pointer = n - 1;

	// �� ������ Ȱ��
	while (first_pointer < second_pointer) {
		if (num[first_pointer] + num[second_pointer] < m)
			first_pointer++; // �� ���� ���� �� �����Ƿ�

		else if (num[first_pointer] + num[second_pointer] > m)
			second_pointer--; // �� ���� ���� �� ũ�Ƿ�

		else { // �հ� ��ġ
			ans++;
			first_pointer++;
			second_pointer--;
		}
	}

	cout << ans << "\n";
}