#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


int main(){
    int len, plusnum;
    vector<int> numbers;
    vector<int> gaps;
    int sum = 0;

    cin >> len >> plusnum;
    
    for (int i = 0; i < len; i++) { 
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }
    
    for(int i = 0; i < len/2; i++){
        int gap = abs(numbers[i] - numbers[len-i-1]);
        gaps.push_back(gap);
    }

    
    for(int i = 0; i < len /2; i++){
        int v = gaps[i] % plusnum;
        int w = gaps[i] / plusnum;

        sum += w + min((v),(plusnum - v+ 1));
    }
    
    cout << sum << endl;


    return 0;
}