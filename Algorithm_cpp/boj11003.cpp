// P5
#include <iostream>
#include <deque> // �� Ȱ�� (����� ��� ���� �� ����)
using namespace std;
typedef pair<int, int> Node; // (�ε���, ��) ������ ��� ����

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n, l; // ����, �����̽� ���� + 1��
	cin >> n >> l;

	deque<Node> mydeque;

	for (int i = 0; i < n; i++) {
		int num; // n���� ����
		cin >> num;

		// ���� ������ ū ������ ������ ����(�ּҸ� ���ؾ� ��)
		// �ð����⵵ n ����
		while (mydeque.size() && mydeque.back().first > num)
			mydeque.pop_back();

		mydeque.push_back(Node(num, i));

		// �������� ����� ����
		if (mydeque.front().second <= i - l)
			mydeque.pop_front();

		cout << mydeque.front().first << " ";
	}
}