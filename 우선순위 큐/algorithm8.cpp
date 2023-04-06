#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int k, n;
priority_queue<int, vector<int>, greater<int> > pq;
vector<int> v;
int cnt;

int main() {
	
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	
	cin >> k >> n;
	
	for(int i = 0 ; i < k ; i++) {
		int x;
		cin >> x;
		pq.push(x);
		v.push_back(x);
	}
	
	long long top;
	long long prevtop;
	
	while(cnt < n) {
		top = pq.top();
		
		if(top == prevtop) {
			pq.pop();
			continue;
		}
		
		for(int i = 0 ; i < v.size() ; i++) {
			if(top * v[i] < 2147483648)
			pq.push(top * v[i]);
		}
		
		pq.pop();
		prevtop = top;	// 최소 힙에 중복된 수가 들어가는 것을 막기 위함 
		cnt++;
	}
	
	cout << top << '\n';
	
	return 0;
}
