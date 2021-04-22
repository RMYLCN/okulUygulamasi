/****************************************************************************
**             SAKARYA UNIVERSITY 
**        BILGISAYAR MUHENDISLIGI BOLUMU 
**          NESNEYE DAYALI PROGRAMLAMA  
**     
**    OGRENCI ISMI.....: Irem Yalcin
**    OGRENCI NUMARASI.: G171210026
****************************************************************************/ 

#ifndef SINIF_HPP
#define SINIF_HPP

#include "dugum.hpp"
#include "ogrenci.hpp"

class Sinif
{
	public:
		Sinif(int *numara,int id);
		sinifYazdir();
		ogrenciEkle(int *numara);
		ogrenciSil(int deger);
		ogrenciBul(int deger,Dugum *&degisen,Dugum *&atanacak);
		ogrenciDegistir (int deger,Dugum *&degisen,Dugum *&atanacak);
		sinifSil();
		int id;
		Dugum *ilkDugum;
};


#endif