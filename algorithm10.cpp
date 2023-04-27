// hashmap이용, map 사용하려면 unordered_map -> map으로
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map <int, int> mp;
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	
	cin >> n;
	
	for(int i = 0 ; i < n ; i++) {
	    int card;
	    cin >> card;
	    mp[card]++;
	}
	
	cin >> m;
	
	for(int i = 0 ; i < m ; i++) {
	    int x;
	    cin >> x;
	    cout << mp[x] << ' ';
	}
	
	return 0;
}
