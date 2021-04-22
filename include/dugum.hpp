/****************************************************************************
**             SAKARYA UNIVERSITY 
**        BILGISAYAR MUHENDISLIGI BOLUMU 
**          NESNEYE DAYALI PROGRAMLAMA  
**     
**    OGRENCI ISMI.....: Irem Yalcin
**    OGRENCI NUMARASI.: G171210026
****************************************************************************/ 


#ifndef DUGUM_HPP
#define DUGUM_HPP

#include"ogrenci.hpp"

#include<iostream>
using namespace std;

class Dugum
{
	public:
		dugumSil();
		Dugum(int numara);
		Ogrenci *ogr;
		Dugum *sonraki;
};


#endif