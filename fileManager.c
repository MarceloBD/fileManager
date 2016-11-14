/**
*   Library to manager files as reading or writing in it
*
* @Version 1.0
*
**/

#include <stdio.h>
#include <string.h>
#include "fileManager.h"

void main(){

FILE *fp;
char a[2] = "7";

fp = openFile(a);

char *s = "#texto|alternativo";

//writeF(s, 18 ,fp, 28);

char *data = NULL;
readF(&data, fp);

char **vet = NULL;
int i;

regCount(3, &data);
getFields(&vet ,data);

printf("\nvet0 %s", vet[0]);
printf("\nvet1 %s", vet[1]);
//printf("\nvet2 %s", vet[2]);
//printf("\n%s", vet[3]);
closeFile(fp);

}

void regCount(int* rrn, char** data){
    int i;
   // char *start = *data;
    for (i = 0; i < rrn ; i++){
        mystrsep(data, "#");
        //*start = *data;
    }
    char *start = *data;
    mystrsep(data, "#");
    //*data = start;
    *data = start;
}

FILE *openFile(char* name){
    FILE *fp;
    if(!(fp = fopen(name, "r"))){              //verifies if the file already exists
        fp = fopen(name , "w+");
        fclose(fp);
    }
    return fopen(name, "r+");                  // returns the pointer to the file in both cases
}

int closeFile(FILE* fp){                     // closes file
    return fclose(fp);
}

void writeF(char* data, int size, FILE* file, char *type){       // write string in file
    if (type == "end"){
        fseek ( file , 0 , SEEK_END );                          // if type is end, seeks at end of file
    }
    else{
        fseek( file, type, SEEK_SET);                           // else seeks in "type" byte offset
    }
    fwrite(data, sizeof(char), size, file);                     // writes on file
}


void readF(char** data,FILE *file){
    char buffer[BUFFER_SIZE] = {NULL};                          // buffer to read
    fseek ( file , 0 , SEEK_SET);                               // seeks at beginning of file
    fread(buffer, sizeof(char), sizeof(buffer), file);          // reads from file
    *data = (char*)malloc(sizeof(char)*sizeof(buffer));         // allocates memory for data array
    strcpy(*data, buffer);                                      // copies buffer to data
}

void getFields(char*** vet, char *data){
    int i = 0, j;                                               // declares variables for function
    char *tok = data, *end = data, *start = data;                              // pointers to data array
    while (tok != NULL && *tok != '\0') {

        printf("%d", i);
  //      if(start != NULL){
            mystrsep(&end, "|");
        //stok = start;
        //printf("%s", start);
      //  mystrsep(&start, "#");// makes end points to char after delimiter
        *vet = (char**) realloc(*vet, sizeof(char*)*(i+1));     // relocate the array of strings
 //       for (j = i; j < i+1 ; ++j)
            (*vet)[i] = (char*) malloc (sizeof (char)*14);
        (*vet)[i] = tok;                                        // array receives the string pointed by tok until /0
        tok = end;                                              // makes tok equals to end
            i++;
        //}
       // else
         //   break;
    }
}

char* mystrsep(char** strp, const char* delim){
    char* start = *strp;                                // makes start point to string
    char* p;                                            // creates a p pointer
    if(start != NULL)                                   // if strings is not null
        p = strpbrk(start, delim);                      // p points to delimiter
    else
        p = NULL;                                       // else p points to null
    if (p == NULL){
        *strp = NULL;                                // if there is no delimiter string points to null
    }
    else{
        *p = '\0';                                      // else set p value to /0
        *strp = p + 1;                               // makes string points to next address after delimiter
    }
    return start;                                     // returns start
}
