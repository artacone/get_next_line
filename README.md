# get_next_line
It is a simple project at School21. [Subject](gnl.pdf) has all the details of the task

Briefly, it's an implementation of the function which stores a line read from a file descriptor.
```c
int get_next_line(int fd, char **line)
```
It takes two parameters:
1) file descriptor to read from
2) address of a string where to store the line read from fd
   It returns
   
   1 if it has successfully read a line
   
   0 if EOF has been reached
   
   -1 if an error of any kind happened

Bonus version supports management of multiple file descriptors.

Further on it is added to libft.
