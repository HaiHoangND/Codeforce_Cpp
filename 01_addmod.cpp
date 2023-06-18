#include <iostream>
#define p 1000000007

using namespace std;

int main(){
	unsigned long long a, b;
	cin >> a >> b;
	cout << (a%p + b%p)%p;
	return 0;
}

