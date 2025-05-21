#include <stdio.h>

int sensor(int d)
{
  if (d == 6)
  {
    return 1;
  }
  else if (d == 7) 
  {
    return 2;
  }
  else if (d == 8)
  {
    return 3;
  }

  // Várias voltas
  if ((d - 3) % 8 == 3)
  {
    return 1;
  }
  else if ((d - 3) % 8 == 4)
  {
    return 2;
  }
  else if ((d - 3) % 8 == 5)
  {
    return 3;
  }
}


void main(void)
{
  int d_total;
  scanf("%i", &d_total);
  printf("%i\n", sensor(d_total));
}
