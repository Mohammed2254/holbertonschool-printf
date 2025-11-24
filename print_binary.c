#include "main.h"
int print_binary(unsigned int n)
{
int count = 0;
int bit;
unsigned int mask = 1 << 31;
while (!(n & mask) && mask > 1)
mask >>= 1;
while (mask > 0)
{
bit = (n & mask) ? 1 : 0;
_putchar(bit + '0');
count++;
mask >>= 1;
}
return (count);
}
