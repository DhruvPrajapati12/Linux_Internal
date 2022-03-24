#include <stdio.h>
#include <pthread.h>

struct char_print_params
{
    char character;
    int count;
};

// parameters to the print function
void* char_print(void* parameters)
{   
    struct char_print_params *s = (struct char_print_params *)parameters;
    printf("structure char data == %c cout == %d\n", s->character, s->count);
    return NULL;
}

void main()
{
    pthread_t t1, t2;

    struct char_print_params arg1;
    struct char_print_params arg2;

    arg1.character = 'x';
    arg1.count = 23;

    arg2.character = 'y';
    arg2.count = 45;

    pthread_create(&t1, NULL, char_print, &arg1);
    pthread_create(&t2, NULL, char_print, &arg2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}