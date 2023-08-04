#include<iostream>
#include <map>
#include <cstring>
#include<algorithm>
#include<vector>


using namespace std;

int main(int argc, char** argv)
{
	int N, M;
	string room;
	map<string, int> rooms;

	cin >> N >> M;
	int array[N][10] = {0};
	string asc[N];

	for(int i; i<N; i++){
		cin >> room;
		asc[i] = room;
	}
	// 회의실 이름 사전순 정렬
	sort(asc,asc+N);
	for(int i; i<N; i++){
		rooms[asc[i]] = i;
	}

	// 예약 내역 하나씩 정리
	for(int j=0; j<M; j++){
		int s, e;
		cin>>room>>s>>e;
		for(int k=s-9; k<e-9; k++){
			array[rooms[room]][k]=1;
		}
	}

	for(int i=0; i<N; i++){
		int cnt=0;
		vector<vector<int>> res;
		cout<<"Room "<<asc[i]<<":"<<endl;
		//예약전체확인
		int s=0,e=0;
		for (int j=0; j<10; j++){
			if ((array[i][j]==0) && s==0){
				s = j+9;
			} else if(array[i][j]!=0 && s!=0){
				e = j+9;
				vector<int> v;
				v.push_back(s);
				v.push_back(e);
				res.push_back(v);
				
				s=0,e=0;
				cnt+=1;
			} else if(array[i][j]==0 && s!=0 && j==9){
				e = j+9;
				vector<int> v;
				v.push_back(s);
				v.push_back(e);
				res.push_back(v);
				
				s=0,e=0;
				cnt+=1;
			}
		}
		if(res.empty()){
			cout<<"Not available"<<endl;
		} else{
			cout<<cnt<<" available:"<<endl;
			//res 전부 출력
			for (auto r:res){
				if(r[0]==9){
					cout<<"09";
				}else{
					cout<<r[0];
				}				
				cout<<"-"<<r[1]<<endl;
			}
		}
		if(i!=N-1){
			cout<<"-----"<<endl;
		}
	}
	return 0;
}
