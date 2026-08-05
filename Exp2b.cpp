#include <bits/stdc++.h>
using namespace std;

// Remove duplicate letters from key
string removeDuplicates(string text) {
    string result = "";
    bool visited[26] = {false};

    for (char c : text) {
        char ch = toupper(c);

        if (!isalpha(ch))
            continue;

        if (ch == 'J')
            ch = 'I';

        int index = ch - 'A';

        if (!visited[index]) {
            visited[index] = true;
            result += ch;
        }
    }

    return result;
}

// Prepare plaintext
string preparePlaintext(string text) {
    string temp = "";

    // Remove spaces and convert to uppercase
    for (char c : text) {
        if (isalpha(c)) {
            char ch = toupper(c);

            if (ch == 'J')
                ch = 'I';

            temp += ch;
        }
    }

    string result = "";

    for (int i = 0; i < temp.length(); i++) {

        result += temp[i];

        if (i + 1 < temp.length() && temp[i] == temp[i + 1]) {
            result += 'X';
        }
    }

    if (result.length() % 2 != 0)
        result += 'X';

    return result;
}

// Find position of character in matrix
void findPosition(char matrix[5][5], char ch, int &row, int &col) {

    if (ch == 'J')
        ch = 'I';

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == ch) {
                row = i;
                col = j;
                return;
            }
        }
    }
}

// Encrypt
string encrypt(string text, char matrix[5][5]) {

    string cipher = "";

    for (int i = 0; i < text.length(); i += 2) {

        char a = text[i];
        char b = text[i + 1];

        int r1, c1, r2, c2;

        findPosition(matrix, a, r1, c1);
        findPosition(matrix, b, r2, c2);

        // Same row
        if (r1 == r2) {
            cipher += matrix[r1][(c1 + 1) % 5];
            cipher += matrix[r2][(c2 + 1) % 5];
        }

        // Same column
        else if (c1 == c2) {
            cipher += matrix[(r1 + 1) % 5][c1];
            cipher += matrix[(r2 + 1) % 5][c2];
        }

        // Rectangle
        else {
            cipher += matrix[r1][c2];
            cipher += matrix[r2][c1];
        }
    }

    return cipher;
}

int main() {

    string keyInput, plainText;

    cout << "Enter Key: ";
    getline(cin, keyInput);

    cout << "Enter Plaintext: ";
    getline(cin, plainText);

    char matrix[5][5];

    // Remove duplicates
    string key = removeDuplicates(keyInput);

    // Add remaining alphabets
    for (char ch = 'A'; ch <= 'Z'; ch++) {

        if (ch == 'J')
            continue;

        if (key.find(ch) == string::npos)
            key += ch;
    }

    // Fill matrix
    int k = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = key[k++];
        }
    }

    // Print matrix
    cout << "\nKey Matrix:\n";

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Prepare plaintext
    string prepared = preparePlaintext(plainText);

    cout << "\nPrepared Plaintext: " << prepared << endl;

    // Encrypt
    string cipher = encrypt(prepared, matrix);

    cout << "Encrypted Text: " << cipher << endl;

    return 0;
}