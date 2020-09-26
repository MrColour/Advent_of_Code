#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

char* ReadFile(char *filename)
{
    char *buffer = NULL;
    int string_size, read_size;
    FILE *handler = fopen(filename, "r");
    if (handler)
    {
        fseek(handler, 0, SEEK_END);
        string_size = ftell(handler);
        rewind(handler);
        buffer = (char*) malloc(sizeof(char) * (string_size + 1) );
        read_size = fread(buffer, sizeof(char), string_size, handler);
        buffer[string_size] = '\0';
        if (string_size != read_size)
        {
            free(buffer);
            buffer = NULL;
        }
        fclose(handler);
    }
    return buffer;
}

int main()
{
    struct timeval stop, start;

    char *string = ReadFile("input.txt");
    int i = 0;
    int n_lines = 0;
    while (string[i] != '\0'){
        if (string[i] == ':'){
            n_lines++;
        }
        i++;
    }
    char *positions = malloc(n_lines * sizeof(int));
    char *depth = malloc(n_lines * sizeof(int));
    char *end = string;
    int pos = 0;
    int pospos = 0;
    while(*end) {
        int n = strtol(string, &end, 10);
        if (pos==0){
            positions[pospos] = n;
            pos = 1;
        } else {
            depth[pospos] = (n-1)*2;
            pos = 0;
            pospos++;
        }
        while (*end == ':' || *end == '\n') {
            end++;
        }
        string = end;
    }
    gettimeofday(&start, NULL);
    int offset = 0;
    int caught_yet;
    while(1) {
        caught_yet = 0;
        for (i = 0; i < n_lines; i++) {
            if ((positions[i] + offset) % depth[i] == 0) {
                caught_yet = 1;
                break;
            }
        }
        if (caught_yet == 0) {
            break;
        }
        offset++;
    }
    gettimeofday(&stop, NULL);
    printf("Best offset is %d\n", offset);
    printf("Took %f ms\n", ((stop.tv_sec*1e6 + stop.tv_usec) - (start.tv_sec*1e6 + start.tv_usec))/1e6);
    return 0;
}
