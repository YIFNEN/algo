#include<iostream>
#include<vector>
using namespace std;


int main(){

int weight [] = {1,2,3,4,5};
int number [5] = {0,};


for(int i = 0; i < 5; i++){
    cin >> number[i];
}

int bag = number[4];

while(number[3] > 0 && number[0] > 0)// weight 4, 1 짝지음
{
    bag++;
    --number[3];
    --number[0];
}
while(number[1] > 0 && number[2] > 0) // weight 3,2 짝지음 
{
    bag++;
    --number[1];
    --number[2];
}
while(number[2] > 0 && number[0] > 0) // weight 3,1 짝지음 음수 되더라도 감소
{
    bag++;
    --number[2];
    number[0] = number[0] - 2;
    
}

while(number[1] > 0) // weight 2와 1 남을 경우 소모
{    
    bag++;
   if(number[1] > 1 && number[0] > 0) // 2 2개,1 한개 먼저 소모
   { number[1] -= 2;
     --number[0];
   }
   else if (number[1] == 1 && number[0] > 0){ // 2가 한개 남을 경우 2 한개 1세개 소모
    --number[1];
    number[0] -= 3;
   }
   else{ //1이 안남을 경우 2 2개 소모
    number[1] -= 2;

   }
}


bag= bag + number[3]+number[2] + number[1]/2 + number[0]/5;

if( number[0] % 5 > 0 ) { //1이 5개 이하 남을 경우 증가
    bag++;
}

cout << bag << endl;

    return 0;
}