#include<iostream>
#include<stdio.h>

using namespace std;

int main(){


return 0;
}


FILE *girisDosya = fopen("resim.bmp", "rb");

if (girisDosya == (FILE*)0)
{
 cout << "Resim dosyasi bulunamiyor veya gecersiz." << endl;
}

else 
{
	cout << "Basari ile yuklendi" << endl;
}

unsigned char bilgiDepo[54];
unsigned char piksels[1024];

for(int i = 0; i < 54; i++)
{
	bilgiDepo[i] = getc(girisDosya);
}

int genislik = *(int *)&bilgiDepo[18]; 
int uzunluk = *(int *)&bilgiDepo[22];
int bitDerinlik = *(int *)&bilgiDepo[28];

fclose(girisDosya);

cout << "--------------------" << endl;
cout << "Derinlik:     " << bitDerinlik << endl;
cout << "Genislik:     " << genislik << endl;
cout << "Uzunluk:      " << uzunluk << endl;
cout << "--------------------" << endl;




