#include <iostream>

using namespace std;

int a, b, c;

long long multiple(int y) {
	
	if(y == 1) return a % c;
	
	long long k = (multiple(y/2) % c);
	
	if(y % 2 != 0) {
		return k * (k * a % c) % c;
	} else {
		return k * k % c;
	}
}

int main() {
	
	cin >> a >> b >> c;
	
	cout << multiple(b) << '\n';
	
	return 0;
}
