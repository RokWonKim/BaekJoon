//2차원 DP 시간복잡도 - O(N*M) -> O(N**2)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    //n은 동전 몇개 받을건지, k는 동전 합쳐서 나올 합값
    //num은 n개의 동전이 각 각 어떤 가치를 갖는지
    int n,k,num;
    int max_val = 0; //정답

    cin >> n >> k; 
    vector<int> n_arr; //num들을 받을 배열
    for(int i = 0; i < n; i++) {
        cin >> num;
        n_arr.push_back(num);
    }
    sort(n_arr.begin(),n_arr.end()); //순서대로 만들기 위해 sort

    //2차원 배열 만들기
    vector< vector<int> > v(n, vector<int>(k+1));

    //첫번째 줄은 먼저 입력받기(다음 반복문에서 -1줄을 해야하기 때문에 미리 해주는게 코드가 깔끔함)
    if (n_arr[0] <= k) {
        for(int i = 1; i <= k; i++)
            if(i%n_arr[0] == 0) v[0][i] = i/n_arr[0];
    }

    //벌써 k값을 맞출 수 있으니!
    max_val = v[0][k];
    
    //각 열은 k까지 가는 길?느낌
    for(int i = 1; i < n; i++) {
	//입력 받은 num값들 중에서 k를 넘어 버리는 것이 있음
	//그런 것들은 필요없으니 스킵하는게 효율이 좋음
	//(sort되어있어서 num값들이 n_arr에 오름차순 정렬되어있음
        if (n_arr[i] > k) break;
        for(int j = 1; j <=k; j++) {
	    //오름차순 정렬이니 n_arr[i]의 배수이면 그 몫이 가장 빠른 길
            if(j%n_arr[i] == 0) v[i][j] = j/n_arr[i];
            else {
		//ex) n_arr[i]가 3이면 1,2는 어차피 없으니 위의 것 카피
                if (j < n_arr[i]) v[i][j] = v[i-1][j];
		//ex) n_arr[i]가 3이다. 현재 8번 인덱스를 지나가면 8-3인덱스에 0이 아닌 수가 존재하면
		//    +1해서 넣기
		else if (v[i][j-n_arr[i]] == 0) v[i][j] = v[i-1][j];
		//ex) 위 else if구문이 틀리다면 8-3에 0이 아닌 수가 있음
		//    거기에 +1해서 그 전 행에서의 값과 비교해서 작은 값넣기
		//    단 위 행의 값이 0이면 그냥 8-3인덱스 값에 +1해서 넣기 
                else{ 
                    if (v[i-1][j] == 0) v[i][j] = v[i][j-n_arr[i]]+1;
                    else v[i][j] = min(v[i-1][j], v[i][j-n_arr[i]]+1);
                }
            }
        }
	//행이 바뀔때마다 최신화
        max_val = v[i][k];
    }
    
    //max_val이 0이라는 것은 k를 만들 수 없다는 것이니 -1로 바꿔 줘야댐
    if (max_val == 0) max_val = -1;
    cout << max_val;
    return 0;
}

    
