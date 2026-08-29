#include <stdio.h>
#include <stdarg.h>

int myMaxFunc(int num_args, ...){

    va_list args;
    
    va_start(args, num_args);

    int max_num = 0;

    for (int i=0; i<num_args; i++){
        int x = va_arg(args, int); 
        if (i==0){ 
            max_num = x; 
        } else if (x > max_num) {
            max_num = x;
        }
    }

    va_end(args);

    return max_num;
}

int main(){

    int myMaxVar = myMaxFunc(4, 14, 89, 12, 56);

    printf("Max number is: %d\n", myMaxVar);

    return 0;
}
