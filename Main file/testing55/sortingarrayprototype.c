#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>

void cleanbuff(){
    fflush(stdin);
    fflush(stdout);
}

// shit to do 1. Use quicksort 2. Assotiate the grade with a name and number

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
     //int arraysize;
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



int main() {
/* float studentgrades[100];
 float swaper;
 int out = 0;
 int i,u;
 int counter4 = 1;
 int counter5 =0;     

 float studentgrades[] = {91.75, 76.23,87.64,62.21,85.0}; 
 int cant = sizeof(studentgrades)/sizeof(studentgrades[0]);

  for (i=0; i < cant-1; i++) {

     for (u=0; u < cant-1; u++) {
        swaper = studentgrades[u];
        studentgrades[u] = studentgrades[u+1];
        studentgrades[u+1] = swaper;

     }

  } */

   exer_5();

   return 0;
}