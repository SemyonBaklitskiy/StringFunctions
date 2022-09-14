#include <stdio.h>

int Strlen(const char* str);

int Puts(const char* str);

char* Strchr(const char* str, int ch);

char* Strcpy(char* destination, const char* source);

char* Strncpy(char* destination, const char* source, int n);

char* Strcat(char* destination, const char* append);

char* Strncat(char* destination, const char* append, int n);

char* Fgets(char* str, int n, FILE* stream);

char* Strdup(const char* str);

int size_of_string(FILE* stream);

int Getline(char** lineptr, int* n, FILE* stream);