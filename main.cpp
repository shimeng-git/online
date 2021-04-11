#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<stack>
#include<queue>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n, 0);
    set<int> record;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (arr[i] == 0) {
            record.insert(i);
        }
    }

    double value = 0;
    double min_value = 1e10;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (record.find(i) == record.end() && arr[i] <= k) {
            for (int it : record) {
                value += (it - i);
            }
            value = abs(value);
            if (value < min_value) {
                min_value = value;
                res = i;
            }
        }
    }

    cout << res + 1 << endl;

    return 0;
}






//int main() {
//    int n;
//    cin >> n;
//    vector<vector<int>> record(n, vector<int> (2, 0));
//    for (int i = 0; i < n; ++i) {
//        cin >> record[i][0] >> record[i][1];
//    }
//
//    sort(record.begin(), record.end(), [](auto a, auto b) -> bool {
//        if (a[0] < b[0]) {
//            return true;
//        } else {
//            return false;
//        }
//    });
//
//    int time = record[0][0];
//    for (int i = 0; i < n; ++i) {
//        if (record[i][0] >= time) {
//            time += record[i][1];
//        } else {
//            time += (record[i][0] - time + 1);
//        }
//    }
//    cout << time << endl;
//
//
//    return 0;
//}


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