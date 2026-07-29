#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string text){
    string result = "";
    bool visited[26] = {false};
    int index = 0;
    for(auto c : text){
        char ch = toupper(c);
        if(ch == 'J'){
            ch = 'I';
        }
        if(isalpha(ch)) index = ch - 'A';

        if(!visited[index]){
            result += ch;
            visited[index] = true;
        }
    }
    return result;
}

int main() {
    string s;
    cout << "Enter the text: ";
    getline(cin, s);
    char matrix[5][5];

    string key = removeDuplicates(s);
    cout << key;
    // for(int i = 0; i < 5; i++){
    //     for(int j = 0; j < 5; j++){
            
    //     }
    // }
    return 0;
}