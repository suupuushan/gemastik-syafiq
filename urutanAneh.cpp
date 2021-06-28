#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int reversed(int x);

int main(){
    int n;
    cin >> n; // input banyak bilangan

    int a[n];
    string str;

    getline(cin >> ws, str);
    stringstream s(str);

    int i = 0;
    while (!s.eof()){
        s >> a[i];
        i++;
    }

    bool check = false;
    for (int j = 0; j < n; j++){
        if (a[j] <= 0 || a[j] >= 100){
            check = true;
            break;
        }
    }

    if (check){
        cout << "Input value exceeds limit!!!" << endl;
    } else {
        for (int j = 0; j < n; j++){
        a[j] = reversed(a[j]);
        }

        sort(a, a + n);

        for (int j = 0; j < n; j++){
            a[j] = reversed(a[j]);
        }

        for (int j = 0; j < n; j++){
            cout << a[j] << endl;
        }
    }

    cin.get();
    return 0;
}

int reversed(int x){
    if (x < 10){
        x = x*10;
        return x;
    }
    if (x % 10 == 0){
        x = x/10;
    }
    int rem, num = 0;
    while (x != 0){
        rem = x % 10;
        num = num * 10 + rem;
        x = x / 10;
    }
    return num;
}