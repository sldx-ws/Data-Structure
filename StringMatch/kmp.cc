#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> getNext(const string& sub) {
    int m = sub.length();
    vector<int> next(m, 0);
    int j = 0;
    for (int i = 1; i < m; ++i) {
        while (j > 0 && sub[i] != sub[j]) 
            j = next[j - 1];
 
        if (sub[i] == sub[j])
            ++j;

        next[i] = j;
    }
    
    return next;
}

int kmp(const string& str, const string& sub) {
    vector<int> ret;
    int n = str.length();
    int m = sub.length();
    vector<int> next = getNext(sub);

    int i = 0; // str 的指针
    int j = 0; // sub 的指针
    while (i < n) {
        if (sub[j] == str[i]) {
            ++i;
            ++j;
        }
        
        if (j == m) {
            return i - j;
        } else if (i < n && sub[j] != str[i]) {
            if (j != 0)
                j = next[j - 1];
            else
                ++i;
        }
    }

    return -1;
}

int main() {
    string sub, str;
    cin >> str >> sub ;

    cout << kmp(str, sub) << endl;
    
    return 0;
}