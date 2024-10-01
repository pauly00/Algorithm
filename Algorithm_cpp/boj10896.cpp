// G3
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    // N개의 수와 M으로 나눈 나머지가 같은 구간 수
    int N, M;
    cin >> N >> M;

    long sum = 0;
    long count = 0; // 나머지가 같은 구간의 개수

    vector<long> remainder_count(M, 0); // 나머지별 개수를 저장하는 벡터

    // N개의 수를 입력받고 누적합을 계산하며 나머지 개수 카운트
    for (int i = 1; i <= N; i++) {
        int tmp;
        cin >> tmp;
        sum += tmp; // 누적 합 업데이트
        remainder_count[sum % M]++; // 누적 합을 M으로 나눈 나머지를 카운트
    }

    // 나머지가 같은 구간의 수를 계산 (조합 공식 nC2 사용)
    for (int i = 0; i < M; i++) {
        count += (remainder_count[i] * (remainder_count[i] - 1) / 2);
    }

    // 나머지가 0인 구간도 더해서 결과 출력
    cout << remainder_count[0] + count;
}