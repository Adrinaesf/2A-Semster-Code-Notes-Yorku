#include <stdio.h>

int main(){
    /*
        Example: int x= 1, y=1, z; 
        z = ++x + y-- + --y; 
        printf("%d\n", z); 

        Wrong behaviour in C: 
        Undefined behaviur in C y modified twice.  
        and we can't modify it at the same time twice. 

        Solution: 
        z = (++x + y--) + --y; 
        then z = (2 + 1) + --y when y = 0, x=2 so we now have: 
        x = (2 + 1) + -1 = 2

    */
    int a[10] = {0}; 
    for (int i = 0; i < 10; i++){
        scanf("%d", &a[i]); 
    }

    return 0; 
}