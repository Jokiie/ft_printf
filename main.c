#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	int	count;
	char *name = "Celia";
	char *str = "";
	count = 0;
	ft_printf("--tests avec (s)\n");

	ft_printf("ft_printf : %s\n", str);
	printf("le printf : %s\n", str);

	ft_printf("%s", (char *)NULL);
	printf("%s", (char *)NULL);

	ft_printf("ft_printf : tab(\t) v (\v) f(\f) r (\r) n \n");
	printf("vrai printf : tab(\t) v (\v) f(\f) r (\r) n \n");	

	count = ft_printf("\n30%%\n");
	count = ft_printf("The chars written are %d\n", count);
	
	count = printf("\n30%%\n");
	count = printf("The chars written are %d\n", count);
	
	ft_printf("--tests avec (c)--\n");

	ft_printf("%c\n", 'a');
	printf("%c\n", 'a');

	ft_printf("--tests avec (d)--\n");

	ft_printf("My printf : %d\n", -42);
	printf("Real printf : %d\n", -42);

	ft_printf("My printf : %d\n", 0);
	printf("Real printf : %d\n", 0);

	ft_printf("My printf : %d\n", 42);
	printf("Real printf : %d\n", 42);

	ft_printf("My printf : %d\n", 04242);
	printf("Real printf : %d\n", 04242);

	ft_printf("--tests avec (u)--\n");

	ft_printf("My printf : %u\n", -42);
	printf("Real printf : %u\n", -42);
	
	ft_printf("My printf : %u\n", 0);
	printf("Real printf : %u\n", 0);
	
	ft_printf("My printf : %u\n", 42);
	printf("Real printf : %u\n", 42);

	ft_printf("My printf : %u\n", 04242);
	printf("Real printf : %u\n", 04242);

	ft_printf("--tests avec (i)--\n");

	ft_printf("My printf : %i\n", -42);
	printf("Real printf : %i\n", -42);

	ft_printf("My printf : %i\n", 0);
	printf("Real printf : %i\n", 0);

	ft_printf("My printf : %i\n", 42);
	printf("Real printf : %i\n", 42);

	ft_printf("My printf : %i\n", 04242);
	printf("Real printf : %i\n", 04242);

	ft_printf("--tests avec (X)--\n");

	ft_printf("My printf : %X\n", -42);
	printf("Real printf : %X\n", -42);

	ft_printf("My printf : %X\n", 0);
	printf("Real printf : %X\n", 0);

	ft_printf("My printf : %X\n", 42);
	printf("Real printf : %X\n", 42);

	ft_printf("My printf : %X\n", -4242);
	printf("Real printf : %X\n", -4242);


	ft_printf("--tests avec (x)--\n");

	ft_printf("My printf : %x\n", -42);
	printf("Real printf : %x\n", -42);

	ft_printf("My printf : %x\n", 0);
	printf("Real printf : %x\n", 0);

	ft_printf("My printf : %x\n", 42);
	printf("Real printf : %x\n", 42);

	ft_printf("My printf : %x\n", 361);
	printf("Real printf : %x\n", 361);

	ft_printf("--tests avec (p)--\n");

	ft_printf("My printf : %p\n", name);
	printf("Real printf : %p\n", name);

	ft_printf("My printf : %p\n", (void*)0);
	printf("Real printf : %p\n", (void*)0);

	count = ft_printf("My printf : %p\n", (void*)-12345);
	count = printf("Real printf : %p\n", (void*)-12345);

	ft_printf("Pointer count = %d\n", count);
	printf("Pointer count = %d\n", count);

    ft_printf("--test : Format specifier not implemented.--\n");
    ft_printf("%f%.5d\n", 4.2, 42);
    printf("%f%.5d\n", 4.2, 42);

	ft_printf("--Final Test--\n");

	ft_printf("My printf : %c%s%p%d%i%u%x%X%%\n", 'a', name, 
	name, 42, 42, 42, 42, 42);
	printf("Real printf : %c%s%p%d%i%u%x%X%%\n", 'a', name, 
	name, 42, 42, 42, 42, 42);
	return (0);
}
