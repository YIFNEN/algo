#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N; // 사람 수 입력

    vector<int> L(N); // 체력 손실 배열
    vector<int> J(N); // 기쁨 배열

    for (int i = 0; i < N; i++) {
        cin >> L[i]; // 체력 손실 입력
    }
    for (int i = 0; i < N; i++) {
        cin >> J[i]; // 기쁨 입력
    }

    int maxJoy = 0; // 최대 기쁨 초기화
    int maxLife = 100; // 세준이의 체력

    // 모든 조합을 탐색하기 위해 비트마스크 사용
    for (int mask = 0; mask < (1 << N); mask++) {
        int currentLife = maxLife; // 현재 체력 초기화
        int currentJoy = 0; // 현재 기쁨 초기화

        for (int i = 0; i < N; i++) {
            // 각 원소를 순회하며 i번째 사람이 선택되었는지 확인
            if (mask & (1 << i)) {
                // 체력 감소 전에 현재 체력이 충분한지 확인
                if (currentLife > L[i]) {
                    currentLife -= L[i]; // 체력 손실
                    currentJoy += J[i]; // 기쁨 증가
                }
            }
        }

        // 현재 체력이 0보다 큰 경우에만 최대 기쁨 갱신
        if (currentLife > 0) {
            maxJoy = max(maxJoy, currentJoy); // 최대 기쁨 갱신
        }
    }

    cout << maxJoy << endl; // 결과 출력
    return 0;
}
