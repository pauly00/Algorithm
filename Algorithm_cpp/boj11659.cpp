// S3
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int numbers, sum_num; // 숫자 개수, 합을 구할 구간 개수
    cin >> numbers >> sum_num;
    long long sum[numbers + 1]; // 구간 합을 저장할 배열 (0으로 초기화)
    sum[0] = 0; // 초기값 설정

    // 1부터 numbers까지 숫자를 입력받아 구간 합 계산
    for (int i = 1; i <= numbers; i++) {
        long long tmp;
        cin >> tmp;
        sum[i] = sum[i - 1] + tmp; // 구간 합 업데이트
    }

    // sum_num개의 구간에 대해 합을 계산
    for (int i = 0; i < sum_num; i++) {
        int start, end;
        cin >> start >> end; // 구간의 시작과 끝 입력
        int ans = sum[end] - sum[start - 1]; // 구간 합 계산
        cout << ans << "\n"; // 결과 출력
    }
}