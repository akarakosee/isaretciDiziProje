#include <iostream>
#include <iomanip>
#include<string>

using namespace std;

// Ogrenci sınıfı tanımlanıyor
class Ogrenci
{
public:
	// Ogrenci sınıfının yapıcı fonksiyonu
	Ogrenci()
	{
		// Ogrenci numarası ve sınıfı rastgele atanıyor
		this->numara = 1000 * (1 + rand() % 3) + rand() % 999;
		this->sinif = 1 + rand() % 4;
	}
	// Ogrenci numarasını döndüren fonksiyon
	int numaraGetir() const
	{
		return numara;
	}
	// Ogrenci sınıfını döndüren fonksiyon
	int sinifGetir() const
	{
		return sinif;
	}
	// Ogrenci sınıfını yazdırmak için << operatörünü aşırı yüklüyoruz
	friend ostream& operator<<(ostream& os, const Ogrenci& ogrenci)
	{
		os << setw(5) << ogrenci.numaraGetir() << "-" << setw(4) << std::right << ogrenci.sinifGetir();
		return os;
	}
private:
	// Ogrenci sınıfının özel üye değişkenleri
	int numara;
	int sinif;
};

// Dizideki tüm öğrencileri NULL ile başlatan fonksiyon
void diziSifirla(Ogrenci** dizi, int ogrenciSayisi)
{
	for (int i = 0; i < ogrenciSayisi; i++)
	{
		dizi[i] = NULL;
	}
}

// Belirli bir sıradaki öğrenciyi silen fonksiyon
void ogrenciSil(Ogrenci** dizi, int ogrenciSayisi)
{
	cout << "sira girin:";
	int sira;
	cin >> sira;
	if (sira < ogrenciSayisi && sira >= 0)
	{
		if (dizi[sira] != NULL)
		{
			delete dizi[sira];
			dizi[sira] = NULL;
		}
		else
		{
			cout << "HATA!! Sira Bos" << endl;
		}
	}
	else
	{
		cout << "HATA!! sinir disinda" << endl;
	}
}

// Belirli bir sıraya yeni bir öğrenci ekleyen fonksiyon
void ogrenciEkle(Ogrenci** dizi, int ogrenciSayisi)
{
	cout << "sira girin:";
	int sira;
	cin >> sira;
	if (sira < ogrenciSayisi && sira >= 0)
	{
		if (dizi[sira] == NULL)
		{
			dizi[sira] = new Ogrenci();
		}
		else
		{
			cout << "HATA!! Sira Dolu" << endl;
		}
	}
	else
	{
		cout << "HATA!! sinir disinda" << endl;
	}
}

// Diziyi ve içindeki tüm öğrencileri silen fonksiyon
void diziYokEt(Ogrenci** dizi, int ogrenciSayisi)
{
	for (int i = 0; i < ogrenciSayisi; i++)
	{
		if (dizi[i])
		{
			delete dizi[i];
		}
	}
	delete[] dizi;
}

// Diziyi yazdıran fonksiyon
void diziYazdir(Ogrenci** dizi, int ogrenciSayisi)
{
	cout << setw(8) << std::left << "indeks" << setw(2) << "|" << setw(10) << "icerik" << setw(2) << "|" << setw(10) << "gosterilen" << endl;
	for (int i = 0; i < ogrenciSayisi; i++)
	{
		cout << setw(5) << std::left << "dizi[" << i << "] " << setw(2) << "|" << setw(10) << dizi[i] << setw(2) << "|";

		if (dizi[i])
		{
			cout << setw(10) << *dizi[i] << endl;

		}
		else
		{
			cout << setw(10) << "----------" << endl;

		}
	}
}

// Ana fonksiyon
int main()
{
	int ogrenciSayisi = 10;
	// Ogrenci işaretçisi dizisi oluşturuluyor
	Ogrenci** ogrenciListesi = new Ogrenci * [ogrenciSayisi];
	
	// Dizideki tüm öğrenciler NULL ile başlatılıyor
	diziSifirla(ogrenciListesi, ogrenciSayisi);

	// Menü döngüsü
	while (true)
	{
		// Dizi yazdırılıyor
		diziYazdir(ogrenciListesi, ogrenciSayisi);
		cout << "1. ogrenci ekle" << endl;
		cout << "2. ogrenci sil" << endl;
		cout << "3. cikis" << endl;
		int secim;
		cin >> secim;
		if (secim == 1)
		{
			// Yeni bir öğrenci ekleniyor
			ogrenciEkle(ogrenciListesi, ogrenciSayisi);
		}
		else if (secim == 2)
		{
			// Belirli bir sıradaki öğrenci siliniyor
			ogrenciSil(ogrenciListesi, ogrenciSayisi);
		}
		else if (secim == 3)
		{
			// Dizi ve içindeki tüm öğrenciler siliniyor
			diziYokEt(ogrenciListesi, ogrenciSayisi);
			break;
		}
		else
		{
			cout << "Yaptiginiz secim menude bulunmuyor" << endl;
			cout << "Tekrar Secim Yapiniz" << endl;
		}
	}
}
