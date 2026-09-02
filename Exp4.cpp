#include <iostream>
#include <string>
using namespace std;

// Expansion table: 32 bits -> 48 bits
int E[48] = {
    32,1,2,3,4,5,
    4,5,6,7,8,9,
    8,9,10,11,12,13,
    12,13,14,15,16,17,
    16,17,18,19,20,21,
    20,21,22,23,24,25,
    24,25,26,27,28,29,
    28,29,30,31,32,1
};

// P-box permutation
int P[32] = {
    16,7,20,21,
    29,12,28,17,
    1,15,23,26,
    5,18,31,10,
    2,8,24,14,
    32,27,3,9,
    19,13,30,6,
    22,11,4,25
};

// DES S-Boxes
int S[8][4][16] = {

    // S1
    {
        {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
        {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
        {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
        {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
    },

    // S2
    {
        {15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
        {3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
        {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
        {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}
    },

    // S3
    {
        {10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},
        {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
        {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
        {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}
    },

    // S4
    {
        {7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
        {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
        {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
        {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}
    },

    // S5
    {
        {2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},
        {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
        {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
        {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}
    },

    // S6
    {
        {12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},
        {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
        {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
        {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}
    },

    // S7
    {
        {4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},
        {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
        {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
        {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}
    },

    // S8
    {
        {13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},
        {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
        {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
        {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}
    }
};


// Perform permutation
string permute(string input, int table[], int size) {
    string output = "";

    for (int i = 0; i < size; i++) {
        output += input[table[i] - 1];
    }

    return output;
}


// XOR two binary strings
string XOR(string a, string b) {
    string result = "";

    for (int i = 0; i < a.length(); i++) {
        result += (a[i] == b[i]) ? '0' : '1';
    }

    return result;
}


// Convert decimal number to 4-bit binary
string toBinary(int n) {
    string result = "";

    for (int i = 3; i >= 0; i--) {
        result += ((n >> i) & 1) ? '1' : '0';
    }

    return result;
}


// S-box substitution: 48 bits -> 32 bits
string sBoxSubstitution(string input) {

    string output = "";

    for (int i = 0; i < 8; i++) {

        string block = input.substr(i * 6, 6);

        // First and last bits form row
        int row =
            (block[0] - '0') * 2 +
            (block[5] - '0');

        // Middle four bits form column
        int col =
            (block[1] - '0') * 8 +
            (block[2] - '0') * 4 +
            (block[3] - '0') * 2 +
            (block[4] - '0');

        int value = S[i][row][col];

        output += toBinary(value);
    }

    return output;
}


int main() {

    // 32-bit right half
    string R0 = "10011010101111001101111011111111";

    // 32-bit left half
    string L0 = "00010010001101000101011001111000";

    // 48-bit round key
    string K1 = "000110110000001011101111111111000111000001110010";

    cout << "----- SINGLE ROUND DES -----\n\n";

    cout << "L0       : " << L0 << endl;
    cout << "R0       : " << R0 << endl;
    cout << "Round Key: " << K1 << endl;

    // Step 1: Expansion
    string expandedR = permute(R0, E, 48);

    cout << "\n1. Expansion (32 -> 48):\n";
    cout << expandedR << endl;

    // Step 2: XOR with round key
    string xored = XOR(expandedR, K1);

    cout << "\n2. XOR with Round Key:\n";
    cout << xored << endl;

    // Step 3: S-box substitution
    string sboxOutput = sBoxSubstitution(xored);

    cout << "\n3. S-Box Substitution (48 -> 32):\n";
    cout << sboxOutput << endl;

    // Step 4: P-box permutation
    string fOutput = permute(sboxOutput, P, 32);

    cout << "\n4. P-Box Permutation:\n";
    cout << fOutput << endl;

    // Step 5: Calculate L1 and R1
    string L1 = R0;
    string R1 = XOR(L0, fOutput);

    cout << "\n----- AFTER ONE ROUND -----\n";

    cout << "L1 = " << L1 << endl;
    cout << "R1 = " << R1 << endl;

    return 0;
}