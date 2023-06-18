/*#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main(){
	string str1;
	string str2;
	cin >> str1;
	fflush(stdin);
	cin >> str2;
	int a[100];
	int m = str1.length(), n = str2.length();
	for(int i = abs(m-n); i >= 1; i--){
		if(m > n) str2 = "0" + str2;
		else str1 = "0" + str1;
	}
	for(int i = str1.length()-1; i >= 0; i--){
		a[i] = ((int)str1[i] - 48) + ((int)str2[i] - 48);
	}
	for(int i = str1.length()-1; i >= 1; i--){
		if(a[i] >= 10){
			a[i-1]+=1;
			a[i]-=10;
		}
	}
	string ans = "";
	for(int i = 0; i <= str1.length()-1; i++){
		ans += to_string(a[i]);
	}
	cout << ans;
	return 0;
}*/
#include <iostream>

using namespace std;

int main(){
	unsigned long long e, f, c, d;
	cin >> e >> f;
	d = e%10 + f%10;
	c = e/10 + f/10;
	if(d >= 10){
		c++;
		d = d%10;
	}
	if(c != 0) cout << c << d;
	else cout << d;
	return 0;
}
