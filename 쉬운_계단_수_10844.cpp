//2차원 DP사용

#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector< vector<int> > v_arr(101, vector<int>(10)); //2차원 배열 할당
    for(int i = 1; i<10; i++) {				//1자리 수와 2자리수는 직접 초기화
        v_arr[1][i] = 1;
        v_arr[2][i] = 2;
    }
    v_arr[2][9] = 1;
    int N;
    int sum = 0;
    cin >> N;			//몇자리 수가 필요한지 입력

    //전체적으로 이진트리 방식?으로 직접 손으로 풀어놓고 보면 보임
    for(int i = 3; i <= N; i++) {
        for(int j = 1; j < 10; j++){
	    //맨 앞자리가 1이면 N-1자리수의 +1 차이 나는 것과 N-2자리수의 0차이는 나는 것을 더함
            if (j == 1) v_arr[i][j] = (v_arr[i-1][j+1] + v_arr[i-2][j])%1000000000;
	    //맨 앞자리가 9이면 N-1자리수의 -1 차이 나는 것을 그대로 가져옴
            else if (j == 9) v_arr[i][j] = (v_arr[i-1][j-1])%1000000000;
	    //2~8은 N-1에서 -1과 +1 의 것을 더한 것을 가져옴
            else {
                v_arr[i][j] = (v_arr[i-1][j-1]+v_arr[i-1][j+1])%1000000000;
            }
        }
    } //다시 한 번 말하지만 이진트리 방식처럼 손으로 직접 만들어 써보면 보임

    //반복자 사용해 N에 해당하는 행에서 1~9를 더함
    for(vector<int>::iterator iter = v_arr[N].begin(); iter != v_arr[N].end(); ++iter)
        sum = (sum + (*iter) )%1000000000;
    cout << sum;
    
    return 0;
}
