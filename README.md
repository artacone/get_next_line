# get_next_line
My implementation of the function which stores a line read from a file descriptor.
int get_next_line(int fd, char **line)
It takes two parameters:
1) file descriptor to read from
2) address of a string where to store the line read from fd
   It returns
   1 if it has successfully read a line
   0 if EOF has been reached
   -1 if an error of any kind happened

Bonus version supports management of multiple file descriptors.