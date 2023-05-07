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


struct student_grades {

    // char name[59];
     float math;
     float science;
     float english;
     float spanish;
     float PE;
     float geography;
}; 

/* Se requiere un programa para determinar el promedio de la las n notas de
n estudiantes y al final determinar el promedio más alto. Utilice el ciclo apropiado.
Considere la opción salir, la cual retorna al menú principal. */


float get_studentgrades(int z){
    float grade_avarage;
    struct student_grades b;

   printf("\nEstudiante #%d \n",z);

   /* printf("Ingrese el nombre del estudiante");
   get(b.name);
   cleanbuff(); */
   
   printf("\n Ingrese nota de matematicas: ");
   scanf("%f",&b.math);
   cleanbuff();

   printf("\nIngrese nota de ciencias naturales: ");
   scanf("%f",&b.science);
   cleanbuff();

   printf("\nIngrese nota de spanish: ");
   scanf("%f",&b.spanish);
   cleanbuff();

   printf("\nIngrese nota de ingles: ");
   scanf("%f",&b.english);
   cleanbuff();

   printf("\nIngrese nota de EF: ");
   scanf("%f",&b.PE);
   cleanbuff();


   printf("\nIngrese nota de geografia: ");
   scanf("%f",&b.geography);
   cleanbuff();
   
   grade_avarage = b.english+b.geography+b.math+b.PE+b.science+b.spanish;
   grade_avarage = grade_avarage/6;
   printf("\n %.2f \n", grade_avarage);
   return grade_avarage;
}

int exer_5() { 
     float studentgrades[3];
     int out = 0;
     int i,u,n;
     float swaper;
     int counter4 = 0;
      while (out != 1) {
        printf("ingrese las notas del estudiante: \n");
        n=1;
        studentgrades[counter4] = get_studentgrades(n);
        printf("\n %.2f \n", studentgrades[counter4]);
        counter4++;
        n++;
        printf("Cuando termine de ingresar las notas de los estudiantes presione 1 \n");
        scanf("%d",&out);
     } 
     

     int cant = sizeof(studentgrades)/sizeof(studentgrades[0]);
     printf("\n %d \n", cant);


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
int main(){
   
   exer_5();


   return 0;
}