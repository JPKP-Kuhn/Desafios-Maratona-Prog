#include <stdio.h>

char partidas[6];

int main(void)
{
  int vitorias = 0;
  for (int i = 0; i < 6; i++)
  {
    scanf(" %c", &partidas[i]);

    if (partidas[i] == 'V')
    {
      vitorias++;
    }
  }
  if (vitorias >= 5)
  {
    printf("1\n");
  } else if (vitorias >= 3)
  {
    printf("2\n");
  } else if (vitorias >= 1)
  {
    printf("3\n");  
  } else {
    printf("-1\n");
  }
}
