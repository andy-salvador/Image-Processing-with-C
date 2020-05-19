#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *girisDosya = fopen( "images/manzara.bmp", "rb" );
    FILE *cikisDosya = fopen( "images/manzara_kopya.bmp" ,"wb" );

    if( girisDosya == ( FILE* )0 )
    {
        printf( "dosya a��lamad�.\n" );
    }
    unsigned char header[54];
    unsigned char colorTable[1024];

    for( int i =0; i<54; i++ )
    {
        header[i] =getc( girisDosya );

    }

    int geni�lik = *(int *)&header[18];
    int y�kseklik = *(int *)&header[22];
    int bitDerinlik = *(int *)&header[28];

    if( bitDerinlik<=8 )
    {
         fread( colorTable, sizeof(unsigned char), 1024, girisDosya );
    }

    fwrite( header, sizeof(unsigned char), 54, cikisDosya );
    unsigned char buf[y�kseklik * geni�lik];
    fread( buf, sizeof(unsigned char), (y�kseklik*geni�lik), girisDosya );

   if( bitDerinlik <=8 )
   {

       fwrite( colorTable, sizeof(unsigned char), 1024, cikisDosya );
   }
       fwrite( buf, sizeof(unsigned char), (y�kseklik *geni�lik), cikisDosya );
       fclose( cikisDosya );
       fclose( girisDosya );

       printf( "Ba�ar� ile olu�turuldu !\n" );
       printf( "Geni�lik : %d\n", geni�lik );
       printf( "Y�kseklik : %d\n", y�kseklik );

    return 0;
}
