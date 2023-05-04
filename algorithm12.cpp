// stoi(num) => string num을 int형으로 변환 

#include <iostream>
#include <string>

using namespace std;

bool isMinus;
int result;

// -가 있으면 뒤에 모든 수 빼주기 
int main() {
	string input;
	cin >> input;
	string num = "";	// 기호 나오기 전까지의 숫자를 저장할 변수 
	
	for(int i = 0 ; i <= input.size() ; i++) {
		if(input[i] == '+' || input[i] == '-' || i == input.size()) {	// i == input.size() 마지막에 기호 없으므로 
			if(isMinus) {
				result -= stoi(num);
			} else {
				result += stoi(num);
			}
			
			if(input[i] == '-') {
				isMinus = true;
			}	 
			num = "";
		} else {
			num += input[i];
		}
	}
	
	cout << result << '\n';
	
	return 0;
}
