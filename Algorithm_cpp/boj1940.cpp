// S4
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n, m; // 재료 n과 재료들의 합 m
	cin >> n >> m;
	vector<int> num(n, 0); // n개의 고유 번호

	// n개의 값들 입력
	for (int i = 0; i < n; i++)
		cin >> num[i];

	sort(num.begin(), num.end()); // 오름차순 정렬

	int ans = 0; // 출력값

	int first_pointer = 0;
	int second_pointer = n - 1;

	// 투 포인터 활용
	while (first_pointer < second_pointer) {
		if (num[first_pointer] + num[second_pointer] < m)
			first_pointer++; // 두 수의 합이 더 작으므로

		else if (num[first_pointer] + num[second_pointer] > m)
			second_pointer--; // 두 수의 합이 더 크므로

		else { // 합과 일치
			ans++;
			first_pointer++;
			second_pointer--;
		}
	}

	cout << ans << "\n";
}