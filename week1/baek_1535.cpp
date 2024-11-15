#include<iostream>
#include<map>
#include<algorithm>
using namespace std;


int main(){
    int life = 100;
    int joy = 0;
    int friends;
    float H[20]= {0.0,};
    float J[20]= {0.0,};
    float E[20] = {0.0,};
    map<float, int, greater<float>> m;
    string line;

    cin >> friends;
    cin.ignore();  

 
    for (int i = 0; i < friends && i < 20; i++) {
        cin >> H[i];
    }


    for (int i = 0; i < friends && i < 20; i++) {
        cin >> J[i];
         E[i] = J[i]/H[i];
        m.insert({E[i],i});
    }
    
    while(life > 0){

        for(auto it : m){
         
        int n = it.second;
        life -= H[n];
        if (life <= 0) {
                continue; 
            }   
        joy += J[n];
        
        for(int i; i < friends ; i++){
            if( E[i] == it.first){
                life -= H[i];
                if (life <= 0) {
                continue; 
                  }   
                joy += J[i];

            }
        }
        
        }
    }
    cout << joy << endl;
    
    return 0;
}
                   





/*
for(int j = 0; j < 20; j++){


}*/

