#include <stdio.h>
#include <string.h>


// dic : 단어 저장
char dic[26000][20];

int trans(int a, int b) {
  const int eod = strlen(dic[a]);

  int count=0;
  for(int i = 0; i < eod; ++i) {
    if(dic[a][i] != dic[b][i]) {
      ++count;
    }
  }

  return count;
}  

int main() {
  // num : 문자 갯수
  int num;
  
  FILE *fp = fopen("./input.txt", "r");
  for(int i = 1; ; ++i) {
    fscanf(fp, " %s ", dic[i]);
    num = i;
    if(feof(fp)) break;
  }
  fclose(fp);

  int max = 0;
  for(int i = 1; i < num; ++i) {
    int x = i;
    int y = i + 1;
    int len = 0;

    while(y <= num) {
      int ct = trans(x, y);

      if(ct == 1) {
        x = y;
        y = y + 1;
        ++len;
      } else if(ct > 1) {
        y = y + 1;
      }
    }

    if(max <= len) {
      max = len;
    }
  }

  printf("%d", max);
}
