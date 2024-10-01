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

    vector<int> num(n, 0); // n개의 수를 저장할 벡터
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    int ans = 0; // 좋은 수의 개수를 저장할 변수

    // 수들을 오름차순 정렬
    sort(num.begin(), num.end());

    // 각 수에 대해
    for (int i = 0; i < n; i++) {
        long find = num[i]; // 찾고자 하는 수 (두 수의 합이 이 수와 같아야 함)

        int first_pointer = 0;
        int second_pointer = n - 1;

        // 두 포인터를 사용하여 다른 두 수의 합을 찾음
        while (first_pointer < second_pointer) {
            if (num[first_pointer] + num[second_pointer] == find) {
                // 다른 두 수인지 확인 (자기 자신을 포함하면 안 됨)
                if (first_pointer != i && second_pointer != i) {
                    ans++;
                    break; // 좋은 수를 찾으면 더 이상 탐색하지 않음
                }

                else if (first_pointer == i) {
                    first_pointer++; // 첫 번째 포인터가 현재 수와 같으면 이동
                }

                else if (second_pointer == i) {
                    second_pointer--; // 두 번째 포인터가 현재 수와 같으면 이동
                }
            }

            // 두 수의 합이 찾는 수보다 작으면 첫 번째 포인터를 증가
            else if (num[first_pointer] + num[second_pointer] < find)
                first_pointer++;

            // 두 수의 합이 찾는 수보다 크면 두 번째 포인터를 감소
            else if (num[first_pointer] + num[second_pointer] > find)
                second_pointer--;
        }
    }
    cout << ans; // 결과 출력: 좋은 수의 개수
}