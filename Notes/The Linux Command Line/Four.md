# Manipulating Files and Directories  
cp : copy files and directories
mv : move/rename files and directories
mkdir : create directories
rm : remove files and directories
ln : create hard and symbolic links

## Wildcards
wildcard characters - allows you to select filenames based on patterns of characters.

**Wildcard Characters**
'*' : matches any characters
? : matches any single character
[characters] : matches any character that is a member of the set characters
[!characters] : matches any character that is not a memeber of the set characters
[[:class]] : matches any character that is a member of a specific class

**Commonly Used Character Classes**
[:alnum:] : matches any alphanumeric character
[:alpha:] : matches any alphabetic character
[:digit:] : matches any numeral
[:lower:] : matches any lowercase letter
[:upper:] : matches any uppercase letter

Wildcards also work on the command line and are also supported by some graphical file managers.


**mkdir - Create Directories**
**cp - Copy Files and Directories**
**cp Options**
-a/--archive : copy the files and directories and all their attributes including ownerships and permissions.
-i/--interactive : Will prompt a user for confirmation if an overwrite of an existing file is being attempted
-r/--recursive : recursively copy directories and their contents. Required when copying directories/
-u/--update : When copying files from one directory to another, only copy files that either don't exist or are newest.
-v/--verbose : Display informative messages as the copy is performed.

**mv - Move and Rename Files**
Has a few of the same options as cp such as -i/-u/-v

**rm - Remove Files and Directories**
Has a few of the same options as cp such as -i/-r/-v
-f/--force : Ignore nonexistent files and do not prompt. Overrides the interactive option.

**ln - Create Links**
## Hard Links
**2 Important Limitations**
- Cannot reference a file outside of its own file system
- Cannot reference a directory
When a hard link is deleted the link is removed but the contents of file continues to exist until all links to the file are deleted.
**Symbolic Links**
When you delete a symbolic link only the link is deleted and not the file itself.