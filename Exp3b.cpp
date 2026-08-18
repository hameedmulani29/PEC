#include <iostream>
#include <vector>
using namespace std;

string encrypt(string message, int columns) {

    while (message.length() % columns != 0) {
        message += 'X';
    }
    int rows = message.length() / columns;

    vector<vector<char>> matrix(rows, vector<char>(columns));
    int index = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = message[index];
            index++;
        }
    }

    string cipherText = "";

    for (int j = 0; j < columns; j++) {
        for (int i = 0; i < rows; i++) {
            cipherText += matrix[i][j];
        }
    }

    return cipherText;
}

string decrypt(string cipherText, int columns) {

    int rows = cipherText.length() / columns;

    vector<vector<char>> matrix(rows, vector<char>(columns));

    int index = 0;

    for (int j = 0; j < columns; j++) {
        for (int i = 0; i < rows; i++) {
            matrix[i][j] = cipherText[index];
            index++;
        }
    }

    string plainText = "";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            plainText += matrix[i][j];
        }
    }
    return plainText;
}


int main() {

    string message;
    int columns;

    cout << "Enter message: ";
    cin >> message;

    cout << "Enter number of columns: ";
    cin >> columns;

    string cipherText = encrypt(message, columns);

    cout << "Encrypted message: " << cipherText << endl;

    string plainText = decrypt(cipherText, columns);

    cout << "Decrypted message: " << plainText << endl;

    return 0;
}