/****************************************************************************
**             SAKARYA UNIVERSITY 
**        BILGISAYAR MUHENDISLIGI BOLUMU 
**          NESNEYE DAYALI PROGRAMLAMA  
**     
**    OGRENCI ISMI.....: Irem Yalcin
**    OGRENCI NUMARASI.: G171210026
****************************************************************************/ 


#include "sinif.hpp"
#include "dugum.hpp"

#include <iostream>
using namespace std;

Sinif::Sinif(int *numara,int id) 
{
	this->id=id;
	
	Dugum *dugum = new Dugum(*numara);  *numara=*numara+1; 
	Dugum *dugum2 = new Dugum(*numara); *numara=*numara+1;
	Dugum *dugum3 = new Dugum(*numara); *numara=*numara+1;
	Dugum *dugum4 = new Dugum(*numara); *numara=*numara+1;
	Dugum *dugum5 = new Dugum(*numara); *numara=*numara+1;
	
	this->ilkDugum=dugum;
	dugum->sonraki=dugum2;
	dugum2->sonraki=dugum3;
	dugum3->sonraki=dugum4;
	dugum4->sonraki=dugum5;
	dugum5->sonraki=0;
} 

Sinif::sinifYazdir() 
{
		int ogr=0;
		Dugum *gecici=ilkDugum;
		
	// 1.Satir
	for(int i=0;i<10;i++) 
	{
		cout<<"_";
	}
	cout <<endl;
	
	// 2.Satir
	cout<<"|"<<this<<"|";
	cout<<endl;
	
	// 3.Satir
	cout<<"----------  ";

    while(gecici!=0) 
	{
		cout<<"************  ";
	    gecici=gecici->sonraki;
		ogr++;
	}
	cout<<endl;
	gecici=ilkDugum;
	
	// 4. Satir
	cout<<"|   "<<this->id<<"    |";
	
	while(gecici!=0) 
	{
		cout<<"  * "<<gecici<<" *";
	    gecici=gecici->sonraki;
	}
	cout<<endl;
	gecici=ilkDugum;
	
	// 5.Satir
	cout<<"----------  ";

    while(gecici!=0) 
	{
		cout<<"************  ";
	    gecici=gecici->sonraki;
	}
	cout<<endl;
	gecici=ilkDugum;
	
	// 6. Satir
	cout<<"|"<<ilkDugum<<"|";
	     
    while(gecici!=0) 
	{
		cout<<"  *    "<<gecici->ogr->no<<"    *";
	    gecici=gecici->sonraki;
	}
	cout<<endl;
	gecici=ilkDugum;
	
	// 7.Satir
	for(int i=0;i<10;i++) 
	{
		cout<<"-";
	}
		cout<<"  ";
		
    while(gecici!=0) 
	{
		cout<<"************  ";
	    gecici=gecici->sonraki;
	}
	gecici=ilkDugum;
	cout <<endl;
	cout <<endl;
	cout <<endl;
	
};

Sinif::ogrenciEkle(int *numara) 
{
	Dugum *gecici=this->ilkDugum;
	while(gecici->sonraki!=0) 
	{
		gecici=gecici->sonraki;
	}
	Dugum *yeniDugum=new Dugum(*numara);
	gecici->sonraki=yeniDugum;
	*numara=*numara+1;

}

Sinif::ogrenciSil(int deger) 
{
	Dugum*gecici=ilkDugum;
	
	if(ilkDugum==0) 
	{
		cout<<"Bos bir sinif uzerinde silme islemi yapamazsiniz."<<endl;
		return 0;
	}
	
	if(ilkDugum->ogr->no==deger) 
	{
		ilkDugum=ilkDugum->sonraki;
		gecici->dugumSil();
		delete gecici;
		return 0;
	}

	while(gecici->sonraki!=0) 
	{
		if(gecici->sonraki->ogr->no==deger) 
		{
			Dugum *gecici2=gecici->sonraki;
			gecici->sonraki=gecici->sonraki->sonraki;
			gecici2->dugumSil();
			delete gecici2;
			return 0;
		}
		gecici=gecici->sonraki;
	}
	gecici=gecici->sonraki;
	if(gecici->ogr->no==deger) 
	{
		gecici->dugumSil();
		delete gecici;
		return 0;
	}
        return 0;
}

 Sinif::ogrenciBul(int deger,Dugum *&degisen,Dugum *&atanacak) 
{
	Dugum *gecici=ilkDugum;
	
	if(ilkDugum==0) 
	{
		cout<<"Bos bir sinif uzerinde degistirme islemi yapamazsiniz."<<endl;
		return 0;
	}
	
	if(ilkDugum->ogr->no==deger) 
	{
		degisen=ilkDugum;
		atanacak=ilkDugum->sonraki;
		return 0;
	}
	
	while (gecici->sonraki!=0) 
	{
		if(gecici->sonraki->ogr->no==deger) 
		{
		   //cout<<"a"<<degisen<<endl;
		   degisen=gecici->sonraki;
		   atanacak=gecici->sonraki->sonraki;
		   //cout<<degisen<<" "<<gecici->sonraki<<"aa"<<degisen->ogr->no<<endl;
		   return 0;
		}
		gecici=gecici->sonraki;
	}
	gecici=gecici->sonraki;
	if(gecici->ogr->no==deger) 
	{
        degisen=gecici;
		return 0;
	}
	else
		cout<<"Degistirmek istediğiniz ogrenci bulunamadı."<<endl;
}

 Sinif::ogrenciDegistir(int deger,Dugum *&degisen,Dugum *&atanacak) 
{
		Dugum *gecici=ilkDugum;
	
	if(ilkDugum==0) 
	{
		cout<<"Bos bir sinif uzerinde degistirme islemi yapamazsiniz."<<endl;
		return 0;
	}
	
	if(ilkDugum->ogr->no==deger) 
	{
		ilkDugum=degisen;
		ilkDugum->sonraki=atanacak;
		return 0;
	}
	
	while (gecici->sonraki!=0) 
	{
		if(gecici->sonraki->ogr->no==deger) 
		{
		   gecici->sonraki=degisen;
		   degisen->sonraki=atanacak;
		   return 0;
		}
		gecici=gecici->sonraki;
	}
	gecici=gecici->sonraki;
	if(gecici->ogr->no==deger) 
	{
        gecici=degisen;
		degisen->sonraki=atanacak;
		return 0;
	}
	else
		cout<<"Degistirmek istediğiniz ogrenci bulunamadı."<<endl;
}

Sinif::sinifSil() 
{
	Dugum *gecici=ilkDugum;
	
   	while(gecici->sonraki!=0) 
	{
      Dugum *gecici2=gecici;
	  gecici->dugumSil();
	  gecici=gecici->sonraki;
	  delete gecici2;
	}
	gecici->dugumSil();
	delete gecici;

} 













 