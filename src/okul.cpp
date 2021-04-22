/****************************************************************************
**             SAKARYA UNIVERSITY 
**        BILGISAYAR MUHENDISLIGI BOLUMU 
**          NESNEYE DAYALI PROGRAMLAMA  
**     
**    OGRENCI ISMI.....: Irem Yalcin
**    OGRENCI NUMARASI.: G171210026
****************************************************************************/ 


# include "okul.hpp"
# include "sinif.hpp"
# include "dugum.hpp"
# include "ogrenci.hpp"

#include <iostream>

using namespace std;

Okul::Okul(int numara,int id) 
{
	Sinif *ilk = new Sinif(&numara,id); id++;
	Sinif *ikinci = new Sinif(&numara,id);
	ilkSinif=ilk;
	ikinciSinif=ikinci;
	this->Siniflar[0]=ilkSinif;
	this->Siniflar[1]=ikinciSinif;
	
};

Okul::okulYazdir() 
{
	cout<<endl;
	ilkSinif->sinifYazdir();
	ikinciSinif->sinifYazdir();
};

Okul::ogrenciEkle(int numara) 
{
	int secim;
	cout<<"Sinif Kodu..:";
	cin>>secim;
	cout<<endl;
	 
	 if(secim==1) //İlk Sinifa Ogrenci Ekleme
	{
		ilkSinif->ogrenciEkle(&numara);
	} 
	
	 if(secim==2) //İkinci Sinifa Ogrenci Ekleme
	{
		ikinciSinif->ogrenciEkle(&numara);
	} 
	else
	cout<<"Yanlis Bir Secim Yaptiniz!"<<endl;

};


Okul::ogrenciSil() 
{
	int secimSinif,secimOgrenci;
	cout<<"Sinif Kodu..:";
	cin>>secimSinif;
	cout<<endl;
	
	cout<<"Ogrenci Numarasi..:";
	cin>>secimOgrenci;
	cout<<endl;
	 
	 if(secimSinif==1) //İlk Siniftan Ogrenci Silme
	{
		ilkSinif->ogrenciSil(secimOgrenci);
		return 0;
	} 
	
	 if(secimSinif==2) //İkinci Siniftan Ogrenci Silme
	{
		ikinciSinif->ogrenciSil(secimOgrenci);
		return 0;
	} 
        return 0;

};

Okul::ogrenciBul(int secilenSinif,int secilenOgrenci,Dugum *&degisen,Dugum *&atanacak) 
{
    	 if(secilenSinif==1) 
	{
        this->ilkSinif->ogrenciBul(secilenOgrenci,degisen,atanacak);	
		//cout<<"adres:"<<degisen<<endl;
        return 0;		
	} 
	    
		 if(secilenSinif=2) 
	{
        this->ikinciSinif->ogrenciBul(secilenOgrenci,degisen,atanacak);
        return 0;		
	} 
	
};

Okul::ogrenciDegistir(int secilenSinif,int secilenOgrenci,Dugum *&degisen,Dugum *&atanacak) 
{
    	 if(secilenSinif==1) 
	{
        this->ilkSinif->ogrenciDegistir(secilenOgrenci,degisen,atanacak);	
        return 0;		
	} 
	    
		 if(secilenSinif=2) 
	{
        this->ikinciSinif->ogrenciDegistir(secilenOgrenci,degisen,atanacak);
        return 0;		
	} 
};

Okul::okulMenu(int numara) 
{
   int secim;
   numara=20;
	do 
	{
		//cout<<endl;
		cout<<"1...Ogrenci Degistir"<<endl;
		cout<<"2...Ogrenci Sil"<<endl;
		cout<<"3...Ogrenci Ekle"<<endl;
		cout<<"4...Cikis"<<endl;
		cin>>secim;
		
		if(secim==1) //Ogrenci Degistir
	{
		Dugum *degisen1=0;
		Dugum *degisen2=0;
		Dugum *atanacak1=0;
		Dugum *atanacak2=0;
		
		
		int secilenSinif1,secilenSinif2,secilenOgrenci1,secilenOgrenci2;
		
		cout<<"Sinif Kodu..:";
		cin>>secilenSinif1;
		cout<<endl;
		
		cout<<"Ogrenci Numarasi..:";
		cin>>secilenOgrenci1;
		cout<<endl;
		
		cout<<"Sinif Kodu..:";
		cin>>secilenSinif2;
		cout<<endl;
		
		cout<<"Ogrenci Numarasi..:";
		cin>>secilenOgrenci2;
		cout<<endl;
		
		
		//İlk Hedef
		this->ogrenciBul(secilenSinif1,secilenOgrenci1,degisen1,atanacak1); 
		// İkinci Hedef
		this->ogrenciBul(secilenSinif2,secilenOgrenci2,degisen2,atanacak2);
		
        
		
		// İkinci Hedef 1. Sinifa
		this->ogrenciDegistir(secilenSinif1,secilenOgrenci1,degisen2,atanacak1);
		//İlk Hedef 2. Sinifa
		this->ogrenciDegistir(secilenSinif2,secilenOgrenci2,degisen1,atanacak2); 
		
		ilkSinif->sinifYazdir();
		ikinciSinif->sinifYazdir();
	}
	
	 if(secim==2) //Ogrenci Sil
	{
        this->ogrenciSil();		
		cout<<endl;
		ilkSinif->sinifYazdir();
		ikinciSinif->sinifYazdir();
	}
	
    if(secim==3) //Ogrenci Ekle
	{
		this->ogrenciEkle(numara);
		cout<<endl;
		ilkSinif->sinifYazdir();
		ikinciSinif->sinifYazdir();
		numara=numara+1;
		
	}
	
	if(secim==4)  //Cikis
	{
		exit(0);
	}
		
	} while(secim>0&&secim<4); 

	cout<<"Yanlis Secim Yaptiniz!"<<endl;
};

Okul::okulSil() 
{	
	this->ilkSinif->sinifSil();
	this->ikinciSinif->sinifSil();
	
	delete this->ilkSinif;
	delete this->ikinciSinif;
};




