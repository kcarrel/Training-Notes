 # The Big Picture

 ## Levels and Layers of Abstraction in a Linux System

In abstract terms...
 Top layer - Games and web browsers
 Middle layer - Operating system
 Bottom layer - Memory in the computer hardware the 0s and 1s

 3 main levels of a linux systems
 - Hardware: includes memory and central proccessing units (CPUs)
 - Kernel: Core of operating system (OS) --> tells CPUs what to do. Primarily interface between hardware and a process.
 - Processes: the running programs that the kernel manages.

 User Processes: Graphical User Interface (GUI), servers and shells
 Linux Kernels: System calls, process management, memory management and device drivers
 Hardware: Processor(CPU), Main Memory (RAM), disks and network ports.

 Kernel processes run in a Kernel mode which allows unrestricted access to processor and main memory. The Kernel space is area that only the Kernel can access.

 User mode restricts access to small amounts of memory and safe CPU operations. In theory this prevents a user process causing large scale issues to the system. 

 ## Hardware: Understanding Main Memory
 Main memory is the most improtant hardware on a computer system. It is the storage for a bunch of 'bits' in the form of 0s and 1s.
 Running Kernel and processes live in main memory. The CPU operates on memory by reading instructions and data from memory then writing data back out to memory.

 State - a particular arrangement of bits

 ## The Kernel
 In charge of 4 general system areas:
 - Processes: determine which processes are allowed to use the CPU
 - Memory: Keeps track of all memory - where it is, connections and whats free.
 - Device Drivers: interface between hardware and processes. operates the hardware. 
 - System calls and support: Processes user system calls to communicate with Kernel

 ### Process Management
 The starting, pausing, resuming and termination of processes.
 One-CPU systems 
 Context switch: The act of one process giving up control of the CPU to another process.

 The human perception is that the system is running multiple processes at the same time because the time it takes the system to context switch (a time slice) is so small.

 The Kernel runs during the time between process time slices during a context switch.

 Under a multi-CPU system a Kernel doesn't need to relinquish CPU of its current CPU to allow a process to run but it usually does.

 ### Memory Management
 Kernel Conditions:
 - Must have own private area in memory unaccessible by user
 - user process needs its own section of memory
 - One user cannot access private memory of another process
 - User processes can share memory
 - Some memory in user processes can be read-only
 - System can use more memory than physically present by dipping into aux disk space

 A helper for Kernel --> MMU!

 Memory Management Unit (MMU) enables a memory access scheme called virutal memory. 

When using VM a process doesn't access memory by physical location in hardware.

 Page table - implementation of a memory address map

 ### Device Drivers and Management

 Device drivers are part of the Kernel and presenta  uniform interface to user processes to simplify a developer's job.

 A device is only accessible in Kernel mode.

 ### System Calls and Support

 System calls: perform specific tasks that a user process alone cannot do or cannot do well.
 ex: opening, reading or writing falls

2 important system calls
- fork() : Kernel creates a nearly identical copy of process
- exec() : Kernel starts program and replaces the current process

All user process in a linux system (exception: init) start via fork() or exec() for running a new program

System calls are denoted with ()s

Pseudodevices: look like devices to user processes but implemented in software. Don't need to be in kernal but is typically there for practicality. 
ex: the kernal random number generator device (/dev/random)

 ## User Space
 2 facets of user space/userland
 - main memory allocated by Kernel for user processes
 - can also mean memory for the entire collection of running processes

 Most action in Linux system happens in user space.
 ## Users
 User: an entity that can run processes and own files. Associated with a username but identified by kernel via userids (number).

Users support permisions and boundaries. Every userspace has a user owner. Can act on own user's processes but not other user's processes.

Root User/Superuser: Exception to the rule. Person who has root access and is an administrator on a traditional Unix system. Still confined to using user space/work in user mode.

