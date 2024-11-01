// S4
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n, m; // n은 재료의 개수, m은 합쳐야 하는 값
    cin >> n >> m;
    vector<int> num(n, 0); // n개의 재료 번호

    // n개의 재료 입력
    for (int i = 0; i < n; i++)
        cin >> num[i];

    sort(num.begin(), num.end()); // 재료 번호를 오름차순 정렬

    int ans = 0; // 찾은 쌍의 개수

    int first_pointer = 0;
    int second_pointer = n - 1;

    // 투 포인터 알고리즘을 사용하여 쌍을 찾음
    while (first_pointer < second_pointer) {
        if (num[first_pointer] + num[second_pointer] < m)
            first_pointer++; // 합이 m보다 작으므로 첫 번째 포인터 증가

        else if (num[first_pointer] + num[second_pointer] > m)
            second_pointer--; // 합이 m보다 크므로 두 번째 포인터 감소

        else { // 합이 m과 일치하는 경우
            ans++;
            first_pointer++;
            second_pointer--;
        }
    }

    cout << ans << "\n"; // 결과 출력: m을 만드는 쌍의 개수
}