#include <iostream>
#include <vector>

using namespace std;

int n;

int main() {

	cin >> n;
	vector<int> arr(n+1, true);	// 에라토스테네스의 체를 이용할 벡터 
	vector<int> primeNum;	// 소수를 저장할 벡터 
		
	for(int i = 2 ; i <= n ; i++) {
		
		if(arr[i]) {
			int j = 2;
			
			while(i*j <= n) {
				arr[i*j] = false;
				j++;
			}
		}
	}
	
	for(int i = 2 ; i <= n ; i++) {	// n까지의 소수 primeNum에 저장 
		if(arr[i]) {
			primeNum.push_back(i);
		}
	}
	
	// 부분합 구하기(투 포인터 문제)	 
	int cnt = 0, intervalSum = 0, end = 0; // 부분합: n 

	for(int start = 0 ; start < primeNum.size() ; start++) {
		
		while(intervalSum < n && end < primeNum.size()) {
			intervalSum += primeNum[end];
			end++;
		}
		if(intervalSum == n) {
			cnt++;
		}
		intervalSum -= primeNum[start];
	}
	
	cout << cnt << '\n';

	return 0;
}
