#include<iostream>
using namespace std;


int main() {
int rect[100][2]={0,};
int board [104][104]={0,};
int i;

cin >> i;

for(int j = 0 ; j < i; j++){
    for(int k = 0; k < 2 ; k++){
        cin >> rect[j][k];}

        for(int b = rect[j][0]; b < rect[j][0] + 10;b++){
        for(int a = rect[j][1]; a < rect[j][1] + 10; a++){
        board[a+1][b+1] = 1;
        }
}

    }


int count = 0;
for (int k = 0; k < 104 ; k++){
    for(int j = 1 ; j < 104; j++){
        if(board[j-1][k] != board[j][k]){
            count++;
        }
    }
    }


for(int j = 0 ; j < 104; j++){
    for(int k = 1; k < 104 ; k++){
        if(board[j][k-1] != board[j][k]){
            count++;
        }
    }
    }

    cout << count << endl;

    return 0;
}