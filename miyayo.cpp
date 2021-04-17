//
// Created by shimeng on 2021/4/17.
//
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

//int main()
//{
//    int t;
//    cin >> t;
//
//    for (int it = 0; it < t; ++it) {
//        int n;
//        double p;
//        cin >> n >> p;
//        p /= 100;
//
//        vector<pair<int, int>> record(n);
//        int maxForce = 0;
//        for (int i = 0; i < n; ++i) {
//            pair<int, int> &cur = record[i];
//            cin >> cur.first >> cur.second;
//            if (cur.first > maxForce) {
//                maxForce = cur.first;
//            }
//        }
//        double limit = maxForce * p;
//        cout << "Case #" << it << ": " << endl;
//        for (auto item : record) {
//            if (item)
//        }
//    }
//
//    return 0;
//}

int m = 0;
vector<int> all;

bool dfs(vector<int> &record, int pos, int curValue) {
    if (pos >= record.size()) {
        return false;
    }

    if (curValue >= m) {
        all.push_back(curValue);
        return false;
    }

    bool flag = true;
    for (int i = pos; i < record.size() && flag; ++i) {
        curValue += record[i];
        flag = dfs(record, pos+1, curValue);
        curValue -= record[i];
    }
    return true;
}


int main()
{
    int n;
    cin >> n >> m;
    vector<int> record(n);
    for (int i = 0; i < record.size(); ++i) {
        cin >> record[i];
    }
    sort(record.begin(), record.end());

    dfs(record, 0, 0);
    sort(all.begin(), all.end());
    cout << all[0] << endl;

//
//    int res = 0;
//    for (int i = 0; i < record.size(); ++i) {
//        int temp = res + record[i];
//        if (temp < m) {
//            res = temp;
//        } else {
//            int cur = record[i];
//            while (i < record.size() && record[i] + res >= m) {
//                cur = record[i];
//                ++i;
//            }
//            res += cur;
//        }
//    }
//    cout << res << endl;

    return 0;
}