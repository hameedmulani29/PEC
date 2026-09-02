#include <bits/stdc++.h>
using namespace std;

long long modPower(long long base, long long exponent, long long modulus){
    long long result = 1;
    while(exponent > 0){
        if(exponent % 2 != 0){
            result = (result*base) % modulus;
        }
        base = (base*base)%modulus;
        exponent = exponent/2;
    }
    return result;
}

long long gcd(long long a, long long b){
    while(b != 0){
        long long temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int main() {
    long long p,q,n,phi,e,d, cipher, message, decrypted;
    cout << "Enter p and q: ";
    cin >> p >> q;
    cout << "Enter message: ";
    cin >> message;
    n = p*q;
    phi = (p-1)*(q-1);

    for(e = 2; e < phi; e++){
        if(gcd(e, phi)==1)break;
    }

    for(d = 1; d < phi; d++){
        if((d*e)%phi == 1){
            break;
        }
    }

    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "message = " << message << endl;

    cout << "n = " << n << endl;
    cout << "phi = " << phi << endl;
    cout << "e = " << e << endl;
    cout << "d = " << d << endl;
    cipher = modPower(message,e,n);
    cout << "Encrypted Value: " << cipher;
    cout << endl;
    decrypted = modPower(cipher,d,n);
    cout << "Decrypted Message: " << decrypted;
    return 0;
}