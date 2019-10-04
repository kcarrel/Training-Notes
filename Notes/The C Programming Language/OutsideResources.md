## Pointers
The following line:

char * name = "John";

does three things:

    - It allocates a local (stack) variable called name, which is a pointer to a single character.
    - It causes the string "John" to appear somewhere in the program memory (after it is compiled and executed, of course).
    - It initializes the name argument to point to where the J character resides at (which is followed by the rest of the string in the memory).
