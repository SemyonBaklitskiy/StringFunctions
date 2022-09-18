#include "functions.h"
#include "test.h"

int main() {
#ifdef PUTS 
    test_puts();

#elif STRCHR
    test_strchr();

#elif STRLEN
    test_strlen();

#elif STRCPY
    test_strcpy();

#elif STRNCPY
    test_strncpy();    

#elif FGETS
    test_fgets();

#elif STRDUP
   test_strdup();

#elif GETLINE
    test_getline();

#elif STRCAT
    test_strcat();

#elif STRNCAT
    test_strncat();


#else 
    test_puts();
    test_strchr();
    test_strlen();
    test_strcpy();
    test_strncpy();
    test_strcat();
    test_strncat();
    test_fgets();
    test_strdup();
    test_getline();
#endif
}