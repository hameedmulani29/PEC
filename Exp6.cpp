#include<bits/stdc++.h>
using namespace std;

int modPow(int base, int exponent, int modulus){
    int result = 1;
    if (exponent == 0) return 1;
    
    if(exponent % 2 == 0){
        result = modPow(base, exponent/2, modulus);
        return (result*result)%modulus;
    }
    else{
        return base * modPow(base, exponent-1, modulus)%modulus;
    }
}

int main(){
    int p, g,a,b;
    cout << "Enter prime number p : ";
    cin >> p;
    cout << "Enter primitive root g: ";
    cin >> g;
    cout << "Enter first private key: ";
    cin >> a;
    cout << "Enter second private key: ";
    cin >> b;

    int A,B;
    A = modPow(g,a,p);
    B = modPow(g,b,p);

    int skt1 = modPow(B,a,p);
    int skt2 = modPow(A,b,p);

    if(skt1 == skt2)cout << "Shared secret key: " << skt1 << endl << "Shared secret key: " << skt2 << endl << "Success " << endl << "First private key: " << a << endl << "First public key: " << A << endl  << "Second private key: " << b << endl << "Second public key: " << B << endl;
    else cout << "Failure" << endl;
    return 0;
}