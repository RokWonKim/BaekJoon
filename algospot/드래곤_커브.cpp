#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<cassert>

using namespace std;

const int INF = 1000*1000*1000+100;
const string Xgo = "X+YF";
const string Ygo = "FX-Y";

int n,p,l;
int len[51];

void calc() {
    len[0] = 1;
    for(int i = 1; i < 51; i++)
        len[i] = min(INF, len[i-1]*2 +2 );
}

char expand(const string& dragon,int gen ,int skip) {

    if (gen == 0) {
        return dragon[skip]; 
    }

    for (int i = 0; i < dragon.size(); i++) {
        if (dragon[i] == 'X' || dragon[i] == 'Y') {
            if (skip >= len[gen])
                skip -= len[gen];
            else if (dragon[i] == 'X')
                return expand(Xgo, gen-1, skip);
            else
                return expand(Ygo, gen-1, skip);
        }
        else if( skip > 0) --skip;
        else return dragon[i];
    }
    return '#';
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    calc();
    while(T--) {
        cin >> n >> p >> l;
        for (int i = 0; i < l; i++) {
            cout << expand("FX", n, p+i-1);
        }
        cout << '\n';
    }

    return 0;
}