#include <iostream>
#include <vector>

using namespace std;

//function untuk mengecek apakah gradien sudah ada atau belum
bool cek_gradien(vector<float> g, int m)
{
  for (int v : g)
  {
    if (v==m)
    return true;
  }
  return false;
}

int main() {
  vector<float> g1, g2; // 2 buah vector yang menyimpan nilai gradien tiap2 pohon terhadap posisi pak blangkon
  int n, x, y;
  cin >> n >> x >> y; // input banyak pohon dan posisi Pak Blangkon
  int a, b, jumlah_pohon = 0;
  for (int i = 0; i < n; i++) {
    cin >> a >> b; // input posisi pohon
    float m = (b - y) / (a - x); // rumus
    if (a >= x) {
      if (!cek_gradien(g2, m))
      {
        g2.push_back(m); // menambah m ke posisi akhir vektor
        jumlah_pohon++;
      }
    }
    else {
      if (!cek_gradien(g1, m))
      {
        g1.push_back(m); // menambah m ke posisi akhir vektor
        jumlah_pohon++;
      }
    }
  }
  cout << jumlah_pohon << endl;
  cin.get();
  return 0;
}