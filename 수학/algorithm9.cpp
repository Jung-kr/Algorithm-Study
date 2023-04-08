#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 2147483647

using namespace std;

int n, m;
vector<pair<int, int> > house;
vector<pair<int, int> > chicken;
vector<int> visited;	// 조합을 사용하기 위한 보조 순열 
int minDistanceChick = MAX;

void calculateDistance() {
	
	int totalDistance = 0;

	for(int i = 0 ; i < house.size() ; i++) {	
		int minDistance = MAX;
		
		for(int j = 0 ; j < chicken.size() ; j++) {
			if(visited[j] == 1) {
				int distance = (abs(house[i].first - chicken[j].first) 
					+ abs(house[i].second - chicken[j].second));
					
				if(distance < minDistance) {
					minDistance = distance;
				}
			}
		}
		totalDistance += minDistance;
	}
	
	if(minDistanceChick > totalDistance) {
		minDistanceChick = totalDistance;
	}
}

void selectChicken() {
	
	for(int i = 0 ; i < chicken.size() ; i++) {
		// 초기 보조 순열 초기화 
		if(i < chicken.size() - m) {
			visited.push_back(0);
		} else {
			visited.push_back(1);
		}
	}
	do {
		calculateDistance();
	} while(next_permutation(visited.begin(), visited.end()));
	
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	
	cin >> n >> m;
	
	for(int i = 1 ; i <= n ; i++) {
		for(int j = 1 ; j <= n ; j++) {
			int x;
			cin >> x;
			
			if(x == 1) {
				house.push_back({i, j});
			} else if(x == 2) {
				chicken.push_back({i, j});
			}
		}
	}
	
	selectChicken();
	
	cout << minDistanceChick << '\n';
	
	return 0;
}
