#include <stdio.h>
#include "functions.h"
#include <assert.h>
#include <stdlib.h>

int Puts(const char* str) {
    if (str != NULL) {
        printf("%s\n", str);
        return Strlen(str) + 1;

    }   else {
        return EOF;
    }     
}

char* Strchr(const char* str, int ch) {
    if (str != NULL) {
        for (int i = 0; str[i] != '\0'; ++i) {
            if (str[i] == ch) {
                return (char*)(str + i);
            }
        }

        return NULL;

    }   else {
        assert(0);
    }
}

 int Strlen(const char* str) {
    if (str != NULL) {
         int n = 0;

        for (int i = 0; str[i] != '\0'; ++i) {
            ++n;
        }

        return n;

    }   else {
        assert(0);
    }
}

char* Strcpy(char* destination, const char* source) {
    if (destination != NULL && source != NULL) {
        int i = 0;
        while (source[i] != '\0') {
            destination[i] = source[i];
            ++i; 
        }

        destination[i] = '\0';

        return destination;

    }   else {
        assert(0);
    }
}

char* Strncpy(char* destination, const char* source, int n) {
    if (destination != NULL && source != NULL && n >= 0) {
        bool nullterminated = false;

        for (int i = 0; i < n; ++i) {
            if (source[i] == '\0') {
                nullterminated = true;
            }

            if (!nullterminated) {
                destination[i] = source[i];

            }   else {
                destination[i] = '\0';
            }
        }

        return destination;

    }   else {
        assert(0);
    }
}

char* Strcat(char* destination, const char* append) {
    if (destination != NULL && append != NULL) {
        int end = Strlen(destination);

        for (int i = 0; append[i] != '\0'; ++i) {
            destination[end] = append[i];
            end++;
        }

        destination[end] = '\0';
        return destination;

    }   else {
        assert(0);
    }
}

char* Strncat(char* destination, const char* append, int n) {
    if (destination != NULL && append != NULL && n >= 0) {
        int end = Strlen(destination);

        for (int i = 0; i < n || append[i] != '\0'; ++i) {
            destination[end] = append[i];
            end++;
        }  

        destination[end] = '\0';
        return destination;    

    }   else {
        assert(0);
    }
}

char* Fgets(char* str, int n, FILE* stream) {
    if (str != NULL && stream != NULL && n >= 0) {
        int i = 0;

        int c = getc(stream);

        while (c != '\n' && c != EOF && i < n - 1) {
            str[i] = c;
            ++i;
            c = getc(stream);
        }

        if (i == 0 || ferror(stream)) {
            return NULL;

        }   else {
            str[i] = '\0';
            return str;
        }

    }   else {
        assert(0);
    }
}

char* Strdup(const char* str) {
    if (str != NULL) {
        int size = Strlen(str) + 1;
        char* dupstr = (char*)calloc(size, sizeof(char));

        if (dupstr == NULL) {
            return NULL;
        }   else {
            return Strcpy(dupstr, str);
        }

    }   else {
        assert(0);
    }
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
    if (lineptr != NULL && stream != NULL && *n >= 0) {
        int size = size_of_string(stream);

        if (*n >= size + 1) {
            char* buffer = NULL;
            if (size != 1) {
                buffer = Fgets(*lineptr, *n, stream);

                if (buffer == 0) {
                    return -1;
                }

                buffer[size - 1] = '\n';
                buffer[size] = '\0';

            }   else {
                buffer[0] = '\n';
                buffer[1] = '\0';
                getc(stream);
            }

        }   else if ((*(lineptr) == NULL) && (*n == 0)) {
            char* buffer = (char*)calloc(size + 1, sizeof(char)); 
            *n = size + 1;
            *lineptr = buffer;

            if (size != 1) {

                buffer = Fgets(*lineptr, *n, stream);

                if (buffer == NULL) {
                    return -1;
                }

                buffer[size - 1] = '\n';
                buffer[size] = '\0';

            }   else {
                buffer[0] = '\n';
                buffer[1] = '\0';
                getc(stream);
            }

        }   else {
            char* buffer = (char*)realloc(*lineptr, (size + 1) * sizeof(char)); 
            *n = size + 1;
            *lineptr = buffer;

            if (size != 1) {

                buffer = Fgets(*lineptr, *n, stream);

                if (buffer == NULL) {
                    return -1;
                }

                buffer[size - 1] = '\n';
                buffer[size] = '\0';

            }   else {
                buffer[0] = '\n';
                buffer[1] = '\0';
                getc(stream);
            }  
        }

        return size;

    }   else {
        assert(0);
    }
}