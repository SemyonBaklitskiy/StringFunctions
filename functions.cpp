#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "functions.h"

int Puts(const char* str) {
    if (str != NULL) {
        for (int i = 0; str[i] != '\0'; ++i) {
            putchar(str[i]);
        }
        putchar('\n');

        return Strlen(str) + 1;

    }   else {
        return EOF;
    }     
}

char* Strchr(const char* str, int ch) {
    assert(str != NULL);

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == ch) {
            return (char*)(str + i);
        }
    }

    return NULL;

}

 int Strlen(const char* str) {
    assert(str != NULL);

    int n = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        ++n;
    }

    return n;
}

char* Strcpy(char* destination, const char* source) {
    assert(destination != NULL && source != NULL);

    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        ++i; 
    }

    destination[i] = '\0';

    return destination;
}

char* Strncpy(char* destination, const char* source, int n) {
    assert(destination != NULL && source != NULL && n >= 0);
    int i = 0;

    while (source[i] != '\0' && i < n) {
        destination[i] = source[i];
        ++i; 
    }

    for (int j = i; j < n; ++j) {
        destination[i] = '\0';
    }

    return destination;
}

char* Strcat(char* destination, const char* append) {
    assert(destination != NULL && append != NULL);
    int end = Strlen(destination);

    for (int i = 0; append[i] != '\0'; ++i) {
        destination[end] = append[i];
        end++;
    }

    destination[end] = '\0';
    return destination;
}

char* Strncat(char* destination, const char* append, int n) {
    assert(destination != NULL && append != NULL && n >= 0);

    int end = Strlen(destination);

    for (int i = 0; i < n && append[i] != '\0'; ++i) {
        destination[end] = append[i];
        end++;
    }  

    destination[end] = '\0';
    return destination;    
}

char* Fgets(char* str, int n, FILE* stream) {
    assert(str != NULL && stream != NULL && n > 0); 

    int i = 0;

    int c = getc(stream);
    if (c != EOF) {
        str[i] = c;
        ++i;
    }

    while (c != '\n' && c != EOF && i < n - 1) {
        c = getc(stream);
        str[i] = c;
        ++i;
    }

    if (i == 0 || ferror(stream)) 
        return NULL;

    str[i - 1] = '\n';
    str[i] = '\0';
    return str;
}

char* Strdup(const char* str) {
    assert(str != NULL);

    int size = Strlen(str) + 1;
    char* dupstr = (char*)calloc(size, sizeof(char));

    if (dupstr == NULL) 
        return NULL;

    return Strcpy(dupstr, str);
}

int size_of_string(FILE* stream) {
    int n = 1;
    int c = getc(stream);

    while (c != '\n' && c != EOF) {
        ++n;
        c = getc(stream);
    }

    fseek(stream, -n, SEEK_CUR);

    return n;
}

int Getline(char** lineptr, int* n, FILE* stream) {
    assert(lineptr != NULL && stream != NULL && *n >= 0);
    
    int size = size_of_string(stream);

    if ((*n >= size + 1) && (*lineptr != NULL)) {
        char* buffer = NULL;
        buffer = Fgets(*lineptr, *n, stream);

        if (buffer == NULL) 
            return -1;

        return size;

    } else if ((*n < size + 1) && (*lineptr != NULL)) {
        char* buffer = NULL;
        *n = size + 1;
        buffer = (char*)realloc(*lineptr, (size + 1) * sizeof(char));
        buffer = Fgets(*lineptr, *n, stream);

        if (buffer == NULL) 
            return -1;

        return size;

    } else {
        char* buffer = (char*)calloc(size + 1, sizeof(char));
        *lineptr = buffer;
        *n = size + 1;
        buffer = Fgets(*lineptr, *n, stream);

        if (buffer == NULL) 
            return -1;

        return size;  
    }   
}
