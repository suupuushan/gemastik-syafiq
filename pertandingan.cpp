#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int n, m, temp;
    cin >> n >> m; // input banyak lawan dan kemahiran awal

    // membuat array kosong
    int A[n];
    int B[n];

    for (int i = 0; i < n; i++){
        cin >> A[i]; // input nilai ketangkasan lawan
    }

    for (int i = 0; i < n; i++){
        cin >> B[i]; // input nilai pertambahan ketangkasan untuk tiap lawan
    }

    // melakukan mapping untuk setiap ketangkasan lawan dan nilai pertambahannya
    map<int, int> op;
    for (int i = 0; i < n; i++){
        op.insert(pair<int, int>(A[i], B[i]));
    }

    sort(A, A + n); // sorting nilai yang terdapat di array A dari terkecil ke terbesar

    for (int i = 0; i < n; i++){
        if(m >= A[i]){
            m += op[A[i]]; // menambah ketangkasan jika ketangkasan saat ini lebih besar dari lawan
        } else {
            break;
        }
    }

    cout << m << endl;

    cin.get();
    return 0;
}