#include<stdio.h>
#include<stdbool.h>
bool isPalindrome(int x)
{
   if(x == 0)
       return true;
   if(x < 0 || x % 10 == 0)
       return false;
   int half = 0;
   while(x > half)
   {
       half = 10 * half + x % 10;
       x /= 10;
   }
   return x == half || x == half / 10;
}
int main(void)
{
    int x;
    while(scanf("%d",&x))
    {
        printf("%d\n",isPalindrome(x));
    }
    return 0;
}
