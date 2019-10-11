## Task 1: Converter

**Problem 1: buffer overflow problem of scanf**
Buffer overflow: While writing data to a buffer (areas of memory set aside to hold data), overruns the buffer;s boundary and overwrites adjacent memory locations. 
Resource: https://stackoverflow.com/questions/1621394/how-to-prevent-scanf-causing-a-buffer-overflow-in-c

Suggested solution: Solve using snprintf() to create the string with the correct buffer size for passing to the scanf() family of functions. 

Essentially: 
```
int scanner(const char *data, char *buffer, size_t buflen)
{
    char format[32];
    if (buflen == 0)
        return 0;
    snprintf(format, sizeof(format), "%%%ds", (int)(buflen-1));
    return sscanf(data, format, buffer);
}
```
*Note:* This still limits the input to the size provided as "buffer" - if you need more space then you have to do memory allocation or use a lib function that does that for you. 

Solution: https://www.mkyong.com/c/how-to-handle-unknow-size-user-input-in-c/

- Use malloc to reallocate dynamically.

Malloc returns a void pointer that gives us the address of the first byte in this block. 

realloc() to increase memory size dynamically