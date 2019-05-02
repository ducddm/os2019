#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 10
typedef struct {
    char type; // 0=fried chicken, 1=French fries
    int amount; // pieces or weight
    char unit; // 0=piece, 1=gram
} item;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void printLog(){
  printf("first = %d\t last = %d\n", first, last);
  return;
}

void produce(item *i) {
    while ((first + 1) % BUFFER_SIZE == last) { 
        // do nothing -- no free buffer item
        }
    memcpy(&buffer[first], i, sizeof(item));
    first = (first + 1) % BUFFER_SIZE;
    printLog();
}

item *consume() {
    item *i = malloc(sizeof(item));
    while (first == last) {
        // do nothing -- nothing to consume
    }
    memcpy(i, &buffer[last], sizeof(item));
    last = (last + 1) % BUFFER_SIZE;
    printLog();
    return i;
}

item *initbuffer(char t, int a, char u){
    item *i = malloc(sizeof(item));
    i->type=t;
    i->amount=a;
    i->unit=u;
    return i;
}

int main(){
    item *order1 = initbuffer(0,2,0);
    item *order2 = initbuffer(1,8,1);
    produce(order1);
    produce(order2);
    consume();
    return 0;
}

