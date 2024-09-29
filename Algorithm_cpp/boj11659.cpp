#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int numbers, sum_num; // 수, 합의 개수
	cin >> numbers >> sum_num;
	long long sum[numbers + 1]; // 합계 저장 배열(0으로 초기화)
	sum[0] = 0; // 초기 배열 0

	// i=1부터 최대 100001까지의 범위에 저장됨
	for (int i = 1; i <= numbers; i++) {
		long long tmp;
		cin >> tmp;
		sum[i] = sum[i - 1] + tmp; // 구간 합 구하기
	}


	for (int i = 0; i < sum_num; i++) {
		int start, end;
		cin >> start >> end; // 구간 합 범위 입력
		int ans = sum[end] - sum[start - 1];
		cout << ans << "\n";
	}
}