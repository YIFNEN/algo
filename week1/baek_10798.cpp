#include<iostream>
#include<string>
using namespace std;

int main()
{
    char board [5][15] = {0,};
    for(int i = 0; i < 5 ; i++){
        string s;
        getline(cin, s);
        for(int j = 0; j < s.length(); j++){
            board[i][j] = s[j];
        }
    }
    
    for(int j = 0; j < 15; j++){
        for(int i = 0; i < 5 ; i++){
            if(board[i][j]){
            cout << board[i][j];
            }
        }
    }
    return 0;
}