## C++ Algorithm-Study

* This repository is a C++ library for algorithm study.
* 알고리즘 공부를 위한 C++ 소스코드 저장소입니다.

## Contents

### 1. 백준1759 [암호 만들기](https://www.acmicpc.net/problem/1759) (골드5)
*수학
*틀린 이유: 'abes' 출력인데 제대로 안보고 'a b e s'로 출력하고 못찾음, 해당 조건을 만족하는 답만 바로 찾으려고 함  
*조합(prev_permutation)과 정렬을 섞은 문제  
해당 조건을 만족하는 답을 바로 찾기 => 모든 경우의 수를 구하고 해당 조건을 만족하는지 확인  
모음, 자음으로 각자 나누고 조합 => 입력 받은 알파벳의 모든 경우의 수 중 조건을 만족하는 알파벳 모음 출력

### 2. 백준1644 [소수의 연속합](https://www.acmicpc.net/problem/1644) (골드3)
*특정 합을 가지는 부분 연속 수열 찾기(부분합)  -> 투 포인터 문제  
*에라토스테네스의 체 + 투 포인터(부분합)  
ex) [1,2,3,2,5] 에서 합 5를 가지는 연속 수열의 갯수: 2

### 3. 백준14502 [연구소](https://www.acmicpc.net/problem/14502) (골드4)  
0 0 0 0 0 0  
1 0 0 0 0 2  
1 1 1 0 0 2  
0 0 0 0 0 2  
*위와 같은 배열에서 3개의 벽(1)을 넣어야 됨 => 가로, 세로 길이이 10 이상이기 때문에 3중 반복문을 통한 완전 탐색 가능  
*배열 arr2를 만들어놓음 => arr에 벽(1)을 3개 넣고 dfs 실행 후 arr2를 이용해서 초기화  

### 4. 백준1963 [소수 경로](https://www.acmicpc.net/problem/1963) (골드4)  
*생성된 그래프의 lev(깊이) 구할때  
=> 기존에는 bfs는 1중 반복문을 통해 queue에 push,pop 했지만 lev를 구할 때는 2중 반복문(큐 사이즈 저장)을 통해 구함
  
### 5. 백준1629 [곱셈](https://www.acmicpc.net/problem/1629) (실버1)  
*수학 // 지수법칙과 모듈러 성질을 이용해서 시작 복잡도극 log로 줄이는 문제  
지수법칙 : a^(n+m) = a^n * a^m  
모듈러 성질  
![image](https://user-images.githubusercontent.com/81340804/229124579-63f24841-7d6f-4e17-8b47-fc5ef2dc52b1.png)
  
### 6. 백준2110 [공유기 설치](https://www.acmicpc.net/problem/2110) (골드4)  
*이분탐색 문제  
=> 이분 탐색을 이용하는 문제는 어느 부분에서 이분 탐색을 이용해야 하는지 찾기 어려울 수 있음  
<꼭 다시 풀어볼 것>  

### 7. 백준1927 [최소힙](https://www.acmicpc.net/problem/1927)  
*우선순위 큐 문제  
ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);로 입출력 시간을 줄일 수 있음  
https://velog.io/@gogori6565/BOJ-cin.tieNULL%EA%B3%BC-iosbasesyncwithstdiofalse  
  
### 8. 백준2014 [소수의 곱](https://www.acmicpc.net/problem/2014) (골드2) 
*우선순위 큐 문제  
=> 우선순위 큐를 생각하는 아이디어 + 최소 힙에 들어갈 숫자가 중복될 수도 있다


