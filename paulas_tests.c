	#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "ft_printf.h"


int	main(void)
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

	   printf(" -- %d\n",ft_printf("d = |%*.*d|",width,press,d)-6);
     	printf(" -- %d\n\n",printf("d = |%*.*d|",width,press,d)-6);

   	 printf(" -- %d\n",ft_printf("i = |%*.*d|",width,press,i)-6);
     	printf(" -- %d\n\n",printf("i = |%*.*d|",width,press,i)-6);


	return (0);
}