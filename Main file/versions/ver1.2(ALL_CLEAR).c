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

// prototype of main 

int main();

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
    }   else { 
        
    if (a.emp_eval >= 6 && a.emp_eval < 8) {
        printf(" \n El empleado %d , %s , tiene acceso a bono debido a que la calidad de su atencion al cliente fue Aceptable \n",z,a.empl_name);
        cleanbuff();
    } cleanbuff();

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

//funcion principal del ejercicio 2
int exer_2(){

    float temp;
    float HS_cant, HD_cant, HT_cant, final_count, amountwithdisc = 0;
    int exit_value = 0;
    int opcr4;
    int haydescuento = 0;

    printf("\n Bienvenido al naufrago satisfecho \n");
    printf("\n Nuestro menu de hoy es: \n 1. Hamburguesa sencilla (20$) \n 2. Hamburguesa doble (25$) \n 3. Hamburguesa triple (28) \n");
    
     printf(" Porfavor digite su orden \n");
    while (exit_value != 1) {
       
       printf("Ingrese el numero de la hamburguesa que quiera \n ");
       scanf("%d",&opcr4);

       switch (opcr4)
       {
       case 1:
        printf("Cuantas hamburguesas sencillas desea? \n");
        scanf("%f",&temp);
        HS_cant = HS_cant + temp;
        temp =0;
        break;
       
       case 2:
        printf("Cuantas hamburguesas dobles desea? \n");
        scanf("%f",&temp);
        HD_cant = HD_cant + temp;
        temp =0;
        break;

        case 3:
        printf("Cuantas hamburguesas triples desea? \n");
        scanf("%f",&temp);
        HT_cant = HT_cant + temp;
        temp =0;
        break;

       default:
       printf(" \n El item que usted ha pedido no se encuentra disponible por el momento \n");
        break;
       }

     printf("\n Si ha terminado su orden presione 1, en caso de querer algo mas presione cualquier otra tecla \n");
     scanf("%d",&exit_value);
    }

    printf("Usted ha terminado de ordenar, desea pagar con efectivo (1) o tarjeta(2)? \n");
    scanf("%d",&exit_value);

     
    if (exit_value == 2) {
       printf("Usted ha elegido pagar con tarjeta por lo que tiene acceso a un 5 */* de descuento \n ");
       haydescuento = 1;
    }

   final_count = HS_cant*20 + HD_cant*25+ HT_cant*28;
   amountwithdisc = final_count - (final_count*0.05);

   printf("Su orden consta de: \n");
   if (HS_cant > 0) {
    printf(" %.f hamburguesas sencillas \n",HS_cant);
   }
   if (HD_cant > 0) {
    printf(" %.f hamburguesas dobles \n",HD_cant);
   }

   if (HT_cant > 0) {
    printf(" %.f hamburguesas triples \n",HT_cant);
   }

   //pendiente preguntarle al usuario si su orden es correcta y si no darle la opcion de cambiarla

   if (haydescuento==1 ) {
   printf("por un total de: %.f$ con descuento y %.f$ sin descuento\n",amountwithdisc ,final_count);

   } else { 
    printf("por un total de: %.f$ sin descuento\n",final_count);
    }

   printf("Desea retornar al menu principal? si(1), no(0) \n ");
   scanf("%d",&exit_value);
   if (exit_value == 1 ) {
     screenclean();
     main();
   } else {printf("Pase un buen dia");}


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

//funciono principal del ejercicio 4
int exer_4() {
    int mes = 0;
    int counter8 = 1;
    int counter9 = 0;
    int exit_value2 = 0;
    int opcr6;
    float monthly_income[12];
    
    while (mes < 12 && exit_value2 != 1) {
        printf("\nMes: %d \n",counter8);
        printf("desea depositar este mes? si(1) no (0) \n");
        scanf("%d",&opcr6);

        if (opcr6 == 1) {
           printf("Ingrese la cantidad que de depositara este mes \n");
           scanf("%f",&monthly_income[mes]);

        }

        printf("Si desea salir digite 1 \n");
        scanf("%d",&exit_value2);
         
        counter8++;
        opcr6 =0;
        mes++;
    }
    exit_value2 = 0;

    printf("Sus opciones son: \n 1. Ver montos en un mes especifico \n 2. Ver los montos ingresados en cada mes \n 3. Salir al menu principal");
    scanf("%d",&opcr6);

    switch (opcr6)
    {
    case 1:
        while (exit_value2 != 2) {

        printf("\nDesea ver el monto almacenado en un mes dado? si(1) no o salir(2) \n");
        scanf("%d",&exit_value2);

        if (exit_value2==1) {
           printf("Ingrese el numero del mes \n ");
           scanf("%d",&opcr6);
           int opcr7 = opcr6 -1;
           printf("El monto ingresado en el mes %d es de: %.3f$ \n",opcr6, monthly_income[opcr7] );
        }

    }
        break;

    case 2:
        for(counter9=0;counter9<counter8-1;counter9++) {
          printf("La cantidad ingresada en el mes %d es de %.2f \n", counter9+1, monthly_income[counter9]);
          }
        break;

    case 3:
        screenclean();
        main();
        break;
    
    default:
        printf("\n opcion invalida, ser regresado al menu principal \n"); // check this
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


float get_studentgrades(int z){
    float grade_avarage;
    struct student_grades b;

   printf("\nEstudiante #%d \n",z);
   
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
     //float studentgrades[100];
     //int out = 0;
     int i,u,n;
     float swaper;
     int counter4 = 0;
     int counter11 = 0;
     float studendtnumb;
     float *studentgrades;
     
      printf("Ingrese el numero de estudiantes que va a ingresar \n");
      scanf("%f", &studendtnumb);    

      studentgrades = (float*) malloc(studendtnumb*sizeof(float));

      if (studentgrades == NULL) {
        printf("Memory allocation failed.\n");
    }
      
      n=1;
      for (counter11 =0; counter11 < studendtnumb;counter11++) {
      
         printf(" \n ingrese las notas del estudiante: %d \n", n);
        studentgrades[counter4] = get_studentgrades(n);
        printf("\n Promedio: %.2f \n", studentgrades[counter4]);
        printf("\n");
        counter4++;
        n++;
      } 

     float cant = sizeof(studentgrades)/sizeof(studentgrades[0]);
     //printf("\n %.3f \n", cant);


     for (i=0; i < cant -1; i++) {

        for (u=0; u < cant -i -1; u++) {
            if (studentgrades[u] < studentgrades[u+1]) { 
               swaper = studentgrades[u];
               studentgrades[u] = studentgrades[u+1];
               studentgrades[u+1] = swaper;
            }
        }
     }

    printf("La nota mas alta registrada es de %.2f \n", studentgrades[0] );
        
    return 0;
} 
 




int main (){
    int opcr0;
    printf("Bienvenidos a la guia 4 de ciclos \n");
    printf("Ingrese el numero del ejercicio que desea \n");
    scanf("%d",&opcr0);

    switch(opcr0) {
        case 1:
        printf("Ejercicio 1 elegido\n");
        screenclean();
        exer_1();
         break;

        case 2:
        printf("Ejercicio 2 elegido\n");
        screenclean();
        exer_2();
         break;

        case 3:
        printf("Ejercicio 3 elegido\n");
        screenclean();
        exer_3();
         break;

        case 4:
        printf("Ejercicio 4 elegido\n");
        screenclean();
        exer_4();
         break;

        case 5:
        printf("Ejercicio 5 elegido\n");
        screenclean();
        exer_5();
         break;

        default:
        printf("opcion invalida, usted sera regresado al menu \n");
        screenclean();
        main();

         break;
    }

    return 0;
}







