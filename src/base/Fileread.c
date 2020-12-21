#include <Project.h>
int ascFileRead(const char *file,char **buff) {

    FILE *pFile;
    long lSize;

    size_t result;

    pFile = fopen(file, "rb");
    if (pFile == NULL)
    {
        fputs("File error", stderr);
        exit(1);
    }

    // obtain file size:
    fseek(pFile, 0, SEEK_END);
    lSize = ftell(pFile);
    rewind(pFile);

    // allocate memory to contain the whole file:
    *buff = (char *)malloc(sizeof(char) * (lSize));
    if (*buff == NULL)
    {
        fputs("Memory error", stderr);
        exit(2);
    }

    // copy the file into the buffer:
    result = fread(*buff, sizeof(char), lSize, pFile);

    if (result != lSize)
    {
        fputs("Reading error", stderr);
        exit(3);
    }

    /* the whole file is now loaded in the memory buffer. */
    // terminate
    fclose(pFile);

    return 0;
}

int ascFileWrite(const char *file,const char *buf){

    FILE *pFile = fopen(file, "wb");
    fwrite(buf, sizeof(char), strlen(buf), pFile);
    fclose(pFile);
    return 0;
}