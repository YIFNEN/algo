#include<iostream>
#include<map>
#include <vector>
#include<string>


using namespace std;
int Factorial(int A);

int main(){
    int count = 0;
    int input;
	cin >> input;

    vector<string> strings(input); // n개의 문자열을 저장할 벡터 생성

    // 문자열 입력받기
    cin.ignore(); // 버퍼에 남아있는 '\n'을 제거


    for (int i = 0; i < input; i++) {
        getline(cin, strings[i]); // 각 문자열 입력
    }

    for(int j = 0; j < input ; j++){
        bool isPal = true;

        for (int i = 0; i < strings[j].length() / 2; ++i)
        {
            if (strings[j][i] != strings[j][strings[j].length() - 1 - i]){
                isPal = false;
                break;
            }
        }

        if (isPal) {
            count++; // 회문일 경우 count 증가
        }

    }
	cout << count * (count - 1) << endl;
    return 0;
}

