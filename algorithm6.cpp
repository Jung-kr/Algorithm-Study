#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;
vector<int> arr;

int binarySearch(int n, int c) {
	
	int result = 0; 
	
	int start = 1;	// 최소거리 
	int end = arr[n-1] - arr[0];	// 최대거리 
	
	while(start <= end) {
		int mid = (start + end) / 2;
		int cnt = 1;	// 공유기 수 
		int st = arr[0];
		
		for(int i = 1 ; i < n ; i++) {
			if(arr[i] - st >= mid) {
				st = arr[i];
				cnt++;
			}
		}
		
		if(cnt < c) {
			end = mid - 1;
		} else {
			result = max(result, mid);
			start = mid + 1;
		}	
	}
	
	return result;
}

int main() {
	
	cin >> n >> c;
	
	for(int i = 0 ; i < n ; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}
	
	sort(arr.begin(), arr.end());	// 이분 탐색을 위한 오름차순 정렬 
	
	cout << binarySearch(n, c) << '\n'; 
	
	return 0;
}
