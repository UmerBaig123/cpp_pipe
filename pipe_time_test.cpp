#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <cstring>

int main() {
    int pipe1[2], pipe2[2];
    const int N = 1000000;
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // Child process
        close(pipe1[1]); // Close write end of pipe1
        close(pipe2[0]); // Close read end of pipe2
        int num;
        for (int i = 0; i < N; ++i) {
            if (read(pipe1[0], &num, sizeof(num)) != sizeof(num)) {
                perror("child read");
                break;
            }
            // Send back the same integer
            if (write(pipe2[1], &num, sizeof(num)) != sizeof(num)) {
                perror("child write");
                break;
            }
        }
        close(pipe1[0]);
        close(pipe2[1]);
        return 0;
    } else {
        // Parent process
        close(pipe1[0]); // Close read end of pipe1
        close(pipe2[1]); // Close write end of pipe2
        int num = 42, ret;
        struct timeval start, end;
        gettimeofday(&start, nullptr);
        for (int i = 0; i < N; ++i) {
            if (write(pipe1[1], &num, sizeof(num)) != sizeof(num)) {
                perror("parent write");
                break;
            }
            if (read(pipe2[0], &ret, sizeof(ret)) != sizeof(ret)) {
                perror("parent read");
                break;
            }
        }
        gettimeofday(&end, nullptr);
        close(pipe1[1]);
        close(pipe2[0]);
        wait(nullptr);
        double elapsed = (end.tv_sec - start.tv_sec) * 1e3 +
                         (end.tv_usec - start.tv_usec) / 1e3;
        std::cout << "Round-trip of " << N << " integers took " << elapsed << " ms\n";
        return 0;
    }
}