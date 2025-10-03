// P4
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    long long N; // 더미 개수
    cin >> N;

    vector<long long> p(N);

    for (long long& i : p)
        cin >> i; // 벡터 p의 원문 입력

    long long grundy = 0; // 그런디 수

    for (long long& i : p) {
        grundy ^= i; // XOR
    }

    if (grundy != 0)
        cout << "koosaga";
    else
        cout << "cubelover";

}