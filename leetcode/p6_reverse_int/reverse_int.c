#include <stdio.h>
#include <stdint.h>
int reverse(int x)
{
    uint16_t sign = x < 0 ? 1 : 0;
    uint64_t y = x < 0 ? -x :x;
    uint16_t bits[20] = {0};
    int i = 0,j;
    while(y){
        bits[i] = y % 10;
        y /= 10;
        ++i;
    }
    y = 0;
    for(j = 0; j < i;++j)
        y = 10 * y + bits[j];
    if((sign && y > 2147483648) || (!sign && y > 2147483647))
        y = 0;
    int res =(int)y;
    if (sign)
        res = -res;
    return res;
}
int main()
{
    int x;
    while(1)
    {
        scanf("%d",&x);
        reverse(x);
    }
    return 0;
}
