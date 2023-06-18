#include <iostream>

using namespace std;

int a[1000000];

int main(){
	int n;
	string s;
	cin >> n;
	for(int i = 0; i< n; i++){
		cin >> a[i];
	}
	int sum = a[0];
	int max = a[0];
	for(int i = 1; i < n; i++){
		if(sum < 0) sum = a[i];
		else{
			sum += a[i];
		}
		if(max < sum) max = sum;
	}
	cout << max;
	return 0;
}

