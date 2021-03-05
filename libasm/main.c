#include <stdio.h>
#include <sys/errno.h>
#include <unistd.h>
#include <string.h>

//void start();
//int ft_atoi_base(char *str, char *base);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);

int main()
{
	// char *str = NULL;
	// printf("\nerrno before wrong call to write: %d\n", errno);
	printf("%d\n", ft_strcmp("Hello World!", ""));
	printf("%d\n", strcmp("Hello World!", ""));

	printf("%d\n", ft_strcmp("lorem\tipsum\tdolor\nsit\namet\n", "Hello 42!"));
	printf("%d\n", strcmp("lorem\tipsum\tdolor\nsit\namet\n", "Hello 42!"));

	printf("%d\n", ft_strcmp("testing  functions\0123456789", "\n\n\f\r\t"));
	printf("%d\n", strcmp("testing  functions\0123456789", "\n\n\f\r\t"));

	printf("%d\n", ft_strcmp("", "lorem teste"));
	printf("%d\n", strcmp("", "lorem teste"));

	printf("%d\n", ft_strcmp("    ", "   teste"));
	printf("%d\n", strcmp("    ", "   teste"));

	printf("%d\n", ft_strcmp("    ", "    "));
	printf("%d\n", strcmp("    ", "    "));
	// printf("\nerrno before wrong call to write: %d\n", errno);
	// ft_write(-1, "ciaone", 6);
	// printf("\nerrno after wrong call to write: %d\n", errno);
	//start();
	//printf("\n%d\n", ft_atoi_base("   	-+--1242235", "01234567"));
	return (0);
}
