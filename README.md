## C++ Algorithm-Study

* This repository is a C++ library for algorithm study.
* 알고리즘 공부를 위한 C++ 소스코드 저장소입니다.

## Contents

### 1. 백준1759 [암호 만들기](https://www.acmicpc.net/problem/1759) (골드5)
*틀린 이유: 'abes' 출력인데 제대로 안보고 'a b e s'로 출력하고 못찾음, 해당 조건을 만족하는 답만 바로 찾으려고 함
*조합(prev_permutation)과 정렬을 섞은 문제
해당 조건을 만족하는 답을 바로 찾기 => 모든 경우의 수를 구하고 해당 조건을 만족하는지 확인  
모음, 자음으로 각자 나누고 조합 => 입력 받은 알파벳의 모든 경우의 수 중 조건을 만족하는 알파벳 모음 출력
