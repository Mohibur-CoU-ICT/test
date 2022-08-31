// CF_1722D. Line
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void print (vector<int>&v) {
    for(int a : v) {
        cout << a << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n;
    string s;
    cin >> t;
    while(t--) {
        cin >> n >> s;
        vector<int>L, R;
        ll value = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == 'L') {
                value += i;
                L.push_back(i);
            }
            else if(s[i] == 'R') {
                value += n - i - 1;
                R.push_back(i);
            }
            cout << value << " ";
        }
        cout << "\nInitial value = " << value << "\n";
        print(L); print(R);
        int x = 0, y = R.size() - 1;
        for(int i=0; i<n; i++) {
            int left = 0;
            int right = 0;
            if(x < L.size()) {
                left = max(left, n-L[x]-1);
            }
            if(y >= 0) {
                right = max(right, R[y]);
            }
            cout << "\nx, L[x], left, y, R[y], right = "<<x<<" "<<L[x]<<" "<<left<<" "<<y<<" "<<R[y]<<" "<<right<<"\n";
            if(left > right) {
                value -= L[x]; // delete previous contributions
                cout << "sub = " << L[x] << " add = " << left << "\n";
                value += left;
                x++;
            }
            else {
                value -= (n - R[y] - 1); // delete previous contributions
                cout << "sub = " << (n - R[y] - 1) << " add = " << right << "\n";
                value += right;
                y--;
            }
            cout << value << " ";
        }
        cout << "\n";
    }

    return 0;
}
