#include <ctype.h> 

int isdigit( int arg );
	The isdigit() function checks whether a character is numeric character (0-9) or not.
	
	Parameters
	argument - a character
	
	Return Value	Remarks
	Zero (0)		If the parameter isn't an numeric character.
	Non zero number	If the parameter is an numeric character.

int isxdigit( int arg );
	The isxdigit() function checks whether a character is a hexadecimal digit character (0-9, a-f, A-F) or not.
	
	Parameters
	argument - a character
	
	Return Value	Remarks
	Zero (0)		If the parameter isn't a hexadecimal character.
	Non zero number	If the parameter is a hexadecimal character.

int isalpha(int argument);

	The isalpha() function checks whether a character is an alphabet or not.
	In C programming, isalpha() function checks whether a character is an alphabet (a to z and A-Z) or not.

	Parameters
	argument - a character

	Return Value	Remarks
	Zero (0)		If the parameter isn't an alphabet.
	Non zero number	If the parameter is an alphabet.
	
int isupper (Character);
	The isupper() function checks whether a character is an uppercase alphabet (A-Z) or not.
	
	Parameters
	argument - a character
	
	Return Value	Remarks
	Zero (0)		If the parameter isn't an uppercase alphabet.
	Non zero number	If the parameter is an uppercase alphabet.

int islower (Character);
	The islower() function checks whether a character is lowercase alphabet (a-z) or not.
	
	Parameters
	argument - a character
	
	Return Value	Remarks
	Zero (0)		If the parameter isn't an lowercase alphabet.
	Non zero number	If the parameter is an lowercase alphabet.


int tolower(int argument);
	
	The tolower() function takes an uppercase alphabet and convert it to a lowercase character.
	
	If the arguments passed to the tolower() function is other than an uppercase alphabet, 
	it returns the same character that is passed to the function.

int toupper(int ch);
	The toupper() function converts a lowercase alphabet to an uppercase alphabet.
	
	If the arguments passed to the tolower() function is other than an lowercase alphabet, 
	it returns the same character that is passed to the function.
	
int isalnum(int argument);

	The isalnum() function checks whether the argument passed is an alphanumeric character (alphabet or number) or not.

	isalnum() Parameters
	argument - a character

	isalnum() Return Value
	Returns 1 if argument is an alphanumeric character.
	Returns 0 if argument is neither an alphabet nor a digit.
	
int isspace(int argument);
	The isspace() function checks whether a character is a white-space character or not.

int iscntrl(int argument);
	The iscntrl() function checks whether a character is a control character or not.
	Characters that cannot be printed on the screen are known as control characters.  For example, backspace, Escape, newline etc.
		
	Parameters
	argument - a character

	Return Value	Remarks
	Zero (0)		If the parameter isn't an control character.
	Non zero number	If the parameter is an control character.

int isprint( int arg );
	The isprint() function checks whether a character is a printable character or not.
	Printable characters are just the opposite of control characters which can be checked using iscntrl().
	
int isgraph(int argument);
	The isgraph() function checks whether a character is a graphic character or not.
	Characters that have graphical representation are known are graphic characters.

int ispunct(int argument);
	The ispunct() function checks whether a character is a punctuation mark or not.
	All punctuations in C: 
	! " # $ % & ' ( ) * + , - . / : ; < = > ? @ [ \ ] ^ _ ` { | } ~
	
	
	
	
#include <stdlib.h>

long int strtol(const char *nptr, char **endptr, int base);
long long int strtoll(const char *nptr, char **endptr, int base);

	The strtol() function converts the initial part of the string in nptr to a long integer value according to the given base, 
	which must be between 2 and 36 inclusive, or be the special value 0.

	The string may begin with an arbitrary amount of white space (as determined by isspace(3)) followed by a single optional '+' or '-' sign. 
	If base is zero or 16, the string may then include a "0x" prefix, and the number will be read in base 16; 
	otherwise, a zero base is taken as 10 (decimal) unless the next character is '0', in which case it is taken as 8 (octal).

	The remainder of the string is converted to a long int value in the obvious manner, stopping at the first character which is not a valid digit in the given base. 
	(In bases above 10, the letter 'A' in either upper or lower case represents 10, 'B' represents 11, and so forth, with 'Z' representing 35.)

	If endptr is not NULL, strtol() stores the address of the first invalid character in *endptr. 
	If there were no digits at all, strtol() stores the original value of nptr in *endptr (and returns 0). 
	In particular, if *nptr is not '\0' but **endptr is '\0' on return, the entire string is valid.

	The strtoll() function works just like the strtol() function but returns a long long integer value.




#include <string.h>

Sr.No.	Function & Description
1	void *memchr(const void *str, int c, size_t n)
Searches for the first occurrence of the character c (an unsigned char) in the first n bytes of the string pointed to, by the argument str.

2	int memcmp(const void *str1, const void *str2, size_t n)
Compares the first n bytes of str1 and str2.

3	void *memcpy(void *dest, const void *src, size_t n)
Copies n characters from src to dest.

4	void *memmove(void *dest, const void *src, size_t n)
Another function to copy n characters from str2 to str1.

5	void *memset(void *str, int c, size_t n)
Copies the character c (an unsigned char) to the first n characters of the string pointed to, by the argument str.

6	char *strcat(char *dest, const char *src)
Appends the string pointed to, by src to the end of the string pointed to by dest.

7	char *strncat(char *dest, const char *src, size_t n)
Appends the string pointed to, by src to the end of the string pointed to, by dest up to n characters long.

8	char *strchr(const char *str, int c)
Searches for the first occurrence of the character c (an unsigned char) in the string pointed to, by the argument str.

9	int strcmp(const char *str1, const char *str2)
Compares the string pointed to, by str1 to the string pointed to by str2.

10	int strncmp(const char *str1, const char *str2, size_t n)
Compares at most the first n bytes of str1 and str2.

11	int strcoll(const char *str1, const char *str2)
Compares string str1 to str2. The result is dependent on the LC_COLLATE setting of the location.

12	char *strcpy(char *dest, const char *src)
Copies the string pointed to, by src to dest.

13	char *strncpy(char *dest, const char *src, size_t n)
Copies up to n characters from the string pointed to, by src to dest.

14	size_t strcspn(const char *str1, const char *str2)
Calculates the length of the initial segment of str1 which consists entirely of characters not in str2.

15	char *strerror(int errnum)
Searches an internal array for the error number errnum and returns a pointer to an error message string.

16	size_t strlen(const char *str)
Computes the length of the string str up to but not including the terminating null character.

17	char *strpbrk(const char *str1, const char *str2)
Finds the first character in the string str1 that matches any character specified in str2.

18	char *strrchr(const char *str, int c)
Searches for the last occurrence of the character c (an unsigned char) in the string pointed to by the argument str.

19	size_t strspn(const char *str1, const char *str2)
Calculates the length of the initial segment of str1 which consists entirely of characters in str2.

20	char *strstr(const char *haystack, const char *needle)
Finds the first occurrence of the entire string needle (not including the terminating null character) which appears in the string haystack.

21	char *strtok(char *str, const char *delim)
Breaks string str into a series of tokens separated by delim.

22	size_t strxfrm(char *dest, const char *src, size_t n)
Transforms the first n characters of the string src into current locale and places them in the string dest.