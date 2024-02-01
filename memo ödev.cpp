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
        cout << "Hasta eklemek i�in yer kalmad�!" << endl;
        return;
    }

    cout << "Hasta ad�n� giriniz: ";
    cin >> ad;
    cout << "Hasta soyad�n� giriniz: ";
    cin >> soyad;
    cout << "Hasta ya��n� giriniz: ";
    cin >> yas;
    cout << "Temasl� m�? (1: Evet, 0: Hay�r): ";
    cin >> temaslimi;

    KovidHastasi yeniHasta = {ad, soyad, yas, temaslimi};
    hastalar[toplamHastaSayisi] = yeniHasta;
    toplamHastaSayisi++;

    cout << "Hasta ba�ar�yla eklendi." << endl;
}

void hastalariListele(KovidHastasi hastalar[], int toplamHastaSayisi) {
    if (toplamHastaSayisi == 0) {
        cout << "Sistemde kay�tl� hasta bulunmamaktad�r." << endl;
        return;
    }

    cout << "Kovid Hastalar�:" << endl;
    for (int i = 0; i < toplamHastaSayisi; ++i) {
        cout << hastalar[i].ad << " " << hastalar[i].soyad << ", " << hastalar[i].yas << " ya��nda";
        if (hastalar[i].temaslimi)
            cout << " - Temasl�" << endl;
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
        cout << "\nMen�:\n";
        cout << "1. Hasta Ekle\n";
        cout << "2. Hastalar� Listele\n";
        cout << "3. ��k��\n";
        cout << "Se�iminiz: ";

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
            cout << "Programdan ��k�l�yor...\n";
            return 0;
        default:
            cout << "Ge�ersiz se�im. Tekrar deneyiniz.\n";
    }
    }

    return 0;
}

