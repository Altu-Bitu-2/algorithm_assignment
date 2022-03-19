#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

deque<int> cardGame(int n, vector<int>& cmd) {
    deque<int> dq;

    for (int i = 1; i <= n; i++) { //놓여 있는 위의 카드부터 검사 1, ..., n
        switch (cmd[i]) {
        case 1: //1번 기술
            dq.push_front(i);//맨 앞에 push
            break;
        case 2: { //!주의! c++에서 switch-case 문에 변수 선언 시 {} 필수!
            int x = dq.front(); //맨 앞의 것 x에 저장
            dq.pop_front(); //맨 앞(x) pop
            dq.push_front(i); //i를 맨 앞에 push
            dq.push_front(x); //x를 맨 앞에 push (x->i 순으로 i가 앞에서 두번째에 있도록)
            break;
         }
        case 3: //3번 기술
            dq.push_back(i); //맨 뒤에 push
            break;
        }//switch 끝
    }
}

/**
 * 결과값을 보고 처음 도출 -> 기술을 모두 반대로 쓰자!
 * 1. 제일 위의 카드 바닥에 내려놓기 ->
 *    바닥에 내려놓은 카드를 다시 위에 ->
 *    제일 위의 카드 앞에 넣기
 * 2. 위에서 두 번째 카드 바닥에 내려놓기 ->
 *    바닥에 내려놓은 카드 위에서 두 번째에 넣기 ->
 *    제일 위의 카드 앞에서 두번째에 넣기
 * 3. 제일 밑에 있는 카드 바닥에 내려놓기 ->
 *    바닥에 내려놓은 카드 밑에 넣기 ->
 *    제일 위의 카드 뒤에 넣기
 */

int main() {
    int n;

    //입력
    cin >> n; //카드 개수 n 입력받기
    vector<int> cmd(n + 1, 0); // 기술번호 벡터, 1부터 채우기 때문에 크기는 n+1, 0으로 초기화
    for (int i = 1; i <= n; i++) { //입력 1부터 채움
        cin >> cmd[i];
    }

    //연산
    reverse(cmd.begin() + 1, cmd.end()); //가장 위의 카드부터 검사하기 위해 기술 순서도 반대로
    deque<int> dq = cardGame(n, cmd); //deque 만들기

    //출력
    while (!dq.empty()) { //deque가 비어있을 때까지
        cout << dq.front() << ' '; //맨 앞 출력
        dq.pop_front(); //출력했으면 pop
    }
    return 0;
}