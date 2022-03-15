#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string input, sub;
    map <string, int> file;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input;
        //확장자 분리
        size_t pos = input.rfind('.'); 
        sub = input.substr(pos+1);
        //해당하는 확장자 개수 추가
        file[sub]++;
    }

    //map 출력
    map<string, int>::iterator iter;
    for (iter = file.begin(); iter != file.end(); ++iter)
        cout << iter->first << ' ' << iter->second << '\n';
    return 0;
}