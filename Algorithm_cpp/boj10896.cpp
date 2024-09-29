#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	// N개의 수와 M으로 나누어떨어짐
	int N, M;
	cin >> N >> M;

	long sum = 0;
	long count = 0; // 나누어떨어지는 구간의 개수

	vector<long> remainder_count(M, 0); // 나머지 개수 저장 배열

	// N개의 수 입력받고 합배열에 추가
	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		sum += tmp; // 누적 합 업데이트
		remainder_count[sum % M]++; // 누적합 나머지 계산 후 추가
	}

	// 같은 나머지인 경우의 수 (nC2)
	for (int i = 0; i < M; i++) {
		count += (remainder_count[i] * (remainder_count[i] - 1) / 2);
	}

	cout << remainder_count[0] + count;
}