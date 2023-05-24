#include "monty.h"

ssize_t custom_getline(char** lineptr, size_t* n, FILE* file) {
    const size_t chunkSize = 32;  
    ssize_t bytesRead = 0;
    size_t totalBytesRead = 0;
    int nextChar;
    char* newLinePtr;

    if (*lineptr == NULL || *n == 0) {
        *n = chunkSize;
        *lineptr = (char*)malloc(*n);
        if (*lineptr == NULL) {
            perror("Error allocating memory");
            return -1;
        }
    }

    while ((nextChar = fgetc(file)) != EOF) {
        if (totalBytesRead >= *n - 1) {
            *n += chunkSize;
            newLinePtr = (char*)realloc(*lineptr, *n);
            if (newLinePtr == NULL) {
                perror("Error reallocating memory");
                return -1;
            }
            *lineptr = newLinePtr;
        }

        (*lineptr)[totalBytesRead] = (char)nextChar;
        totalBytesRead++;

        if (nextChar == '\n')
            break;
    }

    if (totalBytesRead == 0)
        return -1;

    (*lineptr)[totalBytesRead] = '\0';
    bytesRead = (ssize_t)totalBytesRead;
    return bytesRead;
}
