#ifndef STRING_HPP
#define STRING_HPP

#include <stdio.h>

///--------------------------------------------
///@brief This fuction prints line into standart output 
///@param [in] str - poiter on the line to print 
///@param [out]  >0 in case success EOF - in case error 
///--------------------------------------------
int PUTS( const char *str ); 

///--------------------------------------------
///@brief This function look up a char in the string and return pointer to  it 
///@param [in]  str      - pointer the string 
///@param [in]  ch       - the char to find 
///@param [out] curr_ch  - pointer the the char 
///@return nullptr in case there is no such char else pointer to  the char  
///--------------------------------------------
const char *STRCHR( const char *str, int ch );

///--------------------------------------------
///@brief This function determines the lenth of the string 
///@param [in]  str    - string to determine lenth 
///@param [out] num_ch - lenth of the string 
///@return num_ch
///--------------------------------------------
unsigned long STRLEN( const char *str );

///--------------------------------------------
///@brief This function copy the source string to the destination string 
///@param [in]  src  - the pointer to the source string
///@param [in]  dest - the pointer to the destination string
///@param [out] dest - the pointer to the destination string
///@return  dest
///--------------------------------------------
char *STRCPY( char *dest, const char *src );

///--------------------------------------------
///@brief This function copy only n characters from the source string to the destination string 
///@note if n characters was copied the destination string is complited with '\0'
///@param [in]  src  - the pointer to the source string
///@param [in]  dest - the pointer to the destination string
///@param [out] dest - the pointer to the destination string
///@return  dest
///--------------------------------------------
char *STRNCPY( char *dest, const char *src, unsigned long count );

///--------------------------------------------
///@brief This function adds the source sting to the destination string 
///@param [in]  src  - the pointer to the source string
///@param [in]  dest - the pointer to the destination string
///@param [out] dest - the pointer to the destination string
///@return  dest
///--------------------------------------------
char *STRCAT( char *dest, const char *src );

///--------------------------------------------
///@brief This function adds the source sting to the destination string 
///@note if all characters hacve been copied from the source string the function complites the destination sting with '\0'
///@param [in]  src  - the pointer to the source string
///@param [in]  dest - the pointer to the destination string
///@param [out] dest - the pointer to the destination string
///@return  dest
///--------------------------------------------
char *STRNCAT( char *dest, const char *src, unsigned long count );

///--------------------------------------------
///@brief This function gets a line from an input stream 
///@param [in]  str    - sting to add characters from an input stream
///@param [in]  count  - number of characters, which can be added to the sting
///@param [in]  stream - pointer to an input stream
///@param [out] str    - pointer to the string to add characters from an input stream
///@return str
///--------------------------------------------
char *FGETS( char *str, int count, FILE *stream );

///--------------------------------------------
///@brief This function copies string to a new sting
///@note The function allocs memory. It is nessesery to free it after using to avoid leak 
///@param [in] str1 - the source string
///@param [in] str2 - destination string 
///@return st2
///--------------------------------------------
char *STRDUP( const char *str1 );

///--------------------------------------------
///@brief This function gets a line from an input stream 
///@note The function reallocs memory in case buffer size is less than the input string size 
///@param [in]  buffer    - the pointer to the pointer to the buffer, where to read the input string 
///@param [in]  buff_size - the pointer to the size of the buffer
///@param [in]  __stream  - the pointer to the input stream 
///@param [out] num_ch    - number of the characters, which have been red
///@return num_ch
///--------------------------------------------
long int GETLINE( char **buffer, unsigned long *buff_size, FILE * __restrict __stream );

///--------------------------------------------
///@brief A test function for the strchr
///--------------------------------------------
void test_strchr();

///--------------------------------------------
///@brief A test function for the strlen
///--------------------------------------------
void test_strlen();

///--------------------------------------------
///@brief A test function for the strcpy
///--------------------------------------------
void test_strcpy();

///--------------------------------------------
///@brief A test function for the strncpy
///--------------------------------------------
void test_strncpy();

///--------------------------------------------
///@brief A test function for the strcat
///--------------------------------------------
void test_strcat();

///--------------------------------------------
///@brief A test function for the strncat
///--------------------------------------------
void test_strncat();

///--------------------------------------------
///@brief A test function for the fgets
///--------------------------------------------
void test_fgets();

///--------------------------------------------
///@brief A test function for the strdup 
///--------------------------------------------
void test_strdup();

///--------------------------------------------
///@brief A test function for the getline
///--------------------------------------------
void test_getline();

///--------------------------------------------
///@brief This function finds nearest rate of two, which is larger than an input number
///@note The input number changes with such rate of two
///@param [in]  buff_size - pointer on the input number 
///@param [out] rate_two  - rate of two, which is bigger than the input number 
///@return rate_two
///--------------------------------------------
unsigned long find_rate( size_t *buff_size );

#endif
