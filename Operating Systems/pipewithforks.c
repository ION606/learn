#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main() {
    int pipefd[2];
    int rc = pipe(pipefd);

    if (rc == -1) {
        perror("pipe() failed!");
        return EXIT_FAILURE;
    }

    pid_t pid = fork();

    if (pid == 0) {
        perror("fork() failed!");
        return EXIT_FAILURE;
    }

    if (pid == 0) {
        // close the read end of the pipe (there's no need to use it in this process)
        close(pipefd[0]);

        // Write the bytes to the pipe
        char* toWrite = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int bytes_written = write(pipefd[1], toWrite, 26);
        printf("Child process wrote \"%s\" (%d bytes)\n", toWrite, bytes_written);
        
        return EXIT_SUCCESS;
    }
    else {
        // close the write end of the pipe (there's no need to use it in this process)
        close(pipefd[0]);

        int stat;
        pid_t cpid = waitpid(pid, &stat, 0);

        printf("child exited with status %d\n", WEXITSTATUS(stat));

        char buffer[20];
        int bytes_read = read(pipefd[0], buffer, 10);

        // assume the data is char data
        buffer[bytes_read] = '\0';

        printf("Parent process read \"%s\" (%d bytes)\n", buffer, bytes_read);

        // close the write buffer
        close(pipefd[1]);
    }

    return EXIT_SUCCESS;
}
