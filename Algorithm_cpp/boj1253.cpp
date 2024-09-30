// G4
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	
	int n; // 수의 개수
	cin >> n;

	vector<int> num(n, 0); // n개의 수들
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	
	int ans = 0; // 출력값

	// 오름차순 정렬 후
	sort(num.begin(), num.end());

	// 기준점을 넣고
	for (int i = 0; i < n; i++) {
		long find = num[i]; // 찾고자 하는 수 (10억 + 10억 > 21억 가능)

		int first_pointer = 0;
		int second_pointer = n - 1;
	
		// 그 앞번호부터 가장 작은 번호까지 투 포인터 활용
		while (first_pointer < second_pointer) {
			if (num[first_pointer] + num[second_pointer] == find) {
				// 다른 수들의 합인지 체크해야 됨(겹침 방지)
				if (first_pointer != i && second_pointer != i) {
					ans++;
					break;
				}

				else if (first_pointer == i) {
					first_pointer++; // 첫번째 포인터 기준점 증가
				}

				else if (second_pointer == i) {
					second_pointer--; // 두번째 포인터 기준점 감소
				}
			} // 괄호 위치 조심!!!

			else if (num[first_pointer] + num[second_pointer] < find)
				first_pointer++; // 합이 더 클 때(증가)

			else if (num[first_pointer] + num[second_pointer] > find)
				second_pointer--; // 합이 더 작을 때(감소)
		}
	}
	cout << ans;

}