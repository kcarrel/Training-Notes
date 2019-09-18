# Exploring the System
ls - list directory contents
file - determine file type
less - view file contents

## More Fun with ls
Specify a directory to list: ex- $ ls /usr
Specify multiple directory to list: ex- $ ls ~/usr
Specify listing in long format: ex - $ ls -l
**Options and Arguments**
Command syntax typically looks like $ command -options arguments

**Common Command ls Options**
-a/--all : List all files even hidden files beginning with a period character.
-A/--almost-all : Similar to listing all with the exceptions of current/parent directories.
-d/--directory : See details about the directory rather than the contents.
-F/--classify : Append an indicatror character to the end of each listed name.
-h/--human-readable : Display file sizes in human readbale format rather than bytes.
-l : Display results in long format.
-r/--reverse : Display results in reverse order.
-S : Sort results by file size.
-t : Sort by modification time. 

**ls Long Listing Fields**

--rw-r--r-- :Access rights to the file.
1 : File's number of hard links
root : The username of the file's owner.
root : The name of the group that owns the file.
32059 : Size of the file in bytes.
2017-04-03 11:05 : Date and time of the file's last modification
oo-cd-cover.odf : Name of the file

## Determining a File's Type with file
"Everything is a file" in Linux.
file command: prints a brief description of file's contents.

## Viewing File Contents with less
less command: program to view text files

**Why?** Because many files contain system settings (config files) that can give insight into how the system works. 

scripts: programs that systems use are in text file format.

ASCII - American Standard Code

Text is a 1 to 1 mapping of characters to numbers.

**less Commands**
PAGE UP or b : scroll back one page
PAGE DOWN or space : scroll forward one page
Up arrow : Scroll up one line
Down arrow : Scroll down one line
G : Move to the end of text file
1G or g : Move to the beginning of the text file
/characters : Search forward to the next occurrence of characters
n : Search for the next occurrence of the previous search
h : display help screen
q : quit less

## Taking a Guided Tour
**Directories Found on Linux Systems**
/ : Root directory
/bin : contains binaries (programs) necessary for system to boot and run
/boot : contains Linxu kernel, initial RAM disk image and boot loader
/dev : special directory contains device node & kernel maintains a list of all the devices it understands.
/etc : contains all system-wide config files & shell scripts that start each of the systems at boot time.
/home : In normal config each user is given a directory in /home.
/lib : contains shared library files used by the core system programs.
/lost+found : Each formatted partition or device using a Linux file system. Used in case of a partial recovery from a file system corruption event. Under normal circumstances this file is empty.
/media : Contains removable media such as USB drives, CD-ROMs etc.
/mnt : mount points for removable devices that have been mounted manually.
/opt : used to install "optional" software. Holds commerical software products that might be installed on the system. 
/proc : **special**: Not a real file system but a virtual file system maintained by the kernel. The files can be read and gives a picture of how the kernel sees your computer. 
/root : home directory for root account
/sbin : contains system binaries that perform vital system tasks reserved for superuser.
/tmp : intended for the storage of temporary, transient files.
/usr : Contains all programs and support files used by regular users.
/usr/bin : contains the executable programs isntalled by your Linux distribution.
/usr/lib : shared libraries from programs in /usr/bin.
/usr/local : Where programs that are not included with your distribution but are insteded for system-wide use are installed.
/usr/sbin : Contains more system admin programs
/usr/share : Contains all shared data used by programs (default config files, icons, screenbackgrounds etc)
/usr/share/doc : most package installed on the system will include documentation found here.
/var : where data that is likely to change is stored such as various databases, spool files, user mail etc.
/var/log : contains log files/ records of various system activity.

**Symbolic link** (aka: soft link or symlink) - a file that links to another file or directory using its path.
**Hard Links** allow files to have multipled names via a direct reference to the file.