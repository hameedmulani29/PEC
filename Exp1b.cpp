#include <bits/stdc++.h>
using namespace std;

int moduloAddition(int a, int b, int mod){
    int c = a+b;
    c = c % mod;
    return c;
}

int moduloSubtraction(int a, int b, int mod){
    int res = 0;
    if(a > b){
        res = a-b;
        res = res % mod;
    }else{
        res = b-a;
        res = res % mod;
    }
    return res;
}

int moduloMultiplication(int a, int b, int mod){
    if(a == 0 || b == 0) return 0;
    int res = a*b;
    res = res % mod;
    return res;
}

int moduloDivision(int a, int b, int mod){
    int res =  a / b;
    res = res % mod;
    return res;
}

int main() {
    int a,b, mod;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter mod: ";
    cin >> mod;
    cout << endl;
    cout << "Addition: " << moduloAddition(a,b, mod) << endl;
    cout << "Subtraction: " << moduloSubtraction(a,b,mod) << endl;
    cout << "Multiplication: " << moduloMultiplication(a,b,mod) << endl;
    cout << "Division: " << moduloDivision(a,b, mod) << endl;
    return 0;
}