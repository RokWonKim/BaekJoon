
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int songNum, K, length[50]; //곡 갯수, K분 후, 곡의 길이
double T[50][50]; //다음에 나올 곡 확률

class SquareMatrix {

    private:
        vector<vector<double>> v;
        int mSize; //matrix Size
    public:
        SquareMatrix(int n) :mSize(n) {
            v.resize(mSize, vector<double>(mSize, 0));
        }
        ~SquareMatrix() {
            for (int i = 0; i < mSize; i++)
                v[i].clear();
            v.clear();
        }

        SquareMatrix identity(int n) {//단위행렬
            SquareMatrix result = SquareMatrix(n);
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (i == j)
                        result.v[i][j] = 1;
                    else
                        result.v[i][j] = 0;

            return result;
        }

        SquareMatrix operator*(SquareMatrix &b) {
            SquareMatrix result = SquareMatrix(mSize);
            for (int i = 0; i < mSize; i++)
                for (int j = 0; j < mSize; j++)
                    for (int k = 0; k < mSize; k++)
                        result.v[j][k] += v[j][i] * b.v[i][k];

            return result;
        }

        SquareMatrix pow(int k) {
            if (k == 0)
                return identity(mSize);
            if (k % 2 == 1)
                return pow(k - 1)**this;

            SquareMatrix half = pow(k / 2);
            return half*half;
        }

        double *operator[](int i) {
            return &v[i][0];
        }

};




//거듭제곱 동적 계획법
//K분 30초 후에 각 곡이 재생되고 있을 확률 반환
vector<double> getProb(void) {

    //start(time-3, 0)~start(time-3, songNum-1), start(time-2, 0)~start(time-2, songNum-1),
    //start(time-1, 0)~start(time-1, songNum-1), start(time, 0)~start(time, songNum-1)
    SquareMatrix W(4 * songNum);

    //첫 3*songNum의 원소는 그대로 복사
    for (int i = 0; i < 3 * songNum; i++)
        W[i][i + songNum] = 1.0;

    //마지막 songNum개의 원소는 이전 원소들의 선형 결합으로 이루어짐
    for (int i = 0; i < songNum; i++)
        //sProb[time+1][i]=sProb[time+1-length[j][j]*T[j][i];
        for (int j = 0; j < songNum; j++)
            W[3 * songNum + i][(4 - length[j])*songNum + j] = T[j][i];

    SquareMatrix Wk = W.pow(K); //sProb(time+1)=W*sProb(time) -> sProb(time+1)=W^(K)

    vector<double> result(songNum);

    //song번 노래가 재생되고 있을 확률 계산
    for (int song = 0; song < songNum; song++)
        //song번 노래가 시작했을 시간을 모두 찾아 더한다
        for (int start = 0; start < length[song]; start++)
            result[song] += Wk[(3 - start)*songNum + song][3 * songNum];

    return result;
}



int main(void) {

    int test_case;
    cin >> test_case;

    for (int i = 0; i < test_case; i++) {

        int favorite; //좋아하는 노래 갯수
        cin >> songNum >> K >> favorite;

        for (int j = 0; j < songNum; j++)
            cin >> length[j];

        for (int j = 0; j < songNum; j++)
            for (int k = 0; k < songNum; k++)
                cin >> T[j][k];

        vector<double> result = getProb();
        for (int j = 0; j < favorite; j++) {
            int favSong;
            cin >> favSong;

            cout.precision(8);
            cout << result[favSong] << " ";
        }
        cout << endl;

    }

    return 0;

}