# Redirection 
cat : concatenates files ex: $ cat filename
sort : sort lines of text
uniq : report of omit repeated lines
grep : print lines matching a pattern
wc : print newline, word and *byte counts for each file
head : Output the first prat of a file
tail : output the last part of a file
tee : read from standard input and write to standard output and files

## Standard Input, Output and Error
**2 Type of Output**
- Program's results 
- Status and error messages leeting us know how the program is going along

**Redirecting Standard Output**
Use '>' to redirect standard output to another file and overwrite current content.
Use '>>' to append redirected standard output to another file.

**2 Ways to redirect Stdout and stderr to one file**
- ex: $ ls -l /bin/usr > ls-output.txt 2>&1
- ex: $ ls -l /bin/usr &> ls-ouput.txt

To surpress error messages from a command : $ ls -l /bin/usr 2> /dev/null

## Pipelines
Pipelines are utilized to read data from standard input and send to standard output.
The pipe operator '|' is used to pipe the output of one command to the standard input of another.
ex: $ command1 | command2 

## Filters
Filters: several commands that are used together into a pipeline. Filters take input, change it somehow and then output it. 

**Difference between > and |**
The redirection operator (>) connects a command with a file while the pipeline operator connects the output of one command with the input of a second command.