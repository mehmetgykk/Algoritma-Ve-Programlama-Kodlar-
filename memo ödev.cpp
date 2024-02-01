#include <iostream>
#include <string>

using namespace std;


struct KovidHastasi {
    string ad;
    string soyad;
    int yas;
    bool temaslimi;
};


void hastaEkle(KovidHastasi hastalar[], int & toplamHastaSayisi) {
    string ad, soyad;
    int yas;
    bool temaslimi;

    if (toplamHastaSayisi >= 100) {
        cout << "Hasta eklemek için yer kalmadý!" << endl;
        return;
    }

    cout << "Hasta adýný giriniz: ";
    cin >> ad;
    cout << "Hasta soyadýný giriniz: ";
    cin >> soyad;
    cout << "Hasta yaþýný giriniz: ";
    cin >> yas;
    cout << "Temaslý mý? (1: Evet, 0: Hayýr): ";
    cin >> temaslimi;

    KovidHastasi yeniHasta = {ad, soyad, yas, temaslimi};
    hastalar[toplamHastaSayisi] = yeniHasta;
    toplamHastaSayisi++;

    cout << "Hasta baþarýyla eklendi." << endl;
}

void hastalariListele(KovidHastasi hastalar[], int toplamHastaSayisi) {
    if (toplamHastaSayisi == 0) {
        cout << "Sistemde kayýtlý hasta bulunmamaktadýr." << endl;
        return;
    }

    cout << "Kovid Hastalarý:" << endl;
    for (int i = 0; i < toplamHastaSayisi; ++i) {
        cout << hastalar[i].ad << " " << hastalar[i].soyad << ", " << hastalar[i].yas << " yaþýnda";
        if (hastalar[i].temaslimi)
            cout << " - Temaslý" << endl;
        else
            cout << endl;
    }
}

int main() 
{
	setlocale(LC_ALL,"Turkish");
    KovidHastasi hastalar[100];
    int toplamHastaSayisi = 0;

    while (true) {
        cout << "\nMenü:\n";
        cout << "1. Hasta Ekle\n";
        cout << "2. Hastalarý Listele\n";
        cout << "3. Çýkýþ\n";
        cout << "Seçiminiz: ";

        int secim;
        cin >> secim;

    switch (secim)
	{
        case 1:
            hastaEkle(hastalar, toplamHastaSayisi);
            break;
        case 2:
            hastalariListele(hastalar, toplamHastaSayisi);
            break;
        case 3:
            cout << "Programdan çýkýlýyor...\n";
            return 0;
        default:
            cout << "Geçersiz seçim. Tekrar deneyiniz.\n";
    }
    }

    return 0;
}

