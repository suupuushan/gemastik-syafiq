#include <bits/stdc++.h>

using namespace std;

// deklarasi fungsi
int reversed(int x);
bool check(int a[], int n);

int main(){
    int n;
    cin >> n; // input banyak bilangan

    int a[n]; // insialisasi array

    // menambahkan input ke array
    for (int i = 0; i<n; i++) cin >> a[i];

    if (check(a, n)){
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

//fungsi membalik angka
int reversed(int x){
    if (x < 10){
        x = x*10;
        return x;
    } else if (x % 10 == 0){
        x = x/10;
        return x;
    } else {
        int rem, num = 0;
        while (x != 0){
            rem = x % 10;
            num = num * 10 + rem;
            x = x / 10;
        }
        return num;
    }
}

// fungsi pengecekan apakah ada nilai yang <= 0 atau >= 100
bool check(int a[], int n){
    for (int i = 0; i < n; i++){
        if (a[i] <= 0 || a[i] >= 100){
            return true;
        }
    }
    return false;
}