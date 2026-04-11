#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

extern size_t ft_strlen(const char *s);
extern char *ft_strcpy(char *dst, char *src);
extern int ft_strcmp(char *s1, char *s2);
extern ssize_t ft_write(int fd, const void *buf, size_t len);
extern ssize_t ft_read(int fd, void *buf, size_t count);
extern char *ft_strdup(const char *s);


int main(void)
{
    printf("Length ft_strlen : %ld\n", ft_strlen("Hello"));
	printf("Length strlen : %ld\n", ft_strlen("Hello"));

	char *dst1;
	char *dst2;
	printf("String ft_strcpy : %s\n", ft_strcpy(dst1, "Hello"));
	printf("String strcpy : %s\n", strcpy(dst2, "Hello"));

    printf("Difference strcmp : %d\n", strcmp("Hello", "Hellp"));
    printf("Difference ft_strcmp : %d\n", ft_strcmp("Hello", "Hellp"));
    
    ft_write(1, "Hello", strlen("Hello"));
    printf(": ft_write \n");
    write(1, "Hello", strlen("Hello"));
    printf(": write \n");

    char buffer1[1024];
    int len1;
    len1 = ft_read(0, buffer1, sizeof(buffer1) - 1);
    if (len1 == -1)
    {
        perror("OH NO ! ft_read error");
        return 1;
    }
    buffer1[len1] = '\0';
    printf("ft_read  %d octets : %s\n", len1, buffer1);
    char buffer2[1024];
    int len2;
    len2 = read(0, buffer2, sizeof(buffer2) - 1);
    if (len2 == -1)
    {
        perror("OH NO ! read error");
        return 1;
    }
    buffer2[len2] = '\0';
    printf("read  %d octets : %s\n", len2, buffer2);
    
    const char *s1 = "Hello libasm!";
    char *dup1;
    char *dup2;
    dup1 = ft_strdup(s1);
    dup2 = strdup(s1);
    printf("Original : \"%s\"\n", s1);
    printf("ft_strdup: \"%s\"\n", dup1);
    printf("strdup   : \"%s\"\n", dup2);
    free(dup1);
    free(dup2);
    return (0);
}


// int	main(int argc, char **argv)
// {
//     if (argc == 2)
//     {
//     	printf("Length ft_strlen : %ld\n", ft_strlen(argv[1]));
// 	    printf("Length strlen : %ld\n", ft_strlen(argv[1]));
//     }
//     return (0);
// }



// int main(int argc, char **argv)
// {
// 	char dst1[1024];
// 	char dst2[1024];
// 	if (argc == 2)
// 	{
// 		ft_strcpy(dst1, argv[1]);
//         strcpy(dst2, argv[1]);
// 		printf("String ft_strcpy : %s\n", dst1);
// 		printf("String strcpy : %s\n", dst1);
// 	}
// 	return (0);
// }



// int main(int argc, char **argv)
// {
// 	if (argc == 3)
// 	{
// 		printf("Difference ft_strcmp : %d\n", ft_strcmp(argv[1], argv[2]));
//         printf("Difference strcmp : %d\n", strcmp(argv[1], argv[2]));
// 	}
// 	return (0);
// }



// int main(int argc, char **argv)
// {
//     if (argc == 2)
//     {
//         ft_write(1, argv[1], strlen(argv[1]));
//         printf(": ft_write \n");
//         write(1, argv[1], strlen(argv[1]));
//         printf(": write \n");
//     }
//     return (0);
// }



// int main(int argc, char **argv)
// {

//     int fd1 = open(argv[1], O_RDONLY);
//     char buffer1[1024];
//     int len1;
//     len1 = ft_read(fd1, buffer1, sizeof(buffer1) - 1);
//     if (len1 == -1)
//     {
//         perror("OH NO ! ft_read error");
//         return 1;
//     }
//     buffer1[len1] = '\0';
//     printf("ft_read  %d octets : %s\n", len1, buffer1);
    
//     int fd2 = open(argv[1], O_RDONLY);
//     char buffer2[1024];
//     int len2;
//     len2 = read(fd2, buffer2, sizeof(buffer2) - 1);
//     if (len2 == -1)
//     {
//         perror("OH NO ! read error");
//         return 1;
//     }
//     buffer2[len2] = '\0';
//     printf("read  %d octets : %s\n", len2, buffer2);
//     return 0;
// }



// int main(void)
// {
//     const char *s1 = "Hello libasm!";
//     char *dup1;
//     char *dup2;

//     dup1 = ft_strdup(s1);
//     dup2 = strdup(s1);
//     printf("Original : \"%s\"\n", s1);
//     printf("ft_strdup: \"%s\"\n", dup1);
//     printf("strdup   : \"%s\"\n", dup2);
//     free(dup1);
//     free(dup2);
//     return (0);
// }

