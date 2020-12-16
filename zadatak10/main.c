#include<stdio.h>
#include<stdlib.h>


int test() {
    static int x = 10;

    printf("%d\n", x);
    x++;
}


int main() {
}
