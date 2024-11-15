#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

char decode(char y, char z, int key) {
    int yVal = y - 'a';
    int zVal = z - 'a';
    int real = (yVal + zVal - key + 26) % 26;  // 26을 더해 음수 방지
    return 'a' + real;
}

string seperate(const string& secret, int n) {
    string result;
    int len = secret.size();
    
    for (int i = 0; i < len - 1; i += 2) {  
        char y = secret[i];
        char z = secret[i + 1];
        result += decode(y, z, n);
    }
    
    return result;
}

int main() {
    int key;
    string line, secret;
    vector<string> words;


    cin >> key;
    cin.ignore();  


    getline(cin, line);


    istringstream iss(line);
    while (iss >> secret) {
        words.push_back(secret);
    }

    
    for (size_t i = 0; i < words.size(); ++i) {
        cout << seperate(words[i], key);
        if (i != words.size() - 1) { 
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
