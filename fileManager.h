#ifndef FMANAGER
#define FMANAGER

#define BUFFER_SIZE 100

/**
*   Opens a file and verify if it already exists
*   Arguments: name - name of the file
*   Return: pointer to file
**/
FILE *openFile(char* name);

/**
*   Closes a file
*   Arguments: fp - pointer to the file
*   Return:     int
**/
int closeFile(FILE* fp);

/**
*   Writes on file
*   Arguments:  data - data to be written
*               size -  size of the data
*               file - pointer to the file
*               type - position that data will be written
*   Return:     void
**/
void writeF(char* data,int size, FILE* file, char *type);

/**
*   Reads data from file
*   Arguments:  data - pointer to data vector
*               fp - file pointer
*   Return:     void
**/
void readF(char** data, FILE *fp);

/**
*   Separates the data vector with the delimiters
*   Arguments:  vet - matrix of data
*               data - original data vector
*   Return: void
**/
void getFields(char ***vet,char *data);

/**
*   Finds the delimiter in string
*   Arguments:  stringp - string passed
*               delim - delimiter of the data
*   Return: pointer to array
**/
char* mystrsep(char** stringp, const char* delim);

#endif // FMANAGER
