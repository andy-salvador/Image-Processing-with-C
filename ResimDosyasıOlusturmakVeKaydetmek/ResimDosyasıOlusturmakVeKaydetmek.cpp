#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *girisDosya = fopen( "images/kameraman.bmp", "rb" );
    FILE *cikisDosya = fopen( "images/kameraman_kopya.bmp" ,"wb" );

    if( girisDosya == ( FILE* )0 )
    {
        printf( "dosya a��lamad�.\n" );
    }
    unsigned char bitDerinlik[54];
    unsigned char piksels[1024];

    for( int i =0; i<54; i++ )
    {
        bitDerinlik[i] =getc( girisDosya );

    }

    int geni�lik = *(int *)&bitDerinlik[18];
    int y�kseklik = *(int *)&bitDerinlik[22];
    int bitDerinlik = *(int *)&bitDerinlik[28];

    if( bitDerinlik<=8 )
    {
         fread( piksels, sizeof(unsigned char), 1024, girisDosya );
    }

    fwrite( bitDerinlik, sizeof(unsigned char), 54, cikisDosya );
    unsigned char buf[y�kseklik * geni�lik];
    fread( buf, sizeof(unsigned char), (y�kseklik*geni�lik), girisDosya );

   if( bitDerinlik <=8 )
   {

       fwrite( piksels, sizeof(unsigned char), 1024, cikisDosya );
   }
       fwrite( buf, sizeof(unsigned char), (y�kseklik *geni�lik), cikisDosya );
       fclose( cikisDosya );
       fclose( girisDosya );

       printf( "Ba�ar� ile olu�turuldu !\n" );
       printf( "Geni�lik : %d\n", geni�lik );
       printf( "Y�kseklik : %d\n", y�kseklik );

    return 0;
}
