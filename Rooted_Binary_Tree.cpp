#include<iostream>	//D3.7985-Rooted_Binary_Tree_재구성
#include<math.h>
#include<string.h>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T,K,val;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> K;
        val = (int)pow(2,K)-1;
        int *arr = new int[val];	#수 받기
        int *arrset = new int[val+1];	#각 수의 깊이를 체크해주는 배열
        memset(arrset,0,sizeof(arrset));	#0으로 초기화
        cout <<"#" << test_case <<' ';
        for (int i = 0; i < val; i++)	#문자열 받기
            cin >> arr[i];
        for (int i = 1; i < K+1; i++) {	#각 수의 깊이를 체크해줌
            for (int j = 0; j < val+1; j += (int)pow(2,i) )
                    arrset[j] = i;
        }
        for (int i = K-1; i >=0; i--) {	#출력문
            for (int j = 0; j < val; j++) {
                if (arrset[j+1] == i)
                    cout << arr[j] <<' ';
            }
            cout << '\n';
        }
	}
	return 0;
}
