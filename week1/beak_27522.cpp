#include<iostream>
#include<map>
#include<string>


using namespace std;
int main(){
     map<string, char> timeMap; //string이어도 정렬이 된다고 함.
     int score[] = {10, 8, 6, 5, 4, 3 ,2 ,1};
     for (int i = 0; i < 8; i++) {
        string line;

        getline(cin, line); // 한 줄 입력받기

        // 시간 부분과 팀 정보를 분리
        string time = line.substr(0, line.size() - 2); // 마지막 두 글자(B 또는 R) 제외한 부분을 잘라냄
        char team = line.back(); // 문자열의 마지막 문자를 반환

        // map에 저장
        timeMap[time] = team;
    }
    int rscore = 0; 
    int bscore = 0;
    int i = 0;
   
    for(auto it: timeMap){
        switch(it.second){
            case 'R':{
                rscore+=score[i];
                i+=1;
                break;
            }



            case 'B':{
                bscore+=score[i];
                i+=1;
                break;
            }
        }


    }

    if (rscore > bscore){
        cout << "Red" << endl;
    }
    else if(rscore < bscore){
        cout <<"Blue" << endl;
    }





    return 0;
}