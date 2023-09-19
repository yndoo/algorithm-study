//시간복잡도 O(N)
// 모노톤스택 알고리즘 활용
// https://justicehui.github.io/medium-algorithm/2019/01/01/monotoneStack/

#include<bits/stdc++.h>
using namespace std;
int arr[5000001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<int> s;
	int N, x;
	
	cin >> N;
	
	for (int i = 0; i < N; i++) { 			//N회 반복
		cin >> x;				
		arr[i] = x;				//N번째 탑의 높이 입력받으며 몇 번째 인덱스인지 map에 저장
		while(!s.empty() && arr[s.top()] < x) { //s.top()에 나보다 큰 건물(의 인덱스)가 있을때까지 pop
			s.pop();
		}
		if (!s.empty()) { cout << s.top()+1; }	//스택이 비어있지 않다면 s.top()이 나의 레이저를 수신하는 탑의 인덱스
		else { cout << 0; }			//스택이 비어있다면 레이저 수신하는 탑 없음 -> 0출력
		s.push(i);				//스택에 인덱스를 push
		if (i != N - 1) { cout << " "; }	//출력형식 맞추기용 공백
	}

	return 0;
}

/*
* 최악의 경우 시간복잡도 O(NlogN)
* 
#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<int> s;
	map<int, int> m;
	int N;
	cin >> N; 							//N 입력받기
	for (int i = 0; i < N; i++) { 					//N회 반복
		int x;
		cin >> x;
		m[x] = i + 1;						//N번째 탑의 높이 입력받으며 몇 번째 인덱스인지 map에 저장 : O(logN)
		while(!s.empty() && s.top() < x) { 			//s.top()에 나보다 큰 건물이 있을때까지 pop
			s.pop();
		
		if (!s.empty()) { cout << m[s.top()]; }			//스택이 비어있지 않다면 s.top()이 나의 레이저를 수신하는 탑
		else { cout << 0; }					//스택이 비어있다면 레이저 수신하는 탑 없음 -> 0출력
		s.push(x);
		if (i != N - 1) { cout << " "; }			//출력형식 맞추기용 공백
	}

	return 0;
}*/
