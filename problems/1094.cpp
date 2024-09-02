// https://cses.fi/problemset/task/1094
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &num: nums) {
        cin >> num;
    }
    ll res = 0;
    for (int i = 1; i < n; i++) {
        if (nums[i] < nums[i-1]) {
            res += nums[i-1] - nums[i];
            nums[i] = nums[i-1];
        }
    }
    cout << res << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}