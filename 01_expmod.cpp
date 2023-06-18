#include <iostream>
#define p 1000000007

using namespace std;
 
int power(unsigned long long x, unsigned long long y)
{
    unsigned long long res = 1;
    x = x % p; 
    if (x == 0) return 0; 
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;// gop 2 so x vi o tren y da chia cho 2
    }
    return res;
}
 
int main()
{
    unsigned long long x, y;
    cin >> x >> y;
    cout << power(x, y);
    return 0;
}
