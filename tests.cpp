#include <string.h>
#include <iostream> 
#include <stdlib.h>
#include "color.hpp"
#include "string.hpp"

void test_strchr()
{
    char str[16] = "abvgd";
    char my_ch = '\0';

    if (*(STRCHR(str, my_ch)) == my_ch)
        printf(GREEN "str_chr -- ok\n" RESET);
    else 
        printf(RED "Expected: %c\n Real: %c\n" RESET, my_ch, *(STRCHR(str, my_ch)));
}

void test_strlen()
{
    char str[16] = "abvgd";

    if (STRLEN(str) == strlen(str))
        printf(GREEN "str_len -- ok\n" RESET);
    else
        printf(RED "Expected: %lu \n Real: %lu\n" RESET, strlen(str), STRLEN(str));
}

void test_strcpy()
{
    char dest1[14] = {};
    char dest2[14] = {};
    char src[]     = "abrakadabra";

    strcpy(dest1, src);
    STRCPY(dest2, src);

    if (!strcmp(dest1, dest2))
        printf(GREEN "str_cpy -- ok\n" RESET);
    else
        printf(RED "Expected: %s \n Real: %s\n" RESET, dest1, dest2);
}

void test_strncpy()
{
    char dest1[10] = {};
    char dest2[10] = {};
    char src[]     = "Copy me, please";

    strncpy(dest1, src, 4);
    STRNCPY(dest2, src, 4);

    if (!strcmp(dest1, dest2))
        printf(GREEN "str_ncpy -- ok\n" RESET);
    else
        printf(RED "Expected: %s \n Real: %s\n" RESET, dest1, dest2);
}

void test_strcat()
{
    char dest1[10] = "Biba";
    char dest2[10] = "Biba";
    char src[]     = "Boba";

    if (!strcmp(strcat(dest1, src), STRCAT(dest2, src)))
        printf(GREEN "strcat  -- ok\n" RESET);
    else 
        printf(RED "Expected: %s \n Real: %s\n" RESET, dest1, dest2);
}

void test_strncat()
{
    char dest1[100] = "Biba";
    char dest2[100] = "Biba";
    char src[]      = "Boba";

    strncat(dest1, src, 4);
    STRNCAT(dest2, src, 4);

    if (!strcmp(dest1, dest2))
        printf(GREEN "strncat -- ok\n" RESET);
    else 
        printf(RED "Expected: %s \n Real: %s\n" RESET, dest1, dest2);
}

void test_fgets()
{
    FILE *file = fopen("testfgets.txt", "r");
    char dest1[100] = {};
    char dest2[100] = {};

    fgets(dest1, 30, file);
    rewind(file);
    FGETS(dest2, 30, file);

    if (!strcmp(dest1, dest2))
        printf(GREEN "fgets   -- ok\n" RESET);
    else 
        printf(RED "Expected: %s \n Real: %s\n" RESET, dest1, dest2);

    fclose(file);
}

void test_strdup()
{
    char str1[] = "Copy me, please";
    char *str2  = STRDUP(str1);
    char *str3  = strdup(str1);

    if (sizeof(str2) == sizeof(str3) && !strcmp(str2, str3))
        printf(GREEN "strdup  -- ok\n" RESET);
    else 
        printf(RED "Expected: %s \n Real: %s\n" RESET, str3, str2);

    free(str2);
    free(str3);
}

void test_getline()
{
    size_t   buffer_size1   = 5;
    size_t   buffer_size2   = 5;
    char     *buffer1       = (char *)calloc(buffer_size1, 1);
    char     *buffer2       = (char *)calloc(buffer_size2, 1);
    long int caracter1      = getline(&buffer1, &buffer_size1, stdin);
    long int caracter2      = GETLINE(&buffer2, &buffer_size2, stdin);

    if ((caracter1 == caracter2) && !strcmp(buffer1, buffer2) && (buffer_size1 == buffer_size2))
        printf(GREEN "getline -- ok\n" RESET);
    else 
    {
        int curr_ch = 0;

        while (buffer1[curr_ch] != '\0' && buffer2[curr_ch] != '\0')
        {
            printf("%c : %c\n", buffer1[curr_ch], buffer2[curr_ch]);
            curr_ch++;
        }

        printf(RED "getline : my getline\n");
        printf("  %lu    :     %lu\n", buffer_size1, buffer_size2);
        printf("  %ld    :     %ld\n" RESET, caracter1, caracter2);
    }

    free(buffer1);
    free(buffer2);
}
