/*
 * @Name: dcat: cat - Donya OS
 * @Author: Max Base
 * @Repository: github.com/basemax/dcat
 * @Date: 2020-07-11
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <limits.h>

#define DEBUG 1
static int verbose_flag;
char* PROGRAM_NAME="dcat";

// lAbeEnstTuv flags
int lflag=0;
// int Aflag=0;
int bflag=0;
// int eflag=0;
int Eflag=0;
int nflag=0;
int sflag=0;
// int tflag=0;
int Tflag=0;
int uflag=0;
int vflag=0;

size_t size;
int line=1;

void cat(int type, char* contents) {
    // line=1;
    int i=0;
    int iStart=0;
    if(nflag)
        printf("%6d\t", line);
    int isLine;
    if(type == 1)
        isLine=1;
    else
        isLine=0;
    while(i<size) {
        if(contents[i] == '\n' || contents[i] == '\r') {
            line++;
            if(i+1 < size && contents[i] == '\r' && contents[i+1] == '\n') {
                i++;
            }
            if(type == 1) {
                isLine=1;
            }
            // printf("%c", contents[i]);
            if(Eflag)
                putchar('$');
            if(sflag) {
                printf("\r\n");
                i++;
                int shows=0;
                while(contents[i] == '\n' || contents[i] == '\r') {
                    // printf("next char, %d\n", contents[i]);
                    if(contents[i] == '\n' && shows == 0) {
                        printf("%6d\t", line);
                        if(Eflag)
                            putchar('$');
                        printf("\r\n");
                        shows=1;
                    }
                    i++;
                }
                i--;
            }
            else {
                printf("\r\n");
                // putchar('\n');
            }
        }
        else {
            if(Tflag && contents[i] == '\t')
                printf("^I");
            else
                putchar(contents[i]);
                // printf("%c", contents[i]);
        }
        if(isLine==1) {
            if(nflag)
                printf("%6d\t", line);
            isLine=0;
        }
        i++;
    }
}

void reading(char* filename) {
    if(filename!=NULL)
        printf("Reading %s\n", filename);
    else
        printf("Reading STDIN\n");

    if(filename!=NULL) {
        FILE *stream;
        char *contents;
        int fileSize = 0;

        // Open file
        // if(filename==NULL)
        //     stream=stdin;
        // else
        //     stream = fopen(filename, "rb");
        stream = fopen(filename, "rb");

        // Find the size of file
        fseek(stream, 0L, SEEK_END);
        fileSize = ftell(stream);
        fseek(stream, 0L, SEEK_SET);

        // Allocate space for the entire file content
        contents = (char*)malloc(fileSize + 1);

        // Stream file into memory
        size = fread(contents, 1, fileSize, stream);
        contents[size] = 0;
        fclose(stream);

        // printf("%s\n", contents);
        cat(1, contents);
        // putchar('\n');
        // printf("\r\n");
    }
    else {
        while(1) {
            // size_t bufsize = 1024;
            // char *lineStream = (char *) malloc(bufsize+1);

            // scanf("%s", lineStream); // Getting one word!
            // scanf(" %[^\n]", lineStream); // Very Bad code
            // scanf(" %1023[^\n]", lineStream); // Better code

            char lineStream[1024];
            if(fgets(lineStream, sizeof lineStream, stdin)) {
                lineStream[strcspn(lineStream, "\n")] = '\0'; // Lop off potential tailing \n
                // printf("%s\n", lineStream);
                size=strlen(lineStream);
                cat(2, lineStream);
                printf("\r\n");
            }
            else {
                fprintf(stderr, "IO Error in stdin input.\n");
                break; // Stop loop
            }

            // if(getline(&lineStream, &bufsize, stdin) == -1) {
            //     fprintf(stderr, "IO Error in stdin input.\n");
            //     break; // Stop loop
            // }
            // else { printf("%s\n", lineStream);}
        }
    }

    // Close stream
    // if(stream!=stdin)
    // if(filename!=NULL)
    //     fclose(stream);
    // else
    //     clearerr(stream);
}

void version(int status) {
    puts("dcat (Donya OS) 1.0\n\
Copyright (C) 2020 Max Base.\n\
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.\n\
This is free software: you are free to change and redistribute it.\n\
There is NO WARRANTY, to the extent permitted by law.\n\
\n\
Written by Max Base.\n");
    exit(status);
}

void usage(int status) {
    if(status != EXIT_SUCCESS)
        fprintf(stderr, "Try `%s --help' for more information.\n", PROGRAM_NAME);
    else
        printf("Usage: %s [OPTION]... [FILE]...\n\
Concatenate FILE(s) to standard output.\n\
\n\
With no FILE, or when FILE is -, read standard input.\n\
\n\
-l, --learn              learn and read offline documentation\n\
-A, --show-all           equivalent to -vET\n\
-b, --number-nonblank    number nonempty output lines, overrides -n\n\
-e                       equivalent to -vE\n\
-E, --show-ends          display $ at end of each line\n\
-n, --number             number all output lines\n\
-s, --squeeze-blank      suppress repeated empty output lines\n\
-t                       equivalent to -vT\n\
-T, --show-tabs          display TAB characters as ^I\n\
-u                      (ignored)\n\
-v, --show-nonprinting   use ^ and M- notation, except for LFD and TAB\n\
--help     display this help and exit\n\
--version  output version information and exit\n\
\n\
Examples:\n\
cat f - g  Output f's contents, then standard input, then g's contents.\n\
cat        Copy standard input to standard output.\n\
\n\
Programming by Max Base\n\
Full documentation at: <https://github.com/basemac/dcat>\n\
or available locally via: 'dcat --learn'\n", PROGRAM_NAME);
    exit(status);
}

int main(int argc, char **argv) {
    int c;
    register FILE *fi;
    // http://agentzh.org/misc/code/coreutils/system.h.html
    enum {
        GETOPT_HELP_CHAR = (CHAR_MIN - 2),
        GETOPT_VERSION_CHAR = (CHAR_MIN - 3)
    };
    if(argc > 1) {
        if(strcmp(argv[1], "--help") == 0) {
            usage(EXIT_SUCCESS);
        }
        else if(strcmp(argv[1], "--version") == 0) {
            version(EXIT_SUCCESS);
        }
    }
    while(1) {
        // line=0; // Reset line number to 0 while user pass multi input IO files to this program
        static struct option long_options[] = {
            {"learn", no_argument, NULL, 'l'},
            {"show-all", no_argument, NULL, 'A'},
            {NULL, no_argument, NULL, 'e'},
            {"show-ends", no_argument, NULL, 'E'},
            {"number", no_argument, NULL, 'n'},
            {"number-nonblank", no_argument, NULL, 'b'},
            {"squeeze-blank", no_argument, NULL, 's'},
            {NULL, no_argument, NULL, 't'},
            {"show-tabs", no_argument, NULL, 'T'},
            {NULL, no_argument, NULL, 'u'},
            {"show-nonprinting", no_argument, NULL, 'v'},
            {"help", no_argument, NULL, GETOPT_HELP_CHAR},
            {"version", no_argument, NULL, GETOPT_VERSION_CHAR},
            {NULL, 0, NULL, 0},
        };
        int option_index = 0;
        c = getopt_long(argc, argv, "benstuvAET", long_options, &option_index);
        if(c == -1)
            break;
        switch(c) {
        case 0:
            // If this option set a flag, do nothing else now.
            if(long_options[option_index].flag != 0)
                break;
            printf("option %s", long_options[option_index].name);
            if(optarg)
                printf(" with arg %s", optarg);
            printf("\n");
            break;

        // lAbeEnstTuv help + version
        case 'l':
            if(DEBUG)
                puts("option -l\n");
            lflag=1;
            break;

        case 'A':
            if(DEBUG)
                puts("option -A\n");
            vflag=1;
            Eflag=1;
            Tflag=1;
            break;

        case 'b':
            if(DEBUG)
                puts("option -b\n");
            lflag=1;
            nflag=1;
            break;

        case 'e':
            if(DEBUG)
                puts("option -e\n");
            vflag=1;
            Eflag=1;
            break;

        case 'E':
            if(DEBUG)
                puts("option -E\n");
            Eflag=1;
            break;

        case 'n':
            if(DEBUG)
                puts("option -n\n");
            nflag=1;
            break;

        case 's':
            if(DEBUG)
                puts("option -s\n");
            sflag=1;
            break;

        case 't':
            if(DEBUG)
                puts("option -t\n");
            vflag=1;
            Tflag=1;
            break;

        case 'T':
            if(DEBUG)
                puts("option -T\n");
            Tflag=1;
            break;

        case 'u':
            if(DEBUG)
                puts("option -u\n");
            uflag=1;
            break;

        case 'v':
            if(DEBUG)
                puts("option -v\n");
            vflag=1;
            break;

        case '-':
            // printf("reading SDIN\n");
            reading(NULL);
            break;

        case GETOPT_HELP_CHAR:
            usage(EXIT_SUCCESS);
            break;

        case GETOPT_VERSION_CHAR:
            version(EXIT_SUCCESS);
            break;

        case '?':
            // getopt_long already printed an error message.
            break;

        default:
            usage(EXIT_FAILURE);
        }
    }
    if(verbose_flag)
        puts("verbose flag is set");
    if(optind < argc) {
        // printf("non-option ARGV-elements: ");
        while(optind < argc) {
            // printf("%s ", argv[optind++]);
            if(strcmp(argv[optind], "-") == 0)
                reading(NULL);
            else
                reading(argv[optind]);
            optind++;
            // putchar('\n');
            printf("\r\n");
        }
    }
    else
        reading(NULL);

    return 0;
}

