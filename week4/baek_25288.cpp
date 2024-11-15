#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    int N, target;
    cin >> N >> target; 

    vector<int> L(N); 

    for (int i = 0; i < N; i++) {
        cin >> L[i]; // 숫자 목록 입력
    }

    int finalNum = 0; 

    // 모든 조합을 탐색하기 위해 비트마스크 사용
    for (int mask = 0; mask < (1 << N); mask++) {
        int maxNum = 0; 

        for (int i = 0; i < N; i++) {
            // i번째 원소 선택되었는지 확인
            if (mask & (1 << i)){
                maxNum += L[i];                
            }
        }

        
        if (target >= maxNum) {
            finalNum = max(maxNum, finalNum); 
        }
    }

    cout << finalNum << endl; // 결과 출력
    return 0;
}
