// P2
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

    for (auto& x : p) cin >> x;

    long long grundy = 0;      // nim-sum
    bool allOne = true;        // 모든 더미가 1개인지

    for (auto x : p) {
        grundy ^= x;
        if (x != 1) allOne = false;
    }

    if (allOne) {
        // 모든 더미가 1개라면: 개수 짝수 -> 선공 승, 홀수 -> 후공 승
        cout << (N % 2 == 0 ? "koosaga" : "cubelover");
    }
    else {
        // 그 외에는 일반 님 게임과 동일: xor != 0 -> 선공 승
        cout << (grundy != 0 ? "koosaga" : "cubelover");
    }
}