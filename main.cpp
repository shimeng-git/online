#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include <sstream>
using namespace std;



int main()
{
    set<int> data;
    string temp;
    bool flag = false;
    int target = 0;
    while (cin >> temp) {
        if (flag) {
            target = stoi(temp);
            break;
        }

        if (temp != "#") {
            data.insert(stoi(temp));
        } else {
            flag = true;
        }
    }

    set<pair<int, int>> res;
    for (int item : data) {
        if (data.find(target - item) != data.end()) {
            res.insert({min(item, target - item), max(item, target-item)});
        }
    }

    if (res.empty()) {
        cout << "NULL" << endl;
    } else {
        cout << "(" << res.begin()->first << "," << res.begin()->second << ")";
        for (auto it = ++res.begin(); it != res.end(); ++it) {
            cout << ",(" << it->first << "," << it->second << ")";
        }
    }

    return 0;
}


//2 3
//585 375
//936 317 185
//int main()
//{
//    int n, m;
//    cin >> n >> m;
//    vector<int> first(n);
//    vector<int> second(m);
//
//    for (int i = 0; i < n; ++i) {
//        cin >> first[i];
//    }
//
//    for (int i = 0; i < m; ++i) {
//        cin >> second[i];
//    }
//
//    sort(first.begin(), first.end());
//    sort(second.begin(), second.end());
//    set<int> limit;
//    for (int item : second) {
//        limit.insert(item - 1);
//        limit.insert(item);
//        limit.insert(item + 1);
//    }
//
//    int res = 0;
//    for (int d : limit) {
//        auto f = upper_bound(first.begin(), first.end(), d);
//        int first_cnt = (first.end() - f);
//        first_cnt += n;
//
//        auto s = upper_bound(second.begin(), second.end(), d);
//        int second_cnt = (second.end() - s);
//        second_cnt += m;
//
//        int score = abs(first_cnt - second_cnt);
//
//        if (score > res) {
//            res = score;
//        }
//    }
//
//    cout << res << endl;
//
//    return 0;
//}




int forth()
{
    int n;
    cin >> n;
    string str;
    cin >> str;

    int res = 0;
    for (int left = 0; left < n; ++left) {
        for (int right = left + 1; right < n; ++right) {
            char x = 0;
            int votes = 0;
            int cnt = 0;
            for (int i = left; i <= right; ++i) {
                if (votes == 0) {
                    x = str[i];
                }
                votes += str[i] == x ? 1 : -1;
            }

            for (int i = left; i <= right; ++i) {
                if (str[i] == x) {
                    ++cnt;
                }
            }

            if (cnt > (right - left + 1) / 2) {
                ++res;
            }
        }
    }
    cout << res+n << endl;

    return 0;
}



int get_cnt(char a, char b, char c, char target) {
    int cnt = 0;
    if (a == 'x' || b == 'x' || c == 'x') {
        return cnt;
    }

    if (a == target) {
        cnt += 1;
    }
    if (b == target) {
        cnt += 1;
    }
    if (c == target) {
        cnt += 1;
    }
    return cnt;
}

int third()
{
    int n;
    cin >> n;
    string str;
    cin >> str;

    vector<char> op {'0', '1'};
    int res = 0;
    for (char ch : op) {
        int one = 0;
        int zero = 0;
        string temp(str);

        for (int i = 0; i < n-2; ++i) {
            int cnt = get_cnt(temp[i], temp[i+1], temp[i+2], ch);
            if (cnt == 3) {
                temp[i] = 'x';
                temp[i + 1] = 'x';
                temp[i + 2] = 'x';
            }
        }
        for (int i = 0; i < n-2; ++i) {
            int cnt = get_cnt(temp[i], temp[i+1], temp[i+2], ch);
            if (cnt == 2) {
                temp[i] = 'x';
                temp[i + 1] = 'x';
                temp[i + 2] = 'x';
            }
        }

        for (char item : temp) {
            one += (item == '1');
            zero += (item == '0');
        }

        if (abs(one - zero) > res) {
            res = abs(one - zero);
        }
    }

    cout << res << endl;

    return 0;
}



/**
 * 美团第一题
 * @return
 */
int first()
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

    double min_value = 1e10;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        double value = 0;
        if (record.find(i) == record.end() && arr[i] <= k) {
            for (int it : record) {
                value += abs(it - i);
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