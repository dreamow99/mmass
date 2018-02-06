#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <stack>
#define maxn 1000001
#define maxc 1000000001

using namespace std;

int n, ans;
string a;
stack <int> s;

int convert(char c)
{
    if (c == 'C') return 12;
    if (c == 'O') return 16;
    else return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("mmass.inp", "r", stdin);
    //freopen("mmass.out", "w", stdout);
    cin >> a;
    n = a.length()-1;
    for (int i = 0; i <= n; i++)
    {
        if (a[i] == '('){
            s.push(0);
            continue;
        }
        if (a[i] == 'C' || a[i] == 'H' || a[i] == 'O'){
            s.push(convert(a[i]));
            continue;
        }
        if (a[i] >= '2' && a[i] <= '9'){
            int last = s.top();
            s.pop();
            last *= (a[i] - 48);
            s.push(last);
        }
        if (a[i] == ')'){
            int tong = 0;
            while (s.top()){
                tong += s.top();
                s.pop();
            }
            s.pop();
            s.push(tong);
            tong = 0;
        }
    }
    ans = 0;
    while (!s.empty()){
        ans += s.top();
        s.pop();
    }
    cout << ans;
    return 0;
}