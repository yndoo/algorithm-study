#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
	int M, N, K;
	cin >> M >> N >> K;

	int magic[M];
	int ismagic=0; //비밀 조작법의 몇 번째 버튼인지 세는 변수

	for (int i=0; i<M; i++){
		cin>>magic[i];
	}

	for (int i=0; i<N; i++){
		int x;
		cin >> x;
		if(x==magic[ismagic]){
			if (ismagic==M-1){
				cout<<"secret";
				return 0;
			}else{
				ismagic++;
			}
		} else if(x==magic[0]){
			if (magic[ismagic-1]==magic[0]){
				continue;
			}
			ismagic=1;
		}
		else {
			ismagic=0;
		}
		//cout<< x << ismagic<<endl;
	}
	cout<<"normal";
	return 0;
}
