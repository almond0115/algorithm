#include <bits/stdc++.h>

using namespace std;

int N, M;
map<string, int> pocketmons;
string name, question;

// 1 <= N, M <= 100,000

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for(int i=0 ; i<N ; i++) {
        cin >> name;
        pocketmons[name] = i+1;
    }

    // 시간 초과 발생? M(10만) x N(10만) 
    for(int i=0 ; i<M ; i++) {
        cin >> question;

        // int, string 어떻게 구분? isdigit()
        // isdigit은 char 타입만 판별하므로 question이 아닌 question[0]이 되어야 함
        if (isdigit(question[0])){
            // const auto& 형식? map의 각 pair 반복
            // string -> int 정수 변환? stoi or atoi
            int index = stoi(question);
            // 각 반복에서 pokemon은 indexToPokemon의 각 항목을 나타내는 쌍(Pair)
            for(const auto& pocketmon : pocketmons) {
                if(pocketmon.second == index) {
                    cout << pocketmon.first << '\n';
                    break;
                }
            }    
        } else {
            cout << pocketmons[question] << '\n';
        }
    }

    return 0;
}