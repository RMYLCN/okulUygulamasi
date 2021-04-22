/****************************************************************************
**             SAKARYA UNIVERSITY 
**        BILGISAYAR MUHENDISLIGI BOLUMU 
**          NESNEYE DAYALI PROGRAMLAMA  
**     
**    OGRENCI ISMI.....: Irem Yalcin
**    OGRENCI NUMARASI.: G171210026
****************************************************************************/ 

#include "dugum.hpp"
#include "ogrenci.hpp"

#include<iostream>
using namespace std;

 Dugum::Dugum(int numara) 
{
	this->ogr = new Ogrenci(numara);
	this->sonraki=0;
}

 Dugum::dugumSil() 
{
	delete this->ogr;

}