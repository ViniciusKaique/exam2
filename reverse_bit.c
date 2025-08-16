#include <stdio.h>

unsigned char reverse_bit(unsigned char n)
{
    unsigned char rev = 0;
    int i = 8;
    while(i >= 0)
    {
        rev = rev*2 + (n%2);
        n = n / 2;
        i--;
    }
    return (rev);
}

int main (void)
{
    unsigned char n = 42, x = 0;
    int i = 7;

    printf("initial decimal: %u bit: ", n);
    while(i != 0)
    {
        printf("%d", n >> i & 1);
        i--;
    }
    printf("\n");
    x = reverse_bit(n);
    i = 7;
    printf("decimal reverse bit: %u bit: ", x);
    while(i != 0)
    {
        printf("%u", x >> i & 1);
        i--;
    }
        printf("\n");

}
