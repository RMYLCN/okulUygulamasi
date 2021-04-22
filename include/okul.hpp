/****************************************************************************
**             SAKARYA UNIVERSITY 
**        BILGISAYAR MUHENDISLIGI BOLUMU 
**          NESNEYE DAYALI PROGRAMLAMA  
**     
**    OGRENCI ISMI.....: Irem Yalcin
**    OGRENCI NUMARASI.: G171210026
****************************************************************************/ 


#ifndef OKUL_HPP
#define OKUL_HPP

#include <sinif.hpp>

class Okul
{
	public:
			Okul(int numara,int id);
			okulYazdir();
			ogrenciEkle(int numara);
			ogrenciSil();
			okulMenu(int numara);
			ogrenciBul(int secilenSinif,int secilenOgrenci,Dugum *&degisen,Dugum *&atanacak);
			ogrenciDegistir(int secilenSinif,int secilenOgrenci,Dugum *&degisen,Dugum *&atanacak);
			okulSil();
			Sinif *ilkSinif;
			Sinif *ikinciSinif;
			Sinif *Siniflar[];
};


#endif