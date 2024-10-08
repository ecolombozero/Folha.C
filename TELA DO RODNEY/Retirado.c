// Screen Function (Tela Padrão)
void screen()
{
    int lin;
    int col;
    system("cls");
    system("color 0e");
    gotoxy(60, 23);
    printf("Close Application");

    gotoxy(80, 0);
    printf("%c", 191);
    gotoxy(1, 0);
    printf("%c", 218);
    printf("%c", 191);

    gotoxy(1, 24);
    printf("%c", 192);

    gotoxy(80, 24);
    printf("%c", 217);

    for (col = 2; col < 80; col++)
    {
        gotoxy(col, 0);
        printf("%c", 196);

        gotoxy(col, 24);
        printf("%c", 196);
    }

    for (lin = 1; lin < 24; lin++)
    {
        gotoxy(1, lin);
        printf("%c", 179);
        gotoxy(80, lin);
        printf("%c", 179);
    }
}