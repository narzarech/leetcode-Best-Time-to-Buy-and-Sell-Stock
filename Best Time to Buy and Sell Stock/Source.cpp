#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        for (unsigned i = 0; i < prices.size() - 1; ++i) {
            prices[i] = prices[i + 1] - prices[i];
        }
        int prev_max = 0, prev_subarr = 0;
        for (unsigned i = 0; i < prices.size() - 1; ++i) {
            if (prev_subarr < 0) {
                prev_subarr = prices[i];
            }
            else {
                prev_subarr += prices[i];
            }
            if (prev_subarr > prev_max) {
                prev_max = prev_subarr;
            }
        }
        return prev_max;
    }
};
int main() {
    vector<int>prices;
    int tmp;
    while (cin >> tmp) {
        prices.push_back(tmp);
    }
    Solution sol;
    cout << sol.maxProfit(prices);
}