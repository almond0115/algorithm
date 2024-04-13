#include <bits/stdc++.h>

using namespace std;

int N, M;
int n, ret;
vector<int> nums, chosen;

void combinations(vector<int>& nums, vector<int>& chosen, int index, int k, int M){
    if(k == 0){
        // k개 원소가 선택되었으므로 결과 출력
        int sum = 0;
        for(int num : chosen) {
            sum += num;
        }

        if (sum == M) ret++;
        
        return;
    }

    // 재귀 호출을 통해 조합 생성
    for(int i= index ; i < nums.size() ; ++i) {
        chosen.push_back(nums[i]); // 현재 원소 선택
        combinations(nums, chosen, i+1, k-1, M); // 다음 원소 선택을 위해 재귀 호출
        chosen.pop_back(); // 백 트래킹
    }
}

int main() {
    // 재료 개수 (1 <= N <= 15,000)
    cin >> N;

    // 갑옷 만드는데 필요한 수 (1<= M <= 10,000,000)
    cin >> M;

    int k = 2;

    for (int i=0 ; i<N ; i++) {
        cin >> n;
        nums.push_back(n);
    }

    combinations(nums, chosen, 0, k, M);

    cout << ret;

    return 0;
}