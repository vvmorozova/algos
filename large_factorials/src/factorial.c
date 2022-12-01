#include "factorial.h"

char  *summ_two_str(char *str1, char *str2) 
{
  int   in_mind = 0;
  int   digit1, digit2;
  int   sum;
  char  *rez;

  rez = malloc(sizeof(char) * MAX);
  memset(rez, '0', MAX);
  rez[MAX - 1] = 0;
  for (int i = MAX - 2; i >= 0; i--) {
    printf("%c %c\n", str1[i], str2[i]);
    digit1 = str1[i] - '0';
    digit2 = str2[i] - '0';
    sum = digit1 + digit2 + in_mind;
    rez[i] = '0' + sum % 10;
    in_mind = sum / 10;
  }
  return (rez);
}

char *mult(char *num1, char *num2)
{
  char  *str, buff[MAX], *rez;
  int   digit1, digit2;
  int   mult, place;

  str = malloc(sizeof(char) * MAX);
  memset(str, '0', MAX);
  str[MAX - 1] = 0;
  memset(buff, '0', MAX);
  buff[MAX - 1] = 0;
  for (int i = MAX - 2; i >= 0; i--) {
    digit1 = num1[i] - '0';
    for (int j = MAX - 2; j >= 0 ; j--) {
      digit2 = num2[j] - '0';
      mult = digit1 * digit2;
      place = -(MAX - 2 - i - j);
      (void)place;
      buff[place] = '0' + mult % 10;
      buff[place - 1] = '0' + mult / 10;
      rez = summ_two_str(str, buff);
      free(str);
      str = rez;
      memset(buff, '0', MAX - 1);
    }
  }
  return (str);
}

void  recc_mult(int n, char **rez)
{
  char str[MAX], *buff;
  int   len;
  if (n  <= 1) {
    (*rez)[MAX - 2] = '1';
    return ;
  }
  recc_mult(n - 1, rez);
  sprintf(str, "%d", n);
  len = strlen(str);
  memset(str, '0', MAX - 1);
  sprintf(str + MAX - len - 1, "%d", n);
  buff = mult(*rez, str);
  free(*rez);
  *rez = buff;
}

char *factorial(int n)
{
  char  *rez, *final;
  int   sub = 0;

  rez = malloc(sizeof(char) * MAX);
  memset(rez, '0', MAX - 1);
  recc_mult(n, &rez);
  
  while (*rez && rez[sub++] == '0');
  final = malloc(sizeof(char) * (MAX - sub));
  final = memcpy(final, rez + sub - 1, MAX - sub);
  free(rez);
  return (final);
}