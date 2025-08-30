# Pipe Time Test

This project demonstrates inter-process communication and timing using pipes in C++ on a Linux environment.

## Files

- `pipe_time_test.cpp`: The main C++ source file that creates two processes and measures the time taken for data to travel through pipes.
- `Dockerfile`: Build and run the project in a Linux container using Docker.
- `screenshots/run_1.PNG`, `screenshots/run_2.PNG`, `screenshots/run_3.PNG`: Example outputs showing the time taken by the process.

## How to Run

### Using Docker

1. Build the Docker image:
   ```sh
   docker build -t pipe-time-test .
   ```
2. Run the container:
   ```sh
   docker run --rm pipe-time-test
   ```

### On Linux (without Docker)

1. Compile the code:
   ```sh
   g++ -o pipe_time_test pipe_time_test.cpp
   ```
2. Run the program:
   ```sh
   ./pipe_time_test
   ```

## Time taken

Below are screenshots showing the time taken by the process:

| Run 1                           | Run 2                           | Run 3                           |
| ------------------------------- | ------------------------------- | ------------------------------- |
| ![Run 1](screenshots/run_1.PNG) | ![Run 2](screenshots/run_2.PNG) | ![Run 3](screenshots/run_3.PNG) |

### Average time taken:

77,000 milli-seconds = 1 minute 17 seconds
