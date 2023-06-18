#include <iostream>
#define p 1000000007

using namespace std;

long long a[1000005];

int main(){
	int n;
	cin >> n;
	long long s = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		s = (s + a[i])%p;
	}
	cout << s;
	return 0;
}

