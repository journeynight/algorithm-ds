#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
int myAtoi(char *str){
    char *p = str;
    while(*p == ' ')
            ++p;
    int sign = *p == '-' ? 1 : 0;
    if(sign || *p == '+')
        ++p;
    uint64_t total = 0;
    while(*p >= '0' && *p <= '9'){
        total = 10 * total + (*p - '0');
        if(total > 2147483648)
            break;
        ++p;
    }
    if(!sign && total > (uint64_t)2147483647)
        total = 2147483647;
    if(sign && total > (uint64_t)2147483648)
        total = 2147483648;
    int res = sign ? 0 - total : total;
    return res;
}
int main()
{
    char *str[20] = {0};
    while(gets(str) != NULL)
    {
        printf("str = %s\n",str);
        printf("res = %d\n",myAtoi(str));
    }
    return 0;
}
