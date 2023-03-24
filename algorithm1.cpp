#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, c;
vector<char> alphabet;
vector<int> visit;
vector<char> alp;

bool check(vector<char>& a) {	// 최소 모음 1개와 자음 2개를 가지고 있는지 체크 
	int con = 0;
	int vow = 0;
	
	for(int i = 0 ; i < a.size() ; i++) {
		if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') {
			con++;
		} else {
			vow++;
		}
	}
	if(con >= 1 && vow >= 2) {
		return true;
	} else {
		return false;
	}
}

int main() {
	
	cin >> l >> c;
	
	for(int i = 0 ; i < c ; i++) {
		char x;
		cin >> x;
		
		alphabet.push_back(x);
	}
	
	sort(alphabet.begin(), alphabet.end());
	
	for(int i = 0 ; i < c ; i++) {	// prev_permutation로 조합을 이용하기 위해 visit 초기화, 11..000 부터 
		if(i >= l) {
			visit.push_back(0);
		} else {
			visit.push_back(1);
		}
	}
	
	do {
		for(int i = 0 ; i < alphabet.size() ; i++) {
			if(visit[i] != 0) {
				alp.push_back(alphabet[i]);
			}	
		}
		if(check(alp)) {
			for(int i = 0 ; i < alp.size() ; i++) {
				cout << alp[i];
			}
			cout << '\n';
		}		
		for(int i = 0 ; i < l ; i++) {	// alp벡터 초기화 
			alp.pop_back();
		}
	} while(prev_permutation(visit.begin(), visit.end()));

	return 0;
}
