#include <iostream>
#include <vector>
#include <queue>
#define N 10000

using namespace std;
vector<int> arr(N+1, true);
vector<int> primeNum;
vector<int> graph[N];

// 주어진 두 정수에서 3개의 값이 같다면 true 리턴 
bool countValue(int x, int y) {
	int cnt = 0;
	
	if(x / 1000 == y / 1000) cnt++;
	if(x / 100 % 10 == y / 100  % 10) cnt++;
	if(x / 10 % 10 == y / 10 % 10) cnt++;
	if(x % 10 == y % 10) cnt++;

	if(cnt == 3) {
		return true;
	}

	return false;
}

int bfs(int x, int y) {
	int cnt = 0;
	queue<int> q;
	q.push(x);
	
	while(!q.empty()) {
			
		int queueSize = q.size();
		
		// 그래프의 lev를 알기 위해 큐의 사이즈를 저장해서 2중 반복문 실행 
		for(int i = 0 ; i < queueSize ; i++) {
			int f = q.front();
			q.pop();
		
			if(f == y) {
				return cnt;
			}
		
			for(int j = 0 ; j < graph[f].size() ; j++) {
				q.push(graph[f][j]);
			}
		}
		cnt++;
	}
	
	return cnt;
}

int main() {
	
	for(int i = 2 ; i < N ; i++) {
		
		if(arr[i]) {
			int j = 2;
			while(i*j < N) {
				arr[i*j] = false;
				j++;
			}
		}
	}
	
	for(int i = 1000 ; i < N ; i++) {
		if(arr[i]) {
			primeNum.push_back(i);
		}
	}
	
	for(int i = 0 ; i < primeNum.size() ; i++) {
		for(int j = 0 ; j < primeNum.size() ; j++) {
			if(countValue(primeNum[i], primeNum[j])) {
				graph[primeNum[i]].push_back(primeNum[j]);
			}
		}
	}
	
	int testCase;
	int n, m;
	
	cin >> testCase;
	
	for(int i = 0 ; i < testCase ; i++) {
		cin >> n >> m;	
		cout << bfs(n, m) << '\n';
	}
	
	
	return 0;
}
