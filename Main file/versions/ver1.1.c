#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>

// input and output buffer clearer
void cleanbuff(){
    fflush(stdin);
    fflush(stdout);
}

// limpia y pausa pantalla de terminal 
void screenclean() {
    system("pause");
    system("cls");
}

// estructura para ejercicio 1 
struct employee {
    char empl_name[100];
    float basewage;
    float emp_bono;
    float finalwage;
    int num_calls;
    int emp_eval;
};

//funcion que guarda los datos ingresados 
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

// imprime datos ingresados 
struct employee empl_info_output(struct employee a, int z) {
    
    if (a.emp_eval <= 5 || a.num_calls < 50) {
        printf(" \n El empleado %d , %s , no tiene acceso a bono debido a su rendimiento no fue satisfactorio \n", z,a.empl_name);
        cleanbuff();
    }   else { if (a.emp_eval >= 6 && a.emp_eval < 8) {
        printf(" \n El empleado %d , %s , tiene acceso a bono debido a que la calidad de su atencion al cliente fue Aceptable \n",z,a.empl_name);
    }cleanbuff();

    if (a.emp_eval >= 8 && a.emp_eval <= 10) {
        printf("\n El empleado %d , %s , tiene acceso a bono debido a que la calidad de su atencion al cliente fue excelente \n", z, a.empl_name);
    }cleanbuff();

    if (a.num_calls >= 50 && a.num_calls < 100 ){
        printf("Su bono es de 1000 cordobas \n");
        a.emp_bono = 1000;
    }cleanbuff();

    if (a.num_calls >= 100 && a.num_calls < 150 ){
        printf("Su bono es de 1500 cordobas \n");
        a.emp_bono = 1500;
    }cleanbuff();
    
    if (a.num_calls > 150 ){
        printf("Su bono es de 2000 cordobas \n");
        a.emp_bono = 2000;
    }cleanbuff();}

    
    
    a.finalwage = a.basewage + a.emp_bono;
    printf("Su salaro mensual es de %.2f, su bono es de %.2f por lo que su salario mensual es de: %.2f \n", a.basewage, a.emp_bono, a.finalwage);
    cleanbuff();

   return a ;
}


//funcion principal del ejercicio 1 
int exer_1() {

  struct employee emplist[100];
  int opcr2 =0;
  int count1 =0;
  int i = 0;
printf("Bienvenido al sistema de inventario virtual de la Empresa X de Nicaragua \n");
printf("Usted ha ingresado como administrador \n");
printf("Usted tiene disponibles las siguientes opciones:  \n 1. Ingresar a la base de datos de empleados \n 2. Salir  \n");
scanf("%d",&opcr2);
cleanbuff();


switch (opcr2)
{
case 1:
    printf("Ingrese el numero de trabajadores que va a ingresar  \n");
    scanf("%d",&count1);
    cleanbuff();
    
    for(i=1;i<=count1;i++){
        emplist[i] = empl_infoinput(i);
    }
    
    printf("Usted ha termiando de ingresar los datos de su empleado, desea: \n 1. Ver estado de un empleado especifico \n 2. Ver todos los empleados \n");
    scanf("%d",&opcr2);
    cleanbuff();
    
    switch (opcr2)
    {
    case 1:
        printf("Ingrese el numero del empleado que quiere ingresar \n");
        scanf("%d",&opcr2);
        cleanbuff();
        empl_info_output(emplist[opcr2],opcr2);
        break;
    case 2:
        printf("Usted ha elejido ver todos los empleados ingresados \n");
       for(i=1;i<=count1;i++){
         empl_info_output(emplist[i],i);
    }
        break;
    
    default:
       printf("Usted ha elejido una opcion invalida, sera redirijido al menu principal");
       screenclean();
       cleanbuff();
       main();
        break;
    }

    break;

case 2:
     screenclean();
     main();
    break;

default:
    printf("Opcion invalida, pruebe denuevo");
    screenclean();
    exer_1();
    
    break;
}

printf(" \n \n Usted ha llegado al fin del ejercicio, desea retornar al menu princial? si (1) \n");
scanf("%d",&opcr2);

if (opcr2==1){
    screenclean();
    main();
}

    return 0;
}


// funcion principal del ejercicio 3 
int exer_3() { 
    float recount;
    float count3;
    int i;
    int out;
    printf("Ingrese las estatura del grupo \n");

    i=0;

    // ciclo se utiliza para ingresar alturas de las personas, se van sumando en la variable count3
    while (out != 1) {
       printf("Ingrese estatura: ");
       scanf("%f",&recount);  
       count3= count3+recount;
       printf("\nIngrese 1 cuando haya terminado y 0 para continuar: ");
       scanf("%d",&out);
       printf("\n");
       i++;
    }
    //variable i va contando el numero de estaturas que se ingresan, luego se utilza para sacar promedio
    count3 = count3/i;

    printf("\nEl promedio de estatura de las %d estaturas dadas es %.2f \n",i,count3);
 
    printf("Desea salir al menu principal (1) o salir(cualquier otra tecla)? \n");
    scanf("%d",&out);

    switch (out)
    {
    case 1:
        screenclean();
        main();
        break;
    
    default:
        printf("bye");
        break;
    }


  return 0;
}

struct student_grades {
     float math;
     float science;
     float english;
     float spanish;
     float PE;
     float geography;
}; 

/*
float get_studentgrades(int z){
    float grade_avarage;
    struct student_grades b;

   printf("\nEstudiante #%d",z);
   
   printf("Ingrese nota de matematicas: ");
   scanf("%f",&b.math);
   cleanbuff();

   printf("Ingrese nota de ciencias naturales: ");
   scanf("%f",&b.science);
   cleanbuff();

   printf("Ingrese nota de spanish: ");
   scanf("%f",&b.spanish);
   cleanbuff();

   printf("Ingrese nota de ingles: ");
   scanf("%f",&b.english);
   cleanbuff();

   printf("Ingrese nota de EF: ");
   scanf("%f",&b.PE);
   cleanbuff();


   printf("Ingrese nota de geografia: ");
   scanf("%f",&b.geography);
   cleanbuff();
   
   grade_avarage = b.english+b.geography+b.math+b.PE+b.science+b.spanish;
   grade_avarage = grade_avarage/6;
   return grade_avarage;
}

int exer_5() { 
     float studentgrades[100];
     int out = 0;
     int i = 1;
     int counter4 =0;
     while (out != 1) {
        printf("ingrese las notas del estudiante: \n");
        studentgrades[i] = get_studentgrades(i);
        i++;
        counter4++;
        printf("Cuando termine de ingresar las notas de los estudiantes presione 1");
        scanf("%d",&out);
     }
     
      
     


    


     


    return 0;
}
 */




int main (){

exer_1();
// exer_5();
// exer_3();

    return 0;
}







