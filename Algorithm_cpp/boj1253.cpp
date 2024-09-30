// G4
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	
	int n; // ���� ����
	cin >> n;

	vector<int> num(n, 0); // n���� ����
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	
	int ans = 0; // ��°�

	// �������� ���� ��
	sort(num.begin(), num.end());

	// �������� �ְ�
	for (int i = 0; i < n; i++) {
		long find = num[i]; // ã���� �ϴ� �� (10�� + 10�� > 21�� ����)

		int first_pointer = 0;
		int second_pointer = n - 1;
	
		// �� �չ�ȣ���� ���� ���� ��ȣ���� �� ������ Ȱ��
		while (first_pointer < second_pointer) {
			if (num[first_pointer] + num[second_pointer] == find) {
				// �ٸ� ������ ������ üũ�ؾ� ��(��ħ ����)
				if (first_pointer != i && second_pointer != i) {
					ans++;
					break;
				}

				else if (first_pointer == i) {
					first_pointer++; // ù��° ������ ������ ����
				}

				else if (second_pointer == i) {
					second_pointer--; // �ι�° ������ ������ ����
				}
			} // ��ȣ ��ġ ����!!!

			else if (num[first_pointer] + num[second_pointer] < find)
				first_pointer++; // ���� �� Ŭ ��(����)

			else if (num[first_pointer] + num[second_pointer] > find)
				second_pointer--; // ���� �� ���� ��(����)
		}
	}
	cout << ans;

}