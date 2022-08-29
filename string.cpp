#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "string.hpp"

int PUTS( const char *str )
{
    assert(str);

    int num_ch = 0;
    int error  = 1;

    while (str[num_ch] != '\0' && error != EOF)
        error = putchar(str[num_ch++]);

    if (error == EOF)
        return error;

    return putchar('\n');
}

const char *STRCHR( const char *str, int ch )
{
    assert(str);

    const char *curr_ch = str;

    while (*curr_ch != '\0')
    {
        if (*curr_ch == ch)
            return curr_ch;
            
        curr_ch++;
    }
    
    if (ch == '\0')
        return curr_ch;
    
    return nullptr;
}


unsigned long STRLEN( const char *str )
{
    assert(str);

    unsigned long num_ch = 0;

    while (str[num_ch] != '\0' && str[num_ch] != EOF)
        num_ch++;

    return num_ch;
}

char *STRCPY( char *dest, const char *src )
{
    assert(dest);
    assert(src);

    int num_ch = 0;

    while ((dest[num_ch] = src[num_ch])) 
        num_ch++;

    return dest;
}

char *STRNCPY( char *dest, const char *src, unsigned long count )
{
    assert(dest);
    assert(src);

    unsigned long num_ch = 0;

    while (num_ch < count && (dest[num_ch] = src[num_ch]))
        num_ch++;

    if (!src[num_ch] && count == num_ch)
        return dest;

    while (num_ch < count)
        dest[num_ch++] = '\0';

    return dest;
}

char *STRCAT( char *dest, const char *src )
{
    assert(dest);
    assert(src);

    int dest_ch = 0;
    int src_ch  = 0;

    while (dest[dest_ch] != '\0')
        dest_ch++;

    while (src[src_ch] != '\0')
        dest[dest_ch++] = src[src_ch++];

    dest[dest_ch] = '\0';

    return dest;
}

char *STRNCAT( char *dest, const char *src, unsigned long count )
{
    assert(dest);
    assert(src);

    unsigned long num_cpy = 0;
    unsigned long dest_ch = 0;

    while (dest[dest_ch] != '\0')
        dest_ch++;

    while (num_cpy < count && (dest[dest_ch] = src[num_cpy]))
    {
        num_cpy++;
        dest_ch++;
    }

    while (num_cpy < count)
        dest[dest_ch++] = '\0';

    return dest;
}

char *FGETS( char *str, int count, FILE *stream )
{
    assert(str);
    assert(stream);

    int curr_ch   = getc(stream);
    int num_count = 0;

    if (curr_ch == EOF)
        return nullptr;

    while (curr_ch != '\n' && curr_ch != EOF && num_count < count - 1)
    {
        str[num_count] = (char)curr_ch;
        curr_ch = fgetc(stream);
        num_count++;
    }

    str[curr_ch] = '\0';

    return str;
}

char *STRDUP( const char *str1 )
{
    assert(str1);

    char *str2 = nullptr;
    int num_ch = 0;

    str2 = (char *)malloc(sizeof(const char*) * sizeof(str1));

    if (str2 == nullptr)
        return nullptr;

    while ((str2[num_ch] = str1[num_ch]))
        num_ch++;

    return str2;
}

unsigned long find_rate( size_t *buff_size )
{
    size_t rate_two = 1;

    while (*buff_size >= rate_two)
        rate_two *= 2;

    *buff_size = rate_two;

    return rate_two;
}

long int GETLINE( char **buffer, unsigned long *buff_size, FILE * __restrict  __stream   )
{
    assert(*buffer);
    assert(buff_size);
    assert(__stream);

    int ch = fgetc(__stream);
    size_t ch_num = 0;

    while (ch != '\n')
    {
        if (ch_num == *buff_size - 2)
        {
            find_rate(buff_size);
            *buffer = (char *) realloc(*buffer, *buff_size);
            assert(*buffer);
        }
        (*buffer)[ch_num] = (char)ch; 
        ch = fgetc(__stream);
        ch_num++;
    }

    (*buffer)[ch_num++] = '\n';
    (*buffer)[ch_num] = '\0';

    return (long int) ch_num;
}
