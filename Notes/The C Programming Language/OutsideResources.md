## Pointers
The following line:

char * name = "John";

does three things:

    - It allocates a local (stack) variable called name, which is a pointer to a single character.
    - It causes the string "John" to appear somewhere in the program memory (after it is compiled and executed, of course).
    - It initializes the name argument to point to where the J character resides at (which is followed by the rest of the string in the memory).


## Structures

C structures are special, large variables which contain several named variables inside. Structures are the basic foundation for objects and classes in C. Structures are used for:

- Serialization of data
- Passing multiple arguments in and out of functions through a single argument
- Data structures such as linked lists, binary trees, and more


## Pointers for 2 Dimensional Arrays
- Unlike one-dimensional arrays, where we used a pointer, in this case we require a pointer to a pointer, as shown below.

int nrows = 2;
int ncols = 5;
int i, j;

// Allocate memory for nrows pointers
char **pvowels = (char **) malloc(nrows * sizeof(char *));

// For each row, allocate memory for ncols elements
pvowels[0] = (char *) malloc(ncols * sizeof(char));
pvowels[1] = (char *) malloc(ncols * sizeof(char));

pvowels[0][0] = 'A';
pvowels[0][1] = 'E';
pvowels[0][2] = 'I';
pvowels[0][3] = 'O';
pvowels[0][4] = 'U';

pvowels[1][0] = 'a';
pvowels[1][1] = 'e';
pvowels[1][2] = 'i';
pvowels[1][3] = 'o';
pvowels[1][4] = 'u';

for (i = 0; i < nrows; i++) {
    for(j = 0; j < ncols; j++) {
        printf("%c ", pvowels[i][j]);
    }

    printf("\n");
}

// Free individual rows
free(pvowels[0]);
free(pvowels[1]);

// Free the top-level pointer
free(pvowels);
