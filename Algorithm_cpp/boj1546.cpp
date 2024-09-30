// B1
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N; // 과목 개수
	cin >> N;

	vector<int> point; // 각 과목 별 점수

	long M = 0; // 최대값
	// 점수 입력받기
	for (int i = 0; i < N; i++) {
		int score = 0; // 입력받을 점수
		cin >> score;

		point.push_back(score);

		// 총점 계산
		if (score > M)
			M = score;
	}

	// 총점 계산
	double sum = 0; // 총점
	for (int i = 0; i < N; i++) {
		sum += ((double)point[i] / M);
	}

	// 평균값 계산
	double result = sum / N * 100;
	cout << result;
}
