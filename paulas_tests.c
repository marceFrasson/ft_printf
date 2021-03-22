
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "ft_printf.h"


int        main(void)
{
    char c = 'a'; //caracter
    char *s = "palavra - palavra - palavra"; //ponteiro de string

    int d = -32; //inteiro
    int i = d; //inteiro
    unsigned int u = 300564; //insine int

    int x = -56; //hexadecimal
    int X = -5678; //HEXADECIMAL
    char *p = &c; //endereço de ponteiro

    int width = 20;
    int press = 10;

    // printf(" -- %d\n",ft_printf("c = |%*c|",width,c)-6);
    // printf(" -- %d\n\n",printf("c = |%*c|",width,c)-6);

    //  printf(" -- %d\n",ft_printf("s = |%*.*s|",width,press,s)-6);
    // printf(" -- %d\n\n",printf("s = |%*.*s|",width,press,s)-6);

    //  printf(" -- %d\n",ft_printf("s = |%*.*s|",width,press,NULL)-6);
    // printf(" -- %d\n\n",printf("s = |%*.*s|",width,press,NULL)-6);

    // printf(" -- %d\n",ft_printf("d = |%*.*d|",width,press,d)-6);
    //  printf(" -- %d\n\n",printf("d = |%*.*d|",width,press,d)-6);

	

    printf(" -- %d\n",ft_printf(" --0*%0*.10i*0-- ", -41, INT_MIN));
     printf(" -- %d\n\n",printf(" --0*%0*.10i*0-- ", -41, INT_MIN));

	// printf(" -- %d\n",ft_printf("|%p %p|", 18446744073709551616, -18446744073709551616));
    //  printf(" -- %d\n\n",printf("|%p %p|", 18446744073709551616, -18446744073709551616));

	//  printf(" -- %d\n",ft_printf("|%p %p|", INT_MIN, INT_MAX));
    //  printf(" -- %d\n\n",printf("|%p %p|", INT_MIN, INT_MAX));

	//  printf(" -- %d\n",ft_printf("|%p %p|", LONG_MIN, LONG_MAX));
    //  printf(" -- %d\n\n",printf("|%p %p|", LONG_MIN, LONG_MAX));


    // printf(" -- %d\n",ft_printf("u = |%*.*u|",width,press,u)-6);
    // printf(" -- %d\n\n",printf("u = |%*.*u|",width,press,u)-6);

    // printf(" -- %d\n",ft_printf("x = |%*.*x|",width,press,x)-6);
    // printf(" -- %d\n\n",printf("x = |%*.*x|",width,press,x)-6);

    // printf(" -- %d\n",ft_printf("X = |%*.*X|",width,press,X)-6);
    // printf(" -- %d\n\n",printf("X = |%*.*X|",width,press,X)-6);

    // printf(" -- %d\n",ft_printf("|%03.3i|", 6983)-2);
    // printf(" -- %d\n\n",printf("|%03.3i|", 6983)-2);

    // printf(" -- %d\n",ft_printf("X = |%*.*X|",width,press,X)-6);
    // printf(" -- %d\n\n",printf("X = |%*.*X|",width,press,X)-6);

	
	
	return(0);
}

/*
int main(void)
{
	char *str = "ADFJK";
	int ch;
	
	// ft_printf("\n   pntr |%-20.25p|   string |%15s|   char |%-20.4c|   prcnt |%5%|   digit |%15d|\n\n", &*str, str, 'w', 465782);
	// ch = printf("   pntr |%-20.25p|   string |%15s|   char |%-20.4c|   prcnt |%5%|   digit |%15d|\n\n", &*str, str, 'w', 465782);

	// ft_printf("\n   pntr |%020.25p|   string |%-15s|   char |%20.4c|   prcnt |%-5%|   digit |%015.15d|\n\n", &*str, str, 'w', 465782);
	// ch = printf("   pntr |%020.25p|   string |%-15s|   char |%20.4c|   prcnt |%-5%|   digit |%015.15d|\n\n", &*str, str, 'w', 465782);

	// ft_printf("\n   pntr |%20.5p|   string |%025s|   char |%-4.10c|   prcnt |%-5.2%|   digit |%-15.10d|\n\n", &*str, str, 'w', 465782);
	// ch = printf("   pntr |%20.5p|   string |%025s|   char |%-4.10c|   prcnt |%-5.2%|   digit |%-15.10d|\n\n", &*str, str, 'w', 465782);

	// ft_printf("\n   pntr |%-5.20p|   string |%-5.15s|   char |%4.10c|   prcnt |%5.%|   digit |%015d|\n\n", &*str, str, 'w', 465782);	
	// ch = printf("   pntr |%-5.20p|   string |%-5.15s|   char |%4.10c|   prcnt |%5.%|   digit |%015d|\n\n", &*str, str, 'w', 465782);

	// ft_printf("\n   pntr |%05.25p|   string |%20.5s|   char |%020.4c|   prcnt |%0%|   digit |%010.15d|\n\n", &*str, str, 'w', 465782);
	// ch = printf("   pntr |%05.25p|   string |%20.5s|   char |%020.4c|   prcnt |%0%|   digit |%010.15d|\n\n", &*str, str, 'w', 465782);

	// ft_printf("%.7s %.2s\n", "hello", "world");
	// printf("%.7s %.2s\n", "hello", "world");

	// printf("\n\n");

	// ft_printf("%5.i\n", 0);
	// printf("%5.i\n", 0);	

	// printf("\n\n");

	// ft_printf("%%06i -54 == |%0*i|\n", 6, -54);
	// printf("%%06i -54 == |%0*i|", 6, -54);	

	// printf("\n\n");

	// ft_printf("%%.6i -54 == |%.*i|\n", 6, -54);
	// printf("%%.6i -54 == |%.*i|", 6, -54);	

	// printf("\n\n");

	// ft_printf("%%.16i -54 == |%016i|\n", -54);
	// printf("%%.16i -54 == |%016i|", -54);

	// printf("\n\n");

	// ft_printf("%%.-6i -3 == |%.*i|\n", -6, -3);
	// printf("%%.-6i -3 == |%.*i|\n", -6, -3);

	// printf("\n\n");


	// ft_printf("%%04.3i 42 == |%04.3i|\n", 42);
	// printf("%%04.3i 42 == |%04.3i|\n", 42);

	// printf("\n");

	int i = 0;

	while (i--)
		printf("oi");

	return (0);
}*/
