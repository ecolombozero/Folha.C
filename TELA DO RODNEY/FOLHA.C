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
    char charge [50];
    char admissionDate [50];
    char phone [30];
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
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


// Função Tela
void screen()
{
    int lin;
    int col;
    system("cls");
    system("color 0e");
    
//Layout

    gotoxy(80, 0);
    printf("%c", 191);// Cantos superior direito

    gotoxy(1, 0);
    printf("%c", 218);// Canto Superior Esquerdo
    

    gotoxy(1, 24); // Canto inferior esquerdo
    printf("%c", 192);

    gotoxy(80, 24); // Canto inferior direito
    printf("%c", 217);

// Desenha as bordas horizontais
  for (col = 2; col < 80; col++)
  {
    gotoxy(col, 0);
    printf("%c", 196); // linha superior

    gotoxy(col, 24);
    printf("%c", 196); // linha inferior

    gotoxy(col, 4);
    printf("%c", 196); // linha inferior
    gotoxy(02, 1);
    printf("Ewerton Colombo     RA: 00022754");

    gotoxy(02, 3);
    printf("Estrura de Dados");
    gotoxy(54, 3);
    printf("Payment System");
  }

  for (lin = 1; lin < 24; lin++)

  {
    gotoxy(1, lin);
    printf("%c", 179); // linha esquerda

    gotoxy(80, lin);
    printf("%c", 179); // linha direita
  }
}

void employee_Screen(){
    screen();
    
    gotoxy(10,6);
    printf("Registry Number: ");
    gotoxy(10,8);
    printf("Name: "); 
    gotoxy(10,10);
    printf("Address: ");
    gotoxy(10,12);
    printf("Charge: ");
    gotoxy(10,14);
    printf("Admission Date: ");
    gotoxy(10,16);
    printf("Phone:");
    gotoxy(10,18);
    printf("Salary:");
    
}

void List_Employees (listType *L)
{
  PointerType P;

  if (L->First == NULL)
  {
    screen();
    gotoxy(07, 05);
    printf("No record found!");
    gotoxy(03, 23);
    printf("Press keyboard to leave...");
    getch();
    return;
  }
  P = L->First;
  while (P != NULL)
  {
    employee_Screen();
    gotoxy(27, 6);
    printf("%d", P->content.registryNumber);
    gotoxy(16, 8);
    printf("%s", P->content.name);
    gotoxy(19, 10);
    printf("%s", P->content.address);
    gotoxy(18, 12);
    printf("%s", P->content.charge);
    gotoxy(26, 14);
    printf("%s", P->content.admissionDate);
    gotoxy(17, 16);
    printf("%s", P->content.phone);
    gotoxy(18, 18);
    printf("%.2f", P->content.salary);

    P = P -> next;
    getch(); // Espera uma tecla para continuar
  }
}

// Serve para registrar Funcionários usando os dados da Employee Screen

void registerFunction (listType *L) {
    PointerType P;
    employee_register dados;
    int answer;

    do {

    screen();
    employee_Screen();

    gotoxy(27,6);
    scanf("%d", &dados.registryNumber);
    gotoxy(16,8);
    fflush(stdin);
    fgets(dados.name, sizeof(dados.name), stdin);
    gotoxy(19,10);
    fflush(stdin);
    fgets(dados.address, sizeof(dados.address), stdin);
    gotoxy(18,12);
    fflush(stdin);
    fgets(dados.charge, sizeof(dados.charge), stdin);
    gotoxy(26,14);
    fflush(stdin);
    fgets(dados.admissionDate, sizeof(dados.admissionDate), stdin);
    gotoxy(17,16);
    fflush(stdin);
    fgets(dados.phone, sizeof(dados.phone), stdin);
    gotoxy(18,18);
    scanf("%f", &dados.salary);

    gotoxy (07, 23);
    printf("Confirm (1= YES; 2= NO): ");
    scanf("%d", &answer);

    if (answer == 1)
    {
      P = (PointerType)malloc(sizeof(itemType));
      P->content = dados;
      P->next = NULL;

      if (L->First == NULL)
      {
        L->First = P;
        L->Last = P;
      }
      else
      {
        L->Last->next = P;
        L->Last = P;
      }
    }
    
    gotoxy(07, 23);
    printf("Do wish to register another one? (1= YES; 2= NO): ");
    scanf("%d", &answer);

 } while (answer == 1);
    
}

void employee_Registry(listType *L ) {
  PointerType P;
  employee_register dados;
  int opc;
  do {
    screen();
    gotoxy(5, 3);
    printf("PAYROLL");
    gotoxy(5, 5);
    printf("1- Register new employee at the end");
    gotoxy(5, 7);
    printf("2- Register new employee at the start");
    gotoxy(5, 9);
    printf("3- Register new employee in a especific position");
    gotoxy(5, 11);
    printf("4- Remove employee at the end");
    gotoxy(5, 13);
    printf("5- Remove employee at the start");
    gotoxy(5, 15);
    printf("6- Remove employee in a especific position");
    gotoxy(5, 17);
    printf("7- Edit employee");
    gotoxy(5, 19);
    printf("8- List especific employee");
    gotoxy(5, 21);
    printf("9- Back");
    gotoxy(03, 23);
    printf("Type your option:");
    scanf("%d", &opc);
        
        switch (opc){
            case 1:
            registerFunction (L);
                break;
            case 2:
             
                break;
        }
    } while (opc != 9);
}

int main (){
    listType L;
    L.First = NULL;
    L.Last  = NULL;
    
    int options;

    do {
        screen();

        gotoxy(5, 5);
        printf("PAYROLL");
        gotoxy(25, 10);
        printf("1 - Register New Employee");
        gotoxy(25, 12);
        printf("2 - List of Employees");
        gotoxy(25, 14);
        printf("3 - Exit");
        gotoxy(03, 23);
        printf("Type your option:");
        scanf("%d", &options);
        
        switch (options){
            case 1:
            employee_Registry (&L);
                break;
            case 2:
            List_Employees (&L);
                break;
        }
    } while (options != 3);
    return 0;
}
