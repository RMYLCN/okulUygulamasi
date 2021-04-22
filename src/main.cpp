/****************************************************************************
**             SAKARYA UNIVERSITY 
**        BILGISAYAR MUHENDISLIGI BOLUMU 
**          NESNEYE DAYALI PROGRAMLAMA  
**     
**    OGRENCI ISMI.....: Irem Yalcin
**    OGRENCI NUMARASI.: G171210026
****************************************************************************/ 

#include <iostream>
#include "ogrenci.hpp"
#include "dugum.hpp"
#include "sinif.hpp"
#include "okul.hpp"
 
 using namespace std;
 
 int main(int argc,char**argv) 
 {
	int numara=10;
	int id=1;
    int secim;
	
	Okul *okul=new Okul(numara,id);
	okul->okulYazdir();
	okul->okulMenu(numara);
	
	//okul->okulSil();

	exit(0);
 }