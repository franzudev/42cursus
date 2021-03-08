#include <stdio.h>
#include <sys/errno.h>
#include <unistd.h>
#include <string.h>

//void start();
//int ft_atoi_base(char *str, char *base);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
char*     ft_atoi_base(char *str, char *base);
int     ft_strchr(char *str, char ch);


int main()
{
    // int res = 0;
    // int i = 0;

    // while (i < 127)
    // {
    //     printf("i: %d || res: %d\n", i, ft_strchr("ciao", i));
    //     res += ft_strchr("ciao", i++);
    // }
    // printf("%d\n", ft_strchr("ciao", '0'));
    // printf("%d\n", res);
	printf("%s\n", ft_atoi_base("   -+-++---ffff", "61123"));
	return (0);
}

/* #include <stdio.h>
#include <string.h>
#include <sys/errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
size_t ft_strlen(char *s);
int ft_strcmp(const char *s1, const char *s2);
char *ft_strcpy(char *dst, const char *src);
ssize_t ft_write(int fd, const void *buf, size_t nbyte);
ssize_t ft_read(int fd, void *buf, size_t nbyte);
char    *ft_strdup(const char *s1);
int main() {
    char *str1 = "This is a string...\n";
    char *str2 = "Gaspacho\n";
    char *empty = "";
    char *ok = "qoigio;rqo;iqrinqr'inerqh'pinqhr'inqhr'pqerna\n";
    printf("\n\n-------------------TEST FT_STRLEN--------------------------\n\n");
    printf("  real: %lu\nlibasm: %lu\n", strlen(str1), ft_strlen(str1));
    printf("  real: %lu\nlibasm: %lu\n", strlen(empty), ft_strlen(empty));
    printf("  real: %lu\nlibasm: %lu\n", strlen(ok), ft_strlen(ok));
    printf("\n\n-------------------TEST FT_STRCPY--------------------------\n\n");
    char    empty1[50];
    char    empty2[50];
    printf("  real: %s\nlibasm: %s\n", strcpy(empty1, str1), ft_strcpy(empty2, str1));
    printf("\n\n-------------------TEST FT_STRCMP--------------------------\n\n");
    printf("  real: %i\nlibasm: %i\n", strcmp(str1, str2), ft_strcmp(str1, str2));
    printf("  real: %i\nlibasm: %i\n", strcmp(empty, str1), ft_strcmp(empty, str1));
    printf("  real: %i\nlibasm: %i\n", strcmp(ok, str2), ft_strcmp(ok, str2));
    printf("\n\n-------------------TEST FT_WRITE--------------------------\n\n");
    printf("real return: %zi\n", write(1, str2, 9));
    printf("libasm return: %zi\n", ft_write(1, str2, 9));
    printf("\n");
    printf("Real Error:%zi, %s\n", write(-7, str2, 7), strerror(errno));
    printf("Libasm Error:%zi, %s\n", ft_write(-7, str2, 7), strerror(errno));
    printf("\n\n-------------------TEST FT_READ--------------------------\n\n");
    char *buffer1 = calloc(500, sizeof(char));
    char *buffer2 = calloc (500, sizeof(char));
    int fd = open("test", O_RDONLY);
    printf("real return: %zi, %s\n", read(fd, buffer1, 5), buffer1);
    fd = open("test", O_RDONLY);
    printf("libasm return: %zi, %s\n", ft_read(fd, buffer2, 5), buffer2);
    printf("\n");
    printf("Real Error:%zi, %s\n", read(-7, buffer1, 7), strerror(errno));
    printf("Libasm Error:%zi, %s\n", ft_read(-7, buffer2, 7), strerror(errno));
    printf("\n\n-------------------TEST FT_STRDUP--------------------------\n\n");
    printf("  real: %s\nlibasm: %s\n", strdup(str1), ft_strdup(str1));
    printf("  real: %s\nlibasm: %s\n", strdup(empty), ft_strdup(empty));
    printf("  real: %s\nlibasm: %s\n", strdup(ok), ft_strdup(ok));

} */

