#include <iostream>
#include <string>

using namespace std;

void solve(string str){
	int k = str.length();
	if(k <= 10) cout << str;
	else{
		cout << str[0] << k - 2 << str[k-1];
	}
	cout << endl;
}

int main(){
	int n;
	string str;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> str;
		solve(str);
	}
	return 0;
}

