// S5
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n; // 목표 값
	cin >> n;

	int start = 1; // 시작 인덱스
	int end = 1; // 끝 인덱스

	int sum = 1; // 합 구하기 (1부터 시작)
	int ans = 1; // 출력값(마지막 값 n은 자동추가)

	// 투 포인터 이동
	while (end != n) {
		// 정답
		if (sum == n) {
			ans++;
			end++; // 마지막 값 증가
			sum += end; // 합 갱신
		}

		// 정답 초과
		else if (sum > n) {
			sum -= start; // 첫번째 인덱스 증가, 합 제거
			start++; // 첫번째 값 변경
		}

		// 정답보다 부족
		else if (sum < n) {
			end++; // 마지막 값 이동 후
			sum += end; // 합 갱신
		}
	}

	cout << ans;
}