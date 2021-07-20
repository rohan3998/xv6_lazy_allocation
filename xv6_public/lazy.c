#include "types.h"
#include "stat.h"
#include "user.h"

int 
main(int argc, char * argv[]){

char *p;
    
///calling sbrk(5000)
 
    printf(1," Address : 0x%p \n", sbrk(0));
    print_free_frame();
    printf(1,"CALLING sbrk(5000) \n");
    sbrk(5000);
    printf(1," Address : 0x%p \n", sbrk(0));
    print_free_frame();
printf(1,"\n");


//writing
printf(1," Address : 0x%p \n", sbrk(0));
    print_free_frame();
    printf(1,"Writing on 0x%p \n", sbrk(0));
    p = sbrk(0);*p = 10;
    printf(1," Address : 0x%p \n", sbrk(0));
    print_free_frame();
    printf(1,"\n");

///calling sbrk(5000)
printf(1," Address : 0x%p \n", sbrk(0));
    print_free_frame();
    printf(1,"CALLING sbrk(5000) \n");
    sbrk(5000);
    printf(1," Address : 0x%p \n", sbrk(0));
    print_free_frame();
    printf(1,"\n");
 
///writing
    printf(1," Address : 0x%p \n", sbrk(0));
    print_free_frame();
    printf(1,"Writing on 0x%p \n", sbrk(0));
    p = sbrk(0);
    *p = 11;
    printf(1," Address : 0x%p \n", sbrk(0));
    print_free_frame();
    printf(1,"\n");
    

///reclamation
    printf(1," Address : 0x%p \n", sbrk(0));
    print_free_frame();
    printf(1,"CALLING sbrk(-4096) \n");
    sbrk(-4096);
    printf(1," Address : 0x%p \n", sbrk(0));
    print_free_frame();
printf(1,"\n");


printf(1," Address : 0x%p \n", sbrk(0));
    print_free_frame();
    printf(1,"CALLING sbrk(-4096) \n");
    sbrk(-4096);
    printf(1," Address : 0x%p \n", sbrk(0));
    print_free_frame();


}
