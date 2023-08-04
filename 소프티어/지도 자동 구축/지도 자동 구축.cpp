#include<iostream>
#include<cmath>

using namespace std;

int main(int argc, char** argv)
{
	int N, sqnum, dots, answer=1;
	cin >> N;
	
	sqnum = pow(4,N); // 한 변 사각형 개수
	dots = sqrt(sqnum)+1; // 한 변 꼭짓점 개수 -> 정답은 dots의 제곱이 됨

	cout<<dots*dots;
	return 0;
}
