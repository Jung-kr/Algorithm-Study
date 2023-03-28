#include <iostream>
#include <queue> 

using namespace std;

int n, m;
int arr[8][8];
int arr2[8][8];
bool visited[8][8];

void dfs(int x, int y) {
	
	// 해당 좌표가 범위를 벗어나는 경우 
	if(x < 0 || x >= n || y < 0 || y >= m) {
		return;
	}
	
	// 해당 좌표가 벽(1)인 경우 
	if(arr[x][y] == 1) {
		return;
	}
	
	if(!visited[x][y]) {
		visited[x][y] = true;
		arr[x][y] = 2;
		
		dfs(x-1, y);
		dfs(x+1, y);
		dfs(x, y-1);
		dfs(x, y+1);
		
		return;
	}
}

int main() {
	
	cin >> n >> m;
	
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < m ; j++) {
			cin >> arr[i][j];
			arr2[i][j] = arr[i][j];
		}
	}
	
	int max = 0;
	
	for(int i = 0 ; i < n*m ; i++) {
		for(int j = i+1 ; j < n*m ; j++) {
			for(int k = j+1 ; k < n*m ; k++) {
				
				int x1 = i / m, y1 = i % m;	// 세울 3벽 중 첫번째 벽 
				int x2 = j / m, y2 = j % m;	// 세울 3벽 중 두번째 벽
				int x3 = k / m, y3 = k % m;	// 세울 3벽 중 세번째 벽
				
				if(arr[x1][y1] != 0 || arr[x2][y2] != 0 || arr[x3][y3] != 0) {	// 세벽 모두 세울 수 있는 경우만 dfs 진행 
					continue;
				}
				
				arr[x1][y1] = 1;
				arr[x2][y2] = 1;
				arr[x3][y3] = 1;	
				
				// arr에 대한 dfs 수행	=> 바이러스 전파 
				for(int i = 0 ; i < n ; i++) {
					for(int j = 0 ; j < m ; j++) {
						if(arr[i][j] == 2) {
							dfs(i, j);
						}
					}
				}
				
				
				int cnt = 0;
				// arr의 안전영역의 갯수 세면서 최대값 탐색 
				for(int i = 0 ; i < n ; i++) {
					for(int j = 0 ; j < m ; j++) {
						if(arr[i][j] == 0) {
							cnt++;
						}
					}
				}	
				
				if(cnt > max) {
					max = cnt;
				}
				
				// arr, visited 초기화 
				for(int i = 0 ; i < n ; i++) {
					for(int j = 0 ; j < m ; j++) {
						arr[i][j] = arr2[i][j];
						visited[i][j] = false;
					}
				}	
			}
		}
	} 
	
	cout << max << '\n';
	
	return 0;
}
