#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *girisDosya = fopen( "images/manzara.bmp", "rb" );
    FILE *cikisDosya = fopen( "images/manzara_kopya.bmp" ,"wb" );

    if( girisDosya == ( FILE* )0 )
    {
        printf( "dosya açýlamadý.\n" );
    }
    unsigned char header[54];
    unsigned char colorTable[1024];

    for( int i =0; i<54; i++ )
    {
        header[i] =getc( girisDosya );

    }

    int geniþlik = *(int *)&header[18];
    int yükseklik = *(int *)&header[22];
    int bitDerinlik = *(int *)&header[28];

    if( bitDerinlik<=8 )
    {
         fread( colorTable, sizeof(unsigned char), 1024, girisDosya );
    }

    fwrite( header, sizeof(unsigned char), 54, cikisDosya );
    unsigned char buf[yükseklik * geniþlik];
    fread( buf, sizeof(unsigned char), (yükseklik*geniþlik), girisDosya );

   if( bitDerinlik <=8 )
   {

       fwrite( colorTable, sizeof(unsigned char), 1024, cikisDosya );
   }
       fwrite( buf, sizeof(unsigned char), (yükseklik *geniþlik), cikisDosya );
       fclose( cikisDosya );
       fclose( girisDosya );

       printf( "Baþarý ile oluþturuldu !\n" );
       printf( "Geniþlik : %d\n", geniþlik );
       printf( "Yükseklik : %d\n", yükseklik );

    return 0;
}
