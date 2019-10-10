#include<iostream>	//조 만들기

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);	//std파일 함수 속도 가속화시켜줌
	int test_case;
	int T,N,K;
	cin>>T;
    int answer = 0;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N >> K;		//한 번에 N,K받기
        cout << "#"<<test_case<<' ';
        if ( N % 2 == 0) {	//짝수이면 모든 조가 같음
            answer = (N*K*(N*K+1) / 2)/K;
        	for(int i = 0; i < K; i++)
                cout << answer << ' ';
        }
        else {			// 홀수면 짝수까지 점수가 같고 그 후가 1씩차이남
            answer = ((N*K-K)*(N*K-K+1)/2)/K + N*K-K+1;
            for(int i = 0; i < K; i++)
                cout << answer+i << ' ';
        }
        cout << '\n';
	}
	return 0;
}
