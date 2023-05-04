#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>

// input and output buffer clearer
void cleanbuff(){
    fflush(stdin);
    fflush(stdout);
}

void screenclean() {
    system("pause");
    system("cls");
}

struct employee {
    char empl_name[100];
    float basewage;
    float emp_bono;
    float finalwage;
    int num_calls;
    int emp_eval;
};

struct employee empl_infoinput(int z) {
    struct employee input;

    printf("Empleado #%d \n",z);
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
    printf(" \n\n ");

   return input;
}

struct employee empl_info_output(struct employee a, int z) {
    
    int bono;
    if (a.emp_eval <= 5 || a.num_calls < 50) {
        printf("El empleado %d no tiene acceso a bono debido a su rendimiento no fue satisfactorio \n", z);

    } 

    if (a.emp_eval >= 6 && a.emp_eval < 8) {
        printf("El empleado %d tiene acceso a bono debido a que la calidad de su atencion al cliente fue Aceptable \n",z);
    }

    if (a.emp_eval >= 8 && a.emp_eval <= 10) {
        printf("El empleado %d , %s , tiene acceso a bono debido a que la calidad de su atencion al cliente fue Aceptable \n", z, a.empl_name);
    }

    if (a.num_calls >= 50 && a.num_calls < 100 ){
        printf("Su bono es de 1000 cordobas \n");
        bono = 1000;
    }

    if (a.num_calls >= 100 && a.num_calls < 150 ){
        printf("Su bono es de 1500 cordobas \n");
        bono = 1500;
    }
    
    if (a.num_calls > 150 ){
        printf("Su bono es de 2000 cordobas \n");
        bono = 2000;
    }
    
    a.finalwage = a.basewage + bono;
    printf("Su salaro mensual es de %.2f, su bono es de %d por lo que su salario mensual es de: %.2f \n", a.basewage, bono, a.finalwage);

   return a ;
}



int exer_1() {

  struct employee emplist[100];
  int opcr2 =0;
  int count1 =0;
  int i = 0;
printf("Bienvenido al sistema de inventario virtual de la Empresa X de Nicaragua \n");
printf("Usted ha ingresado como administrador \n");
printf("Usted tiene disponibles las siguientes opciones:  \n 1. Ingresar a la base de datos de empleados \n 2. Salir  \n");
scanf("%d",&opcr2);


switch (opcr2)
{
case 1:
    printf("Ingrese el numero de trabajadores que va a ingresar  \n");
    scanf("%d",&count1);
    
    for(i=1;i<=count1;i++){
        emplist[i] = empl_infoinput(i);
    }
    
    printf("Usted ha termiando de ingresar los datos de su empleado, desea: \n 1. Ver estado de un empleado especifico \n 2. Ver todos los empleados \n");
    scanf("%d",&opcr2);
    
    switch (opcr2)
    {
    case 1:
        printf("Ingrese el numero del empleado que quiere ingresar \n");
        scanf("%d",&opcr2);
        empl_info_output(emplist[opcr2],opcr2);
        break;
    case 2:
        printf("Usted ha elejido ver todos los empleados ingresados \n");
       for(i=1;i<=count1;i++){
         empl_info_output(emplist[i],i);
    }
        break;
    
    default:
        break;
    }

    break;

case 2:
     screenclean();
     main();
    break;

default:
    printf("Opcion invalida, pruebe denuevo");
    system("pause");
    system("cls");
    exer_1();
    
    break;
}

    return 0;
}



int main (){

exer_1();

    return 0;
}







