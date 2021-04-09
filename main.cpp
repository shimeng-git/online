#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
#include<stack>
#include<queue>
using namespace std;

vector<long long> prime {0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

vector<long long> idx(109, 0);
vector<long long> cnt(109, 0);

// -----------------------------------------------------

#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
#include<stack>
#include<queue>
using namespace std;

bool check(long long n) {
    int cnt = 0;
    vector<int> record(10, 0);
    while (n) {
        long long temp = n % 10;
        n /= 10;
        if (temp != 0 && temp != 1) {
            if (record[temp] == 0) {
                ++cnt;
                record[temp] = 1;
            }
            if (cnt > 1) {
                return false;
            }
        }
    }
    return true;
}


int main()
{
    long long n;
    cin >> n;

    bool flag = false;
    for (unsigned long long i = 1; i < 100; ++i) {
        long long temp = (long long) i * n;
        if (check(temp)) {
            cout << i * n << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}

// -----------------------------------------------------



//long long getCnt(long long p, long long x) {
//    long long res = 0;
//    while (x) {
//        res += (x/p);
//        x /= p;
//    }
//    return res;
//}
//
//int main() {
//    long long n, m;
//    cin >> n >> m;
//    long long temp = m;
//    for (int i = 1; i <= 25; ++i) {
//        while (temp % prime[i] == 0) {
//            idx[prime[i]] += 1;
//            temp /= prime[i];
//        }
//    }
//
//    for (int i = 1; i <= 25; ++i) {
//        if (idx[prime[i]]) {
//            cnt[prime[i]] = getCnt(prime[i], n);
//        }
//    }
//
//    long long res = 1e18+1;
//    for (int i = 1; i <= 25; ++i) {
//        if (idx[prime[i]]) {
//            res = min(res, cnt[prime[i]] / idx[prime[i]]);
//        }
//    }
//
//    cout << res << endl;
//
//    return 0;
//
//}


















/**
 * 第二题
 * @param n
 * @return
 */
//bool check(long long n) {
//    int cnt = 0;
//    vector<int> record(10, 0);
//    while (n) {
//        long long temp = n % 10;
//        n /= 10;
//        if (temp != 0 && temp != 1) {
//            if (record[temp] == 0) {
//                ++cnt;
//                record[temp] = 1;
//            }
//            if (cnt > 1) {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//
//
//int main()
//{
//    long long n;
//    cin >> n;
//
//    bool flag = false;
//    for (unsigned long long i = 1; i < 100; ++i) {
//        long long temp = (long long) i * n;
//        if (check(temp)) {
//            cout << i * n << endl;
//            return 0;
//        }
//    }
//    cout << -1 << endl;
//
//    return 0;
//}





/**
 * 第一题
 * @return
 */
//int main() {
//    int n;
//    cin >> n;
//    vector<long long> data(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> data[i];
//    }
//    if (n < 3) {
//        cout << 0 << endl;
//        return 0;
//    }
//
//    vector<int> bottom;
//    if (data[0] < data[1]) {
//        bottom.push_back(0);
//    }
//    for (int i = 1; i < n - 1; ++i) {
//        if (data[i] < data[i - 1] && data[i] < data[i + 1]) {
//            bottom.push_back(i);
//        }
//    }
//    if (data[n-1] < data[n-2]) {
//        bottom.push_back(n-1);
//    }
//
//    int res = 0;
//    for (int i = 1; i < bottom.size(); ++i) {
//        res = max(bottom[i] - bottom[i - 1] + 1, res);
//
//    }
//    cout << res << endl;
//
//    return 0;
//}

