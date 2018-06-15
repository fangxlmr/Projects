#ifndef LIST_H
#define LIST_H

#define T List_T
typedef struct T *T;

extern T list_new(int n);

extern void list_free(T *list);

extern void list_append(T list, char *str, int val);

extern char *list_getstr(T list);

extern void list_tonum(T list);

#undef T
#endif /* LIST_H */