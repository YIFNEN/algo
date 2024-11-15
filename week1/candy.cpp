#include<iostream>
using namespace std;

int main(){
    const int numCell = 3;
    char board[numCell][numCell] = {};
    int x, y; // 사용자 입력 좌표 저장

    // 보드판 초기화
    for(int i = 0; i < numCell; i++) {
        for(int k = 0; k < numCell; k++){
            board[i][k] = ' ';
        }
    }

    int k = 0; // 차례를 체크하기 위한 변수
    char currentUser;
    
    // 게임 시작
    while(true){
        // 1. 차례 확인 (3명)
        switch(k % 3){
            case 0: {
                cout << "첫번째 유저(X)의 차례입니다";
                currentUser = 'X';
                break;
            }
            case 1: {
                cout << "두번째 유저(O)의 차례입니다";
                currentUser = 'O';
                break;
            }
            case 2: {
                cout << "세번째 유저(Z)의 차례입니다";
                currentUser = 'Z';
                break;
            }
        }

        // 2. 좌표 입력 받기
        cout << "\n(x, y) 좌표를 입력하세요: ";
        cin >> x >> y;

        // 3. 좌표 유효성 체크
        if (x >= numCell || y >= numCell || x < 0 || y < 0){
            cout << x << ", " << y << ": x와 y 둘 중 하나가 칸을 벗어납니다" << endl;
            continue;
        }
        if(board[x][y] != ' '){
            cout << x << ", "<< y << ": 이미 돌이 차있습니다" << endl;
            continue;
        }

        // 4. 입력받은 좌표에 현재 유저의 돌 놓기
        board[x][y] = currentUser;

        // 5. 현재 보드 판 출력
        for (int i = 0; i < numCell; i++){
            cout << "---|---|---" << endl;
            for(int j = 0; j < numCell; j++){
                cout << board[i][j];
                if(j != numCell - 1) {
                    cout << " | ";
                }
            }
            cout << endl;
        }
        cout << "---|---|---" << endl;
        k++;

        // 6. 승리 조건 판별
        bool isWin = false;
        char symbol[3] = {'X', 'O', 'Z'}; // 모든 사용자에 대해 승리 조건 충족 확인

        for (char n : symbol) {
            for(int i = 0; i < numCell; i++){
                if(board[i][0] == n && board[i][1] == n && board[i][2] == n) { // 가로 승리
                    cout<< "user " << n << " 이 승리했습니다!" << endl;
                    isWin = true;
                    break;
                }
                else if(board[0][i] == n && board[1][i] == n && board[2][i] == n) { // 세로 승리
                    cout<< "user " << n << " 이 승리했습니다!" << endl;
                    isWin = true;
                    break;
                }
            }
            if(board[0][0] == n && board[1][1] == n && board[2][2] == n) { // \ 대각선 승리 
                cout<< "user " << n << " 이 승리했습니다!" << endl;
                isWin = true;
                break;
            }
            else if(board[0][2] == n && board[1][1] == n && board[2][0] == n) { // / 대각선 승리
                cout<< "user " << n << " 이 승리했습니다!" << endl;
                isWin = true;
                break;
            }
        }
        if(isWin) {
            break; // 승리 후 종료
        }

        // 7. 다 찼을 경우 종료 판별
        int endcount = 0;
        for (int i = 0; i < numCell; i++){
            for(int j = 0; j < numCell; j++){
                if(board[i][j] != ' '){
                    endcount++;
                }
            }
        }
        if(endcount == numCell * numCell){
            cout << "모든 칸이 다 찼습니다. 종료합니다" << endl;
            break;
        }
    }
    return 0;
}
