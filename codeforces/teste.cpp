#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t; // número de casos de teste
    while (t--) {
        int n, r;
        cin >> n >> r; // número de famílias e número de fileiras
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        int singleSeats = r;      // fileiras onde uma pessoa pode ficar sozinha e ficar feliz
        int pairSeats = r;        // fileiras onde duas pessoas da mesma família podem sentar juntas
        int happyPeople = 0;

        vector<int> individuals;  // membros individuais restantes depois de formar pares

        for (int i = 0; i < n; ++i) {
            int pairs = a[i] / 2;
            int remaining = a[i] % 2;

            // Usar pares completos se houver assentos suficientes
            int usePairs = min(pairs, pairSeats);
            happyPeople += usePairs * 2;
            pairSeats -= usePairs;

            int leftover = a[i] - usePairs * 2;
            while (leftover--) {
                individuals.push_back(1);
            }
        }

        // Agora tentar colocar os indivíduos restantes em assentos solos
        int useSingles = min((int)individuals.size(), singleSeats);
        happyPeople += useSingles;
        // os outros indivíduos não conseguem ficar felizes

        cout << happyPeople << endl;
    }
    return 0;
}

