#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ioctl.h>
#include<math.h>

struct winsize getTerminalModel(){
  printf("Getting terminal model ...\n");
  struct winsize w;
  struct winsize e; e.ws_col = -1; e.ws_row = -1;
  if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1){
    perror("ioctl");
    return e;
  }
  return w;
}

char** allocate_ball_memory( int rows, int cols){
  printf("Allocating Memory ... \n");
  char** balls;
  
  balls = (char**)calloc(rows, sizeof(char*));
  
  
  for(int i = 0;i<rows;i++){
    balls[i] = (char*)calloc(cols, sizeof(char));
  }
  
  for(int i = 0;i<rows;i++){
    for(int j = 0;j<cols;j++){
      if(i == 0)
	balls[i][j] = '-';
      else if(j == cols -1 || j == 0)
	balls[i][j] = '|';
      else
	balls[i][j] = ' ';
    }
  }
  return balls;
}

int func_cal(int x){
  //  printf("Calculating function ...\n");
  return log10(x)*10;
}

int func(char** balls, int rows, int cols){
  //  printf("Filling ball array ... \n");
  for(int i = 0;i<cols;i++){
    int h = func_cal(i);
    if(h>=0 &&  h<rows){
      
    balls[h][i] = 'x';
    }
    
  }
  return 1;
}

void print_func(char** balls, int rows, int cols){
  printf("printing the ball array ... \n");
  for(int i = rows -1;i>=0;i--){
    for(int j = 0;j<cols;j++){
      printf("%c", balls[i][j]);
    }
    printf("\n");
  }
}

int graph(){
  printf("The graph function is executing ... \n");
  struct winsize w = getTerminalModel();
  int rows = w.ws_row-5;
  int cols = w.ws_col/2;
  if(rows == -1 || cols == -1) return 0;
  char** ball = allocate_ball_memory(rows, cols);
  if(ball == NULL) {
    printf("ERROR:: allocate_ball_memory\n");
    return 2;
  }
  int status = func(ball, rows, cols);
  if(status == 0){
    printf("ERROR:: func\n");
    printf("Early exit\n");
  } 
  print_func(ball, rows, cols);
  return 1;
}

int main(){
  printf("Executing Main ... \n");
  int status = graph();
  if(status == 0) printf("YOU FUCKED UP\n"); 
  return 0;
}
