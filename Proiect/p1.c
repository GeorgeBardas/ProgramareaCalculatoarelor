#include <stdio.h>
#include <string.h>

typedef char stackElementT;

 typedef struct {
  stackElementT *contents;
  int maxSize;
  int top;
} stackT;

void newStack(stackT* sp, int maxSize) {
  stackElementT* newContents;

  newContents = (stackElementT *) malloc(sizeof(stackElementT) * maxSize);

  if (newContents == NULL) {
    fprintf(stderr, "Insufficient memory to initialize stack.\n");
    exit(1);
}
  sp->contents = newContents;
  sp->maxSize = maxSize;
  sp->top = -1;
}

void deleteStack(stackT *stackP) {
  free(stackP->contents);
  stackP->contents = NULL;
  stackP->maxSize = 0;
  stackP->top = -1;
}

void push(stackT* sp, stackElementT e) {
  if (isFullStack(sp)) {
    fprintf(stderr, "Can't push element on stack: stack is full.\n");
    exit(1);
  }
  sp->contents[++sp->top] = e;
}

stackElementT pop(stackT* sp) {
  if (isEmptyStack(sp)) {
    fprintf(stderr, "Can't pop element from stack: stack is empty.\n");
    exit(1);
  }
  return sp->contents[sp->top--];
}

int isEmptyStack(stackT* sp) {
  return sp->top < 0;
}

int isFullStack(stackT* sp) {
  return sp->top == sp->maxSize - 1;
}

int main(void)
{
  stackT stack;
  char str[101];
  char *traverse;

  printf("Enter a string: ");
  gets(str);

  newStack(&stack, strlen(str));

  for (traverse = str; *traverse != '\0'; traverse++) {
    push(&stack, *traverse);
  }

  printf("\nPopped characters are: ");

  while (!isEmptyStack(&stack)) {
    printf("%c", pop(&stack));
  }

  printf("\n");
  deleteStack(&stack);
  return 0;
}
