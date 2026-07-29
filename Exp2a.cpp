#include <bits/stdc++.h>
using namespace std;

string encrypt(string s, int shift){
    string result = "";
    for(char c : s){
        if(isupper(c)){
            int num = c - 'A';
            int newChar = (num + shift)%26;
            char ch = newChar + 'A';
            result += ch;
        }
        else if(islower(c)){
            int num = c - 'a';
            int newChar = (num + shift)%26;
            char ch = newChar + 'a';
            result += ch;
        }
        else{
            result += c;
        }
    }
    return result;
}

string decrypt(string s, int shift){
    string result = "";
    for(char c : s){
        if(isupper(c)){
            int num = c - 'A'; // converted 0-25;
            int newChar = (num - shift + 26) % 26;
            char ch = newChar + 'A';
            result += ch;
        }else if(islower(c)){
            int num = c - 'a';
            int newChar = (num - shift + 26)%26;
            char ch = newChar + 'a';
            result += ch;
        }else{
            result += c;
        }
    }
    return result;
}

int main() {
    string text;
    int shift = 0;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the shift value: ";
    cin >> shift;

    string encryption = encrypt(text, shift);
    cout << "Encryption : " << encryption << endl;
    string decryption = decrypt(encryption, shift);
    cout << "Decryption : " << decryption << endl;
    
    return 0;
}