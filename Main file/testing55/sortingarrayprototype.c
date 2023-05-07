#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>


int main() {
 float studentgrades[100];
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

  }





}