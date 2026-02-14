// S5
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n; // 목표 값 (n)
    cin >> n;

    int start = 1; // 시작 포인터
    int end = 1; // 끝 포인터

    int sum = 1; // 연속된 숫자의 합 (1부터 시작)
    int ans = 1; // 경우의 수 (1 하나만으로 n을 만드는 경우 포함)

    // 투 포인터를 사용하여 연속된 숫자의 합을 구하는 방식
    while (end != n) {
        // 합이 n과 같은 경우
        if (sum == n) {
            ans++;
            end++; // 끝 포인터 이동
            sum += end; // 끝 포인터 값 더하기
        }

        // 합이 n보다 큰 경우
        else if (sum > n) {
            sum -= start; // 시작 포인터 값을 빼서 합 줄이기
            start++; // 시작 포인터 이동
        }

        // 합이 n보다 작은 경우
        else if (sum < n) {
            end++; // 끝 포인터 이동
            sum += end; // 끝 포인터 값 더하기
        }
    }

    cout << ans; // 연속된 숫자로 n을 만드는 경우의 수 출력
}