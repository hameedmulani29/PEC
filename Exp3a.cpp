#include <bits/stdc++.h>
using namespace std;

string railFenceEncrypt(string s, int rails){
    vector<string> rail(rails);

    int row = 0;
    bool down = true;

    for(char ch : s){
        rail[row] += ch;

        if(row == rails-1){
            down = false;
        }
        else if(row == 0){
            down = true;
        }

        if(down)row++;
        else row--;
    }

    string cipherText = "";
    for(int i = 0; i < rails; i++){
        cipherText += rail[i];
    }
    return cipherText;  
}


string railFenceDecrypt(string cipherText, int rails) {
    vector<int> pattern(cipherText.length());

    int row = 0;
    bool down = true;

    for (int i = 0; i < cipherText.length(); i++) {
        pattern[i] = row;
        if (row == rails - 1) {
            down = false;
        }
        else if (row == 0) {
            down = true;
        }

        if (down) {
            row++;
        }
        else {
            row--;
        }
    }

    vector<int> railCount(rails, 0);
    for (int r : pattern) {
        railCount[r]++;
    }

    vector<string> rail(rails);
    int index = 0;
    for (int r = 0; r < rails; r++) {
        for (int j = 0; j < railCount[r]; j++) {
            rail[r] += cipherText[index];
            index++;
        }
    }


    vector<int> railIndex(rails, 0);
    string plainText = "";
    for (int i = 0; i < cipherText.length(); i++) {
        int r = pattern[i];
        plainText += rail[r][railIndex[r]];
        railIndex[r]++;
    }
    return plainText;
}

int main() {
    string message;
    int rails;

    cout << "Enter message: ";
    cin >> message;

    cout << "Enter rails: ";
    cin >> rails;

    string cipherText = railFenceEncrypt(message, rails);
    cout << "Encrypted Message: " << cipherText << endl;

    string plainText = railFenceDecrypt(cipherText, rails);
    cout << "Decrypted Message: " << plainText << endl;
    return 0;
}