#include <stdio.h>
#include <stdlib.h>
typedef struct snode {
  void *n;
  struct snode *next;
} snode;

typedef struct dnode {
  void *n;
  struct dnode *prev;
  struct dnode *next;
} dnode;

typedef struct stack {
  struct dnode *top;
  size_t size;
} stack;

typedef struct queue {
  struct dnode *front;
  struct dnode *back;
  size_t size;
} queue;

typedef struct deque {
  struct dnode *front;
  struct dnode *back;
  size_t size;
};

int
main() {
  
}
