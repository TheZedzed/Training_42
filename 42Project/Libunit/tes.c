#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

/*
** signal.h macos
** SIGRTMIN
** SIGRTMAX
**
** wait.h macros
** WNOHANG
** WUNTRACED
** WSTOPPED
** WEXITED
** WCONTINUED
** WNOWAIT
** __WNOTHREAD
** __WALL
** __WCLONE
*/

wait();
exit();
fork();
malloc();
free();
write();
