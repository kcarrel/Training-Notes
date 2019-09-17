# Basic Commands and Directory Hierarchy
Linux is a Unix flavor at heart.

## The Bourne Shell: /bin/sh
Shell: a program that runs commands and serves as a snmall programing environment.
Shell scripts: text files containing sequences of shell commands.

Every unix systems needs the Bourne Shell to function correctly. 
Bash: enhanced version of Bourne Shell aka Bourne-again shell.
## Using the Shell
### The Shell Window
Often referred to as a terminal - The GUI which starts a shell inside a new window.

### cat
Prints the contents of files (ex: $ cat file1 file2).
It performs concatenation when it prints the contents > 1 file

### Standard Input and Standard Output
Unix input and output (I/O).
Unix processes use I/O streams to read (input) + write (output) data.

## Basic Commands
ls: lists contents of a directory
cp: copies files (ex: $ cp file1) or to a directory (ex: $ cp file1 .... fileN dir)
mv: renames a file (ex: $ mv file 1 file 2) or to a dir (ex: $ mv file1 .... fileN dir)
touch: creates a file
rm: removes a file
echo: prints an argument to standard output

## Navigating Directories
cd: change directory
mkdir: make a new directory
rmdir: removees a directory
### Shell Globbing (Wildcards)
Globbing: matching simple patterns to file and directory names
glob character: 
/*/ <-- tells shell to match any number of arbitrary chars.
? <-- tells shell to match exactly 1 arbitrary char (ex: $ b? matches boat & brat)
Enclose glob chars in single quotes if you dont want it to expand in a command (ex: $ echo '* )

## Intermediate Commands
grep: prints the lines from a file or input stream matching an expression (Ex: $ grep root /etc/passwd)

grep -i: case-insensitive matches
grep -v: inverts search - all lines that do not match 

2 important points for RegEx:
- .* matches any number of characters
- . matches one arbirrary character 

less: See contents of file one screenful at a time (ex: $ less /usr/share/dict/words)

pwd: outputs the name of the current working directory
2 reasons for pwd:
- not all prompts include current working directory/ some users get rid of it in prompt
- symbolic links obscure the true full path of current working directory (pwd -P eliminates this confusion)

diff: see differences between 2 text files (ex: $ diff file1 file 2)
file: See a file's format (ex: $ file filename)
find and locate: Find a file in the directory ( ex: $ find dir -name file -print)
head and tail: View a portion of a file or stream of data (ex: $ head -5 /etc/passwd prints n(5) lines)
sort: Puts lines of a text file in alphanumeric number (-r to reverse or -n to sort in numerical order)

## Changing Your Password and Shell
'$ passwd' command begins process to change your password.

## Dot Files
Dot files: Configuration files that begin with a dot (.). Not special just hidden from view when using ls (seen when ls -a).

## Environment and Shell Variables
Shell Variables: Temporary variables containing the values of text strings. (EX: $ STUFF=blach)
## The Command Path
PATH is a special environment varaible that contains the command path.
Command path: list of system directories that the shell searches when trying to locate a command.
## Special Characters

## Command-Line Editing
Ctrl-B: Move cursor left
Ctrl-F: Move cursor right
Ctrl-P: View previous command (or cursor up)
Ctrl-N: View next command (or move cursor down)
Ctrl-A: Move the cursor to the beginning of the line
Ctrl-E: Move the cursor to the end of the line
Ctrl-W: Erase the preceding word
Ctrl-U: Erase the cursor to the beginning of the line
Ctrl-K: Erase from cursor to end of line
Ctrl-Y: Paste erased text


## Getting Online Help
Linux systems has vast documentation.
To get documentation '$ man $command'
To search for a manual page by keyword: '$ man -k keyword'
Access an info mannual: '$ info $commannd

## Shell Input and Output
To send output of a command to a file instead of terminal: $ command > file
To append output to file isntead of overwritting: $ command >> file
To send std. out of a command to std. in of another command: $ command 1 | command 2

### Standard Error
Standard Error (stderr): additional output stream for diagnostics and debugging

### Standard Input Redirection
To channel a file to a program's standard input use < operator : $ head < /proc/cpuinfo>

## Understanding Error Messages
### Anatomy of a UNIX Error Message
3 componenets:
- Program name
- filename
- error

### Common Errors
No such file or directory: You tried to access a file that doesn't exist.
File exists: You tried to create a file that already exists.
Not a directory, ls a directory: When you try to use a file as a directory and vice versa
No space left on device: you're outta disk space
Permission denied: You dont have access to read/write to a file or directory
Operation not permitted: When you try to kill a process that you don't own
Sementation fault: Tried to access a part of memory that it was not allowed to touch and the OS killed it.
Bus error: Program tried to access some memory in a particular way taht it shouldn't.

## Listing and Manipulating PRocesses
PID: The process ID
TTY: Terminal device where the process is running
STAT: Process status (what process is doing and where it resides in memory)
TIME: Amount of CPU time in min/secs that the process has used so far
COMMAND: commmand name (can change if acted upon)
### Command Options
ps x: Show all of your running processes
ps ax: Show all processes on the systems (not just yours)
ps u: Include more detailed info on processes
ps w: Show full command names

### Killing Processes
Send a signal with the kill command to terminate a process.
Default type of signal is TERM (terminate).
Freeze a process: $ kill -STOP pid
Continue a stopped process: $ kill -CONT pid

Most brutal way to terminate a process (should be a last resort): $ kill -KILL pid
The OS terminates the process then forcibly removes it from memory --> only use as a last resort!

### Job Control
TSTP- temporary stop signal
### Background Processes
When normally running a command from the shell you do not get the shell prompt (cannot do anything else) until the program is done executing (ex: sleep 10). 

You can run multiple commands from shell by detaching the process from the shell and putting it in the background by adding an ampersand. (ex: sleep 10 &) The shell prints the PID of the new background process and returns the prompt. (Note: Great for running long processes like large amounts of number crunching).
**However...**
-Running background processes that may expect to work with the stdin or read from terminal which can cause freezing or termination.
-If program writes stdout or stderr the output can appear in terminal regardless of what you are doing there (surprise output!)

**Best practice**
Redirect the output(and potentially the input) of a background process (ex: $ head < /proc/cpuinfo>)

If an errant surprise output does occur:
- Ctrl-L: redraw the entire screen

Be careful using Ctrl-R: Usually redraws the current line but when pressed at the wrong sequence it can put you in reverse isearch mode.

## File Modes and Permissions
Permissions: Determines whether a user can read/write/run a file.

ls -l: displays permissions

**File mode:** represents file's permissions in 4 parts
**1st character:** File Type
- : denotes a regular file(nothing special)
b : denotes a block
c : denotes a character
p : denotes a pip
s : denotes a socket

Block: Computer data storage device that supports reading and optionally writing data in fixed-size blocks (generally 512 bytes)

Character:

Pipe:

Socket:

**2nd character:** User 
**3rd character:** Group 
**4th character:** Other 

Each permission set can contain 4 representations:
r: means that the file is readable
w: means that the file is writeable
x: means that the file is executable
-: means nothing 
**unusual -->** s: 'setuid' meaning when you execute it runs through file owner as user instead of you. 
Parts of the permissions == 'the read bits'

### Modifying Permissions
chmod: change permission 
ex: $ chmod g+r file --> add group (g) read(r) permissions
ex: $ chmod g-r file --> remove group read permissions

**Absolute Permission Modes:** sets all permission bits at once
644: user: read/write;group, other: read
600: user: read/write; group, other: none
755: user: read/write/execute, group, other: read/execute
700: user: read/write/execute; group, other: none
711: user: read/write/execute; group, other: execute

Unmask: specify default permissions
ex: $ unmask 022 --> if you want everyone to be able to see all you create
ex: $ unmask 077 --> Nobody can see what you create

### Symbolic Links
**Symbolic Link:** A file that points to another file or a directory (effectively creates an alias). Offers quick access to obscure directory paths.
### Creating Symbolic Links
Create a symbolic link from target to linkname using ln -s
ex: $ ln -s target linkname
linkname- name of symbolic link
target- path of the file/directory that the link points to
-s: specifies a symbolic link

**Warning**: Be very careful and double check any commands creating a symbolic link otherwise risk a variety of headaches!

Benefit of symbolic links: convienet way to organize and share files or patch small problems

## Archiving and Compressing Files
**gzip:** GNU Zip is 1 of the current Unix compression programs. 
- File ending in .gz is a GNU Zip archive
- Uncompress a gzip file: $ gunzip file.fz
- Compress a gzip file: $ gzip file

**tar**
ex: $ tar cvf archive.tar file1 file 2
**c flag** - create mode
**v flag** - verbose diagnostic output (tar prints names of files/directories when encountering them)
**f flag** -  denotes the file option (must always be filed with a file name except with tape drives). To use stdin or stdout use a - instead of filename.
**x flag** - unpack a .tar file with tar (ex: $ tar xvf archive.tar). An x flag puts tar into 'extract/unpack mode'
**Note:** when using extract mode tar does not remove archived .tar file after extracting its contents. Must be manually removed.
**t flag** - 'table of contents mode' which tests an acrchive's basic integrity and prints names of files inside. 
**Note:** Make sure to test (t flag) before unpacking (x flag) so that you don't make a mess of files that is difficult to clean up.
- If you are unsure after checking create a temp directory, cd to it then extract. You can always use mv if the archive didn't make a mess. 
**p flag** - preserve permissions

### Compressed Archives (.tar.gz)
Archives are normally found compressed with filenames ending in .tar.gz.
To decompress & unpack you must work right to left:
- $ gunzip file.tar.gz
- $ tar xvf file.tar
To compress an archive do the above in reverse order.

### zcat
zcat is == gunzip -dc.
-d : decompresses
-c : sends result to standard output

Since zcat is so common - tar on Linux has a shortcut!
z option : automatically invoke gzip on the archive to extrract (with x or t modes in tar) or creating (c mode)
ex: $ tar ztvf file.tar.gz

### Other Compression Utilities
**bzip2:** a compression program whose compressed files end in .bz2
con: slower
pro: compacts text files more and popular for dist of source code
j: bzip2 compression/decompression option for tar

## Linux Directory Hierarchy Essentials
**Important Subdirectories in root**
/bin: contains ready to run programs 
/dev: contains device files
/etc: core configuration directory (specific to machine's hardware & containing user password, boot, device, networking and other setup files)
/home: Personal directories for regular users
/lib: Library fails containing code that executables can use
/proc: System statistics through browsable directory-and-file interface. 
/sys: Similar to /proc in providing a device and system interface.
/sbin: The place for system executables. (Acessible to root user not reg user)
/tmp: storage area for smaller, temp files.
/usr: large directory hierarchy
/var: variable subdirectory where programs record runtime information. System logging, user tracking, caches and other files that system programs create and maange here.

### Other Root Subdirectories
**Subdirectories of interest in root**
/boot: contains kernel boot loader files (only pertain to 1st stage of Linux startup procedure)
/media: Base attachment point for removable media such as flash drives
/opt: May contain additional 3rd party software

### The /usr Directory
/include: holds header files used by the C compiler
/info: contains GNU info holder manuals
/local: where administrators can install their own software
/man: manual pages
/share: contains files that should work on other kinds of Unix machines w/o loss of functionality.

### Kernel Location
**Normally:** in /vmlinuz or /boot/vmlinuz
A boot loader loads this file into memory and sets it in motion when the system boots.

Loadable kernel modules are located in /lib/modules.

## Running Commands as the Superuser
**Disadvantages of running su command**
- no record of system-altering commands
- no record of users who performed system-altering commands
- no access to normal shell env
- have to enter root password

### sudo
Allows administrators to run commands as root when they are logged in as themselves.
### /etc/sudoers
Area where you can configure the priveleged users that can run superuser commands. 
