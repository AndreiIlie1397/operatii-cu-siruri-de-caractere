#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *f;
    FILE *g;
    FILE *h;
    FILE *i;
    FILE *j;
    char c1, c2, v, c, y, cuvant[50], s[50];
    int suma = 0, nr = 0, x = 0;
    f = fopen ( "date.in.txt", "r+" );
    g = fopen ( "date.in.txt", "r+" );
    h = fopen ( "date.in.txt", "r+" );
    i = fopen ( "date.in.txt", "a+" );
    j = fopen ( "date.in.txt", "a+" );
    if( f == NULL )
    {
        puts( "\n Eroare la citirea fisierului!" );
        return 0;
    }
    printf ( "\n\n  Introduceti:\n\n" );
    printf ( "          1  pentru schimarea unui anumit caracter citit de la tastatura cu un alt caracater citit de la tastatura. \n" );
    printf ( "          2  pentru dublarea unui caracter citit de la tastatura. \n" );
    printf ( "          3  pentru determinarea sumei numerelor din fisier. \n" );
    printf ( "          4  pentru determinarea numarului de aparitii ale unui cuvant. \n" );
    printf ( "\n  Optiune aleasa este: ");
    scanf ( "%c", &y );
    switch ( y )
    {

///Schimarea unui anumit caracter citit de la tastatura cu un alt caracater citit de la tastatura.

    case '1':
        printf ( "\n Introduceti caracterul pe care doriti sa il scimbati: " );
        getchar ();
        scanf ( "%c", &c1 );
        printf ( "\n Introduceti caracterul cu care doriti sa scimbati caracterul %c: ", c1 );
        getchar ();
        scanf ( "%c", &c2 );
        v = fgetc (f);
        while ( v != EOF )
        {
            if ( v == c1 )
            {
                fputc ( c2, g );
                while ( (int)v == 32 )
                    v = fgetc ( f );
            }
            else
                fputc ( v, g );
            v = fgetc ( f );
        }
        break;

///Dublarea unui caracter citit de la tastatura.

    case '2':
        printf ("\n Caracterul pe care doriti sa il dublati este: ");
        getchar ();
        scanf ( "%c", &c );
        v = fgetc( f );
        while ( v != EOF )
        {
            if ( v == c )
            {
                fputc ( c, h );
                fputc ( c, h );
                v = fgetc ( f );
            }
            else
            {
                fputc ( v, h );
                v = fgetc ( f );
            }
        }
        break;

///Determinarea sumei cifrelor din fisier.

    case '3':
        v = fgetc ( f );
        while ( v != EOF )
        {
            while ( v != ' ' )
            {
                if ( v >= '0' && v <= '9' )
                {
                    nr = nr * 10 + v - 48;
                    v = fgetc ( f + 1 );
                }
                if (v != '0' || v != '1' || v != '2' || v != '3' || v != '4' || v != '5' || v != '6' || v != '7' || v != '8' || v != '9' )
                    v = fgetc ( f );
            }
            suma = suma + nr;
            nr = 0;
            v = fgetc ( f );
        }
        fputc ( '\n', i );
        fprintf ( i, "\nSuma numerelor din fisier este: %d. ", suma );
        break;

///Determinarea numarului de aparitii ale unui cuvant

    case '4':
        printf ( "\n Introduceti cuvantul pentru care doriti sa aflati numarul de aparitii: " );
        scanf ( "%s", cuvant );
        while ( fscanf ( f, "%s", s ) != EOF )
        {
        if ( strcmp ( cuvant, s ) == 0 )
                x = x + 1;
        }
        fputc ( '\n', j );
        fprintf ( j, "\nCuvantul '%s' se gaseste in text de %d ori. ", cuvant, x );
        break;
    default:
        printf ( "\n Caracterul introdus nu este corect. Inchideti programul si incercati din nou. \n" );
    }
    fclose ( f );
    fclose ( g );
    fclose ( h );
    fclose ( i );
    fclose ( j );
    return 0;
}
