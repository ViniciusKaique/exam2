#include <unistd.h>
void	print_bits(unsigned char octet)
{
    int i = 7;
    char c;
    while(i >= 0)
    {
    c = (octet >> i & 1) + '0';
    write(1,&c , 1);
    i--;
    }
}
int main (void)
{
    unsigned char n = 42;
    print_bits(n);
}