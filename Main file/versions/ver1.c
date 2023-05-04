#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>

struct employee {
    char empl_name[100];
    float basewage;
    float emp_bono;
    float finalwage;
    int num_calls;
    int emp_eval;
};

// input and output buffer clearer
void cleanbuff(){
    fflush(stdin);
    fflush(stdout);
}

struct employee empl_infoinput(int z) {
    struct employee input;

    printf("Empleado #%d",z);
    printf("Ingrese los datos requeridos \n");
    cleanbuff();
    printf("Nombre: ");
    gets(input.empl_name);
    cleanbuff();

    printf("\nIngrese salario semanal: ");
    scanf("%f",&input.basewage);
    cleanbuff();

    printf("\nIngrese numero de llamadas: ");
    scanf("%d",&input.num_calls);
    cleanbuff();

    printf("\nIngrese evaluacion de la atencion en las llamadas: ");
    scanf("%d",&input.emp_eval);
    cleanbuff();

   return input;
}


int exer_1() {
  struct employee emplist[100];
  int opcr2 = 0;
  int count1;
  int i = 0;
printf("Bienvenido al sistema de inventario virtual de la Empresa X de Nicaragua \n");
printf("Usted ha ingresado como administrador \n");
printf("Usted tiene disponibles las siguientes opciones:  \n 1. Ingresar datos de empleado \n 2. Salir  \n");
scanf("%d",&opcr2);

switch (opcr2)
{
case 1:
    printf("Ingrese el numero de trabajadores que va a ingresar  \n");
    scanf("%d", count1);
    
    empl_infoinput(1);

    for(i=1;i<=count1;i++){

    }

    break;

case 2:

    break;

default:
    break;
}

    return 0;
}


int main (){

exer_1();

    return 0;
}