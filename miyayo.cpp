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




int main()
{
    int m, n;
    cin >> n >> m;
    vector<int> record(n);
    for (int i = 0; i < record.size(); ++i) {
        cin >> record[i];
    }
    sort(record.begin(), record.end(), greater<>());

    int res = 0;
    for (int i = 0; i < record.size(); ++i) {
        int temp = res + record[i];
        if (temp < m) {
            res = temp;
        } else {
            int cur = record[i];
            while (i < record.size() && record[i] + res >= m) {
                cur = record[i];
                ++i;
            }
            res += cur;
        }
    }
    cout << res << endl;

    return 0;
}