// S2
#include <iostream>
using namespace std;

int checkArr[4]; // ������ �ּ� �䱸 ���� ���� �迭
int myArr[4]; // ���� �˻� ���� �κ� ���ڿ����� ���� ����
int checkSecret = 0; // ���� ���� ���� Ȯ�� ����
void Add(char c); // ���� ���� ���� ó��
void Remove(char c); // ������ ���� ó��

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int s, p; // ���ڿ� ����, ��й�ȣ
	cin >> s >> p;

	int ans = 0; // ������ �����ϴ� ����
	string a; // DNA ���ڿ�
	cin >> a;

	// �� ������ �ּ� �䱸 ���� �Է�
	for (int i = 0; i < 4; i++) {
		cin >> checkArr[i];
		if (checkArr[i] == 0) // 0�̸� �ٷ� ����
			checkSecret++;
	}

	// ù ��° �κ� ���ڿ��� ���� ó��
	for (int i = 0; i < p; i++)
		Add(a[i]);
	
	// ó�� ���ڿ� ���� ��
	if (checkSecret == 4)
		ans++;
	
	// �� ��° �κ� ���ڿ����� ������ �����̽� ������ ��� Ȱ��
	for (int i = p; i < s; i++) {
		int j = i - p; // �����쿡�� ������ ������ �ε���
		Add(a[i]); // ���� ������ ���� �߰�
		Remove(a[j]); // ���������� ���� �߰�

		if (checkSecret == 4) // 4���� ���ڰ� ��� ���� ���� ��
			ans++;
	}
	cout << ans << "\n";
}

// ���� ���� ���� ó��
void Add(char c) {
	switch (c) {
	case 'A':
		myArr[0]++;
		if (myArr[0] == checkArr[0]) // �ּ� �䱸 ���� ���� ��
			checkSecret++;
		break;

	case 'C':
		myArr[1]++;
		if (myArr[1] == checkArr[1])
			checkSecret++;
		break;

	case 'G':
		myArr[2]++;
		if (myArr[2] == checkArr[2])
			checkSecret++;
		break;

	case 'T':
		myArr[3]++;
		if (myArr[3] == checkArr[3])
			checkSecret++;
		break;
	}
}

// ������ ���� ó��
void Remove(char c) {
	switch (c) {
	case 'A':
		if (myArr[0] == checkArr[0]) // �ּ� �䱸 ���� ���� ��
			checkSecret--; // ������� ������
		myArr[0]--;
		break;

	case 'C':
		if (myArr[1] == checkArr[1])
			checkSecret--;
		myArr[1]--;
		break;

	case 'G':
		if (myArr[2] == checkArr[2])
			checkSecret--;
		myArr[2]--;
		break;

	case 'T':
		if (myArr[3] == checkArr[3])
			checkSecret--;
		myArr[3]--;
		break;
	}
}