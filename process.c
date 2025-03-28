#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
  pid_t pid;
  
  // Create a new process
  pid = fork();
  
  if (pid < 0) {
    // Fork failed
    printf("Fork Failed!\n");
    return 1;
  } else if (pid == 0) {
      // Child process
      printf("This is the child process. PID: %d, Parent PID: %d\n",getpid(),getppid());
    } else {
      // Parent Process
      printf("This is the parent process. PID: %d, Child PID: %d\n",getpid(),pid)
      }

    return 0;
}