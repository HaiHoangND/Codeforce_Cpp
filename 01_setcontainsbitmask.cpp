#include <iostream>

using namespace std;

int main(){
	int n, m;
	int a[100], b[100], c[100];
	cin >> n;
	for(int i = 0; i< n; i++){
		cin >> a[i];
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> b[i];
		c[i] = 0;
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(b[i] == a[j]){
				c[i] = 1;
			}
		}
	}
	for(int i = 0; i< m; i++){
		if(c[i] == 0){
			cout << 0;
			return 0;
		}
	}
	cout << 1;
	return 0;
}

