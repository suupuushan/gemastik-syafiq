#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

// deklarasi fungsi reversed
int reversed(int x);

int main(){
    int n;
    cin >> n; // input banyak bilangan

    int a[n]; // insialisasi array
    string str;

    getline(cin >> ws, str); // membaca input
    stringstream s(str);

    // menambahkan input ke array
    int i = 0;
    while (!s.eof()){
        s >> a[i];
        i++;
    }
    
    // pengecekan apakah ada nilai yang <= 0 atau >= 100
    bool check = false;
    for (int j = 0; j < n; j++){
        if (a[j] <= 0 || a[j] >= 100){
            check = true;
            break;
        }
    }

    if (check){
        cout << "Input value exceeds limit!!!" << endl; // pesan error
    } else {
        // membalik semua nilai, ex 21 => 12
        for (int j = 0; j < n; j++){
            a[j] = reversed(a[j]);
        }

        sort(a, a + n); // mengurutkan nilai yang sudah dibalik

        // membalik kembali nilai yang sudah diurutkan
        for (int j = 0; j < n; j++){
            a[j] = reversed(a[j]);
        }

        // menampilkan output
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