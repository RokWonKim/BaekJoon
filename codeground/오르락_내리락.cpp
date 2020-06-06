#include <cstdio>
#include <cstring>

using namespace std;

int Answer;
int arr[1000001];
long long sum_arr[1000001];

int solve(int i) {
    
    if (i == 1) return arr[i];
    
    int &value = arr[i];
    if (value != -1) return value;
    
    value = 1;
    if (i%2 == 1) value += solve(i+1);
    else value += solve(i/2);
    
    return value;
}

int main(int argc, char** argv)
{
    
	int T, test_case;
	memset(arr,-1,sizeof(arr));
	arr[1] = 0;
	for (int i = 1; i <= 1000000; i++) sum_arr[i] = sum_arr[i-1] + solve(i);
	    
	scanf("%d", &T);
	for(test_case = 0; test_case  < T; test_case++)
	{
		int N_1, N_2;
		scanf("%d %d", &N_1, &N_2);
		
		Answer = sum_arr[N_2] - sum_arr[N_1-1];
		
		printf("Case #%d\n%d\n", test_case+1, Answer);
	}

	return 0;
}