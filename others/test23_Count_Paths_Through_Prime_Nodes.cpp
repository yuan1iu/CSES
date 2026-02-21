#include <vector>
using namespace std;
class Solution {
   public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        vector<bool> prime(n + 1, true);  // 是否為質數
        prime[0] = prime[1] = false;
        for (int i = 0; i * i <= n; i++) {
            if (!prime[i]) continue;
            for (int j = 2 * i; j <= n; j++) {
                prime[j] = false;
            }
        }
        return 0;
    }
};

int main() {
    Solution s;

    // s.countPaths();
    return 0;
}
