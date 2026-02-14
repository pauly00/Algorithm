// P5
#include <iostream>
#include <deque> // 덱 활용 (양방향 노드 삽입 및 제거)
using namespace std;
typedef pair<int, int> Node; // (인덱스, 값) 형태의 노드 생성

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n, l; // 개수, 슬라이싱 범위 + 1개
	cin >> n >> l;

	deque<Node> mydeque;

	for (int i = 0; i < n; i++) {
		int num; // n개의 값들
		cin >> num;

		// 현재 수보다 큰 값들은 덱에서 제거(최소를 구해야 함)
		// 시간복잡도 n 유지
		while (mydeque.size() && mydeque.back().first > num)
			mydeque.pop_back();

		mydeque.push_back(Node(num, i));

		// 범위에서 벗어나면 제거
		if (mydeque.front().second <= i - l)
			mydeque.pop_front();

		cout << mydeque.front().first << " ";
	}
}