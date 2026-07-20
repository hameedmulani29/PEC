#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b,a%b);
}

int lcm(int a, int b){
    return (a/gcd(a,b))*b;
}

int main() {
    int a,b;
    cout << "Enter the value of a and b:";
    cin >> a >> b;
    
    int result1 = gcd(a,b);
    int result2 = lcm(a,b);

    cout << "The gcd of the given numbers is: " << result1 << endl;
    cout << "The lcm of the given numbers is: " << result2 << endl;
    return 0;
}