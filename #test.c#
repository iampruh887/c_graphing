#include<stdio.h>
#include<sys/ioctl.h>
#include<unistd.h>

int main(){
  struct winsize w;
  if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1) {
    perror("ioctl");
    return 1;
  }
  printf("Terminal width: %d columns\n", w.ws_col);
  printf("Terminal height: %d rows\n", w.ws_row);

  for(int i = 0;i<w.ws_row;i++) {
    for(int j = 0;j<w.ws_col;j++) {
      printf("0");
    }
    printf("\n");
  }
  return 0;
}
  
