/*
Autor: Ewerton Colombo
RA: 00022754
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

//definindo estrutura de dados

typedef struct {
    int  registryNumber;
    char name [30];
    char address[50];
    char charge [20];
    char admissionDate [20];
    char phone [19];
    float salary;
} employee_register;

typedef struct itemType *PointerType;

typedef struct itemType {
    employee_register content;
    PointerType next;
} itemType;

typedef struct
{
    PointerType First;
    PointerType Last;
} listType; 

// Screen Browser
void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


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

void employee_Screen(){
    screen();
    
    gotoxy(10,6);
    printf("Registry Number:");
    gotoxy(10,8);
    printf("Name:"); 
    gotoxy(10,10);
    printf("Address:");
    gotoxy(10,12);
    printf("Charge:");
    gotoxy(10,14);
    printf("Admission Date:");
    gotoxy(10,16);
    printf("Phone:");
    gotoxy(10,18);
    printf("Salary:");
}

void registerFunction (listType *L){
    PointerType P;
    employee_register dados;
    int answer;

    do {

    screen();
    employee_Screen();
    gotoxy(19,10);
    scanf("%d", &dados.registryNumber);
    gotoxy(19,12);
    fflush(stdin);
    fgets(dados.name, 19, stdin);
    gotoxy(19,14);
    fflush(stdin);
    fgets(dados.address, 50, stdin);
    gotoxy(19,16);
    fflush(stdin);
    fgets(dados.charge, 20, stdin);
    gotoxy(19,18);
    fflush(stdin);
    fgets(dados.admissionDate, 20, stdin);
    gotoxy(19,20);
    fflush(stdin);
    fgets(dados.phone, 19, stdin);
    gotoxy(19,22);
    scanf("%f", &dados.salary);

    gotoxy (07, 23);
    printf("Confirm (1= YES; NO): ");
    scanf("%d", &answer);

    gotoxy(07, 23);
    printf("Do wish to register another one? (1=YES; 2= NO): ");
    scanf("%d", &answer);
 } while (answer == 1);
    
}


int main (){
    listType L;
    L.First = NULL;
    L.Last  = NULL;
    
    int options;

    do {
        screen();

        gotoxy(30, 03);
        printf("PAYROLL");
        gotoxy(25, 10);
        printf("Register New Employee");
        gotoxy(25, 12);
        printf("List of Employees");
        gotoxy(25, 14);
        printf("Close");
        gotoxy(03, 23);
        printf("Type your option:");
        scanf("%d", &options);
        
        switch (options){
            case 1:
            registerFunction (&L);
                break;
            case 2:
            //Consultar (&L);
                break;    
        }
    } while (options != 3);

    screen();
    employee_Screen();
}