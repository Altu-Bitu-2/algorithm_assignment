#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T,N, M, input;

    cin >> T;
    //T번만큼 테스트
    for (int i = 0; i < T; i++) {
        cin >> N;
        set<int> s;
	
	//set에 저장
        for (int j = 0; j < N; j++) {
            cin >> input;
            s.insert(input);
        }
	
	//있는지 확인
        cin >> M;
        for (int j = 0; j < M; j++) {
            cin >> input;
            if (s.end() == s.find(input)) //없으면
                cout << 0 << '\n';
            else //있으면
                cout << 1 << '\n';
        }
    }
  
    return 0;
}