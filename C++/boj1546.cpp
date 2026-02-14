// B1
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N; // 과목의 개수
    cin >> N;

    vector<int> point; // 각 과목의 점수를 저장할 벡터

    long M = 0; // 최대값 저장 변수
    // 점수 입력받기
    for (int i = 0; i < N; i++) {
        int score = 0; // 입력받은 점수
        cin >> score;

        point.push_back(score); // 점수를 벡터에 추가

        // 최대값 계산
        if (score > M)
            M = score;
    }

    // 점수 계산
    double sum = 0; // 점수의 합계
    for (int i = 0; i < N; i++) {
        sum += ((double)point[i] / M); // 각 점수를 최대값으로 나누어 합산
    }

    // 최종 결과 계산
    double result = sum / N * 100;
    cout << result; // 결과 출력
}