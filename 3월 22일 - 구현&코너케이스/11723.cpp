#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int SIZE = 21;

/**
 * [집합] - 단순 구현 문제
 *
 * ver1. 배열 사용 풀이
 * set()을 사용해서 매번 연산을 하면 시간이 굉장히 오래 걸려요.
 * 입력되는 x의 값이 1~20으로 범위가 매우 작기 때문에, 각 숫자가 집합에 들어있는 여부를 저장하는 배열을 이용합니다.
 *
 * 1. 집합에는 1~20의 숫자만 입력 or 제거됨 (=true or false)
 * 2. 크기 21의 bool 배열을 선언
 * 3. 입력은 true 처리, 제거는 false 처리
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, num; //연산의 수 m, 피연산자 num
    string cmd; //명령 입력받을 문자열 cmd
    vector<bool> s(SIZE, false);

    cin >> m; //연산 수 입력
    while (m--) { //m번만큼 반복
        cin >> cmd; //문자열 입력받기
        if (cmd == "all") { //all  연산이라면
            s.assign(SIZE, true); //모든 원소가 있으므로 모두 true로 바꿈
            continue;
        }
        if (cmd == "empty") { //empty 연산이라면
            s.assign(SIZE, false); //모든 원소가 없으므로 모두 false로 바꿈
            continue;
        }

        cin >> num; //all이나 empty가 아니라면 숫자를 입력받음
        if (cmd == "add") { //add 연산이라면 
            s[num] = true; //입력받은 숫자를 true로 바꿈
            continue;
        }
        if (cmd == "remove") { //remove 연산이라면
            s[num] = false; //입력받은 숫자를 제거하는 것이므로 false로 바꿈
            continue;
        }
        if (cmd == "check") { //check연산이라면 num이 있는지 확인하고 있으면 1 없으면 0 출력
            cout << s[num] << '\n'; //bool 형을 출력하면 true: 1, false: 0으로 출력
            continue;
        }
        if (cmd == "toggle") {  //toggle이라면
            s[num] = !s[num]; //지금 있는 상태의 반대 상태(true면 false, false이면 true)로 업데이트
            continue;
        }
    }
    return 0;
}