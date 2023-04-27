#include <iostream>
#include <map>

using namespace std;

map <string, float> mp;
float cnt;	// 전체 나무 수 

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	
	// 입력 종료 조건이 없으므로 getline eof
	string tree;
	while(getline(cin, tree)) {
		mp[tree]++;
		cnt++;
	}
	
	map<string, float>::iterator i;
	
	for(i = mp.begin() ; i != mp.end() ; i++) {
		
		// cout으로 4소수점까지 표시 
		cout << fixed; 
		cout.precision(4);
		
		cout << i->first << ' ' << (i->second)/cnt*100 << '\n';
	}
	
	
	return 0;
}
