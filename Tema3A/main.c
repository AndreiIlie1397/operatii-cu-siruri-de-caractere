#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f;
    FILE *g;
    FILE *h;
    char v;
    f = fopen ( "date.in.txt", "r" );
    g = fopen ( "date.out.txt", "w" );
    h = fopen ( "date.in.txt", "r" );
    if ( f == NULL )
    {
        puts ( "\n Eroare la citirea fisierului!" );
        return 0;
    }
    fprintf ( g, "Sa apara numai numerele.\n" );
    fprintf ( g, "------------------------\n" );

    while ( ( v = fgetc ( f ) ) != EOF )
    {
        if ( v >= '0' && v <= '9' )
            putc ( v, g );
        else
            v = fgetc ( f + 1 );
    }

    fprintf ( g, "\n\nSa stearga toate cuvintele ce incep cu majuscula.\n" );
    fprintf ( g, "-------------------------------------------------\n" );
    v = fgetc ( h );
    while ( v != EOF )
    {
        if ( v >= 'A' && v <= 'Z' )
        {
            v = getc ( h );
            while ( v != ' ' )
                v = getc ( h );
        }
        else
            putc ( v, g );
        v = getc ( h );
    }

    fclose ( f );
    fclose ( g );
    fclose ( h );
    return 0;
}
