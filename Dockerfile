# Use an official GCC image as the base
FROM gcc:latest

# Set the working directory
WORKDIR /usr/src/app

# Copy the C++ source file into the container
COPY pipe_time_test.cpp .

# Compile the C++ file
RUN g++ -o pipe_time_test pipe_time_test.cpp

# Set the default command to run the compiled binary
CMD ["./pipe_time_test"]
