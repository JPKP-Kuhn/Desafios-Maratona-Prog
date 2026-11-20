#include <bits/stdc++.h>
using namespace std;
#define _                                                                                          \
    ios_base::sync_with_stdio(false);                                                              \
    cin.tie(NULL);                                                                                 \
    cout.tie(NULL);
#define fr first
#define sc second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LSOne(S) ((S) & -(S)) // bit menos significativo ligado, bitmask

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

class Solution {
  public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_map<int, int> m;
        for (int i = 0; i < (nums.size() / 2); i++) {
            if (nums[i] == nums[nums.size() - i - 1])
                return true;
            if (m[nums[i]] >= 1 || m[nums[nums.size() - i - 1]] >= 1)
                return true;
            m[nums[i]]++;
            m[nums[nums.size() - i - 1]]++;
        }
        if (nums.size() & 1)
            return m[nums[nums.size() / 2]] >= 1;

        return false;
    }
};
int main() {
    _ Solution *s = new Solution;
    vector<int> n = {2, 2, 11};
    bool f = s->containsDuplicate(n);
    cout << f << '\n';

    return 0;
}
