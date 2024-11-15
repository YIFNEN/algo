#include<iostream>
#include<vector>
using namespace std;


int main(){
    int number;
    cin >> number;
    vector<int> arrA(number);
    vector <int>arrB(number);
    vector<int> arrC(number);
    int check = 1;

    for(int i = 0; i < number; i++){
        cin >> arrA[i];
    }


    if(number > 1){
    int n = arrA[1] - arrA[0];

    
    for(int i = 0; i < number - 1 ; i++){
    
        if ((arrA[i+1] - arrA[i])!= n){ // 각 항의 차 검사
            cout << "NO" << endl;
            check = 0;
            break;
        }
    }

    if (check == 1){ //등차수열일 경우 진행
            cout << "YES" << endl;
            for(int i = 0; i < number; i++){

                    arrB[i] = 2*arrA[i];
                    arrC[i] = arrA[i] -arrB[i]; //arrB, arrC 생성 및 출력
                }

            for(auto& i : arrB){
                    cout << i <<' ';
                }
            cout << endl;
            for(auto& i : arrC){
                    cout << i <<' ';
                }
    }
    }


    else{ // 원소가 1개일 경우
        cout << "YES" << endl;
        cout << arrA[0] + 1 << endl;
        cout << -1 << endl << endl;

    }
      
    return 0;
}