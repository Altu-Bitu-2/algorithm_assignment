#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * [N번째 큰 수]
 *
 * 메모리 제한이 있으므로, 입력값을 모두 저장하면 안된다.
 * 상위 n개만 저장하는 "최소" 힙을 만들어서 heap[0]을 현재까지의 N번째 큰수로 유지하는 풀이
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, input;
    priority_queue<int, vector<int>, greater<>> pq; //최소 힙, 정렬이랑 반대

    cin >> n; //n 입력받기
    int size = n * n;   //표의 크기는 nxn
    while (size--) { //사이즈만큼 반복
        //입력
        cin >> input; //정수 입력받기

        //연산
        pq.push(input); //최소 힙에 입력받은 값 저장
        if (pq.size() > n) { //최소 힙의 크기가 n 이상이라면 가장 작은 값 삭제
            pq.pop(); //가장 작은 값 삭제
        }
    }

    //출력
    cout << pq.top(); //n번째 큰 수 출력 (가장 위에 있는 것이 n개 중에 가장 작은 값)
    return 0;
}