# Navigation
pwd - print name of current working directory
cd - change directory
ls - list directory contents

## Understanding the File System Tree
Linux has a hierarchial directory structure.                                
Hierarchial Directory Structure - organized in a tree-like pattern containing files and directories.
root directory - first directory in the file system that contains subdirectories and files that branch outwards.

## The Current Working Directory
When navigating in the command line it is best thought of as a "maze shaped like an upside-down tree and we are able to stand in the middle of it".

## Changing the Current Working Directory
**Absolute Pathnames:** Begins with the root directory and follows the tree branch by branch until the path to the desired directory or file is completed. ex: $ cd /usr/bin
**Relative Pathnames:** A relative pathway starts from the working directory ex: $ cd ..

### Important Facts about Filenames
- Filenames that begin with a period character are hidden unless ls -a is used.
- Filenames and commands are case sensitive
- Do not emebed spaces in file names
- Linux has no concept of 'file extensions'.

### Some Helpful Shortcuts
cd : changes the working directory to your home directory
cd - : changes the working directory to the previous working directory
cd ~username : changes the working directory to home directory of username