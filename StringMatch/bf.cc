#include <iostream>
#include <string>
using namespace std;

int bf(string str, string sub) {
    int n = str.length();
    int m = sub.length();

    for (int i = 0; i <= n - m; ++i) {
        int j = 0; 
        for (; j < m; ++j) {
            if (str[i + j] != sub[j])
                break;
        }

        if(j == m)
            return i;
    }

    return -1;
}

int main() {
    string s1("helloworld");
    string s2("he");
    cout << bf(s1, s2) << endl; // 0

    return 0;
}