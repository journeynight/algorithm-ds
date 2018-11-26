#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#define BITS_PER_WORD 8
static int INT_MAX = ((unsigned)1 << 31) - 1;
static int INT_MIN = -((unsigned)1 << 31);
char *calc_bits(int x)
{
    assert(x >= INT_MIN && x <= INT_MAX);
    char *bits = (char *)malloc(BITS_PER_WORD * sizeof(int));
    memset(bits,'0',BITS_PER_WORD * sizeof(int));
    unsigned val =  (unsigned)x;
    int index = BITS_PER_WORD * sizeof(int) - 1;
    while(val)
    {
        bits[index --] = (val % 2 == 1) ? '1' : '0';
        val /= 2;
    }
    return bits;
}
int main()
{
    int x;
    scanf("%d",&x);
    char *bits = calc_bits(x);
    printf("%s\n",bits);
    free(bits);
    return 0;
}
