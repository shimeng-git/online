#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
#include<stack>
#include<queue>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<long long> data(n);
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }
    if (n < 3) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> bottom;
    if (data[0] < data[1]) {
        bottom.push_back(0);
    }
    for (int i = 1; i < n - 1; ++i) {
        if (data[i] < data[i - 1] && data[i] < data[i + 1]) {
            bottom.push_back(i);
        }
    }
    if (data[n-1] < data[n-2]) {
        bottom.push_back(n-1);
    }

    int res = 0;
    for (int i = 1; i < bottom.size(); ++i) {
        res = max(bottom[i] - bottom[i - 1] + 1, res);

    }
    cout << res << endl;

    return 0;
}