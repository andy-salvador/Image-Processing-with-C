#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *girisDosya = fopen( "images/kameraman.bmp", "rb" );
    FILE *cikisDosya = fopen( "images/kameraman_kopya.bmp" ,"wb" );

    if( girisDosya == ( FILE* )0 )
    {
        printf( "dosya açýlamadý.\n" );
    }
    unsigned char bitDerinlik[54];
    unsigned char piksels[1024];

    for( int i =0; i<54; i++ )
    {
        bitDerinlik[i] =getc( girisDosya );

    }

    int geniþlik = *(int *)&bitDerinlik[18];
    int yükseklik = *(int *)&bitDerinlik[22];
    int bitDerinlik = *(int *)&bitDerinlik[28];

    if( bitDerinlik<=8 )
    {
         fread( piksels, sizeof(unsigned char), 1024, girisDosya );
    }

    fwrite( bitDerinlik, sizeof(unsigned char), 54, cikisDosya );
    unsigned char buf[yükseklik * geniþlik];
    fread( buf, sizeof(unsigned char), (yükseklik*geniþlik), girisDosya );

   if( bitDerinlik <=8 )
   {

       fwrite( piksels, sizeof(unsigned char), 1024, cikisDosya );
   }
       fwrite( buf, sizeof(unsigned char), (yükseklik *geniþlik), cikisDosya );
       fclose( cikisDosya );
       fclose( girisDosya );

       printf( "Baþarý ile oluþturuldu !\n" );
       printf( "Geniþlik : %d\n", geniþlik );
       printf( "Yükseklik : %d\n", yükseklik );

    return 0;
}
