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


int exer_2(){

    float temp;
    float HS_cant, HD_cant, HT_cant, final_count, amountwithdisc = 0;
    int exit_value, disc = 0;
    int opcr4;

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
        break;
       
       case 2:
        printf("Cuantas hamburguesas dobles desea? \n");
        scanf("%f",&HD_cant);
        HD_cant = HD_cant + temp;
        break;

        case 3:
        printf("Cuantas hamburguesas triples desea? \n");
        scanf("%f",&HT_cant);
        HT_cant = HT_cant + temp;
        break;

       default:
       printf(" \n El item que usted ha pedido no se encuentra disponible por el momento \n");
        break;
       }

     printf("\n Si ha terminado su orden presione 1, en caso de querer algo mas presione cualquier otra tecla \n");
     scanf("%d",&exit_value);
    }

    printf("Usted ha terminado de ordener, desea pagar con efectivo (1) o tarjeta(2)? \n");
    scanf("%d",&exit_value);

    if (exit_value == 2) {
       printf("Usted ha elegido pagar con tarjeta por lo que tiene acceso a un 5 */* de descuento \n ");
       disc = 0.05;
    }

   final_count = HD_cant*20 + HS_cant*25+ HT_cant*28;
   amountwithdisc = final_count - (final_count*disc);

   printf("Su orden consta de: \n");
   if (HS_cant != 0) {
    printf(" %.f hamburguesas sencillas \n",HS_cant);
   }
   if (HD_cant != 0) {
    printf(" %.f hamburguesas dobles \n",HD_cant);
   }

   if (HT_cant != 0) {
    printf(" %.f hamburguesas triples \n",HT_cant);
   }

   //pendiente preguntarle al usuario si su orden es correcta y si no darle la opcion de cambiarla

   if (disc==0.05 ) {

   printf("por un total de: %.f$ con descuento y %.f$ sin descuento\n",amountwithdisc ,final_count);
   } else { printf("por un total de: %.f$ sin descuento\n",final_count); }

   printf("Desea retornar al menu principal? si(1), no(0) \n ");
   if (exit_value == 1 ) {
     screenclean();
     main();
   } else {printf("Pase un buen dia");}


   return 0;
}

/* Se requiere un programa para determinar cuánto ahorrará una persona en
un año, si al final de cada mes deposita variables cantidades de dinero; además, se
requiere saber cuánto lleva ahorrado cada mes. Utilice el ciclo apropiado. Considere la
opción salir, la cual retorna al menú principa*/

int exer_4() {
    int mes = 0;
    int exit_value2;
    int opcr6;
    float monthly_income[12];
    //float swaper;
    int counter7;
    
    while (mes <= 12 && exit_value2 != 1) {
        printf("desea depositar este mes? si(1) no (0) \n");
        scanf("%d",&opcr6);

        if (opcr6 == 1) {
           printf("Ingrese la cantidad que de positara este mes \n");
           scanf("%f",&monthly_income[mes]);
        }

        printf("Si desea salir digite 1 \n");
        scanf("%d",&exit_value2);

        mes++;
    }
    exit_value2 = 0;

    while (exit_value2 != 2) {

        printf("\nDesea ver el monto almacenado en un mes dado? si(1) no (2) \n");
        scanf("%d",&exit_value2);

        if (exit_value2==1) {
           printf("Ingrese el numero del mes \n ");
           scanf("%d",&opcr6);
           int opcr7 = opcr6 -1;
           printf("El monto ingresado en el mes %d es de: %.3f$ \n",opcr6, monthly_income[opcr7] );
        }

    }

    for (counter7=0; counter7<mes;counter7++) {

    }
    
   // for (){}
    
    return 0;
}

int main() {exer_4();return 0;}