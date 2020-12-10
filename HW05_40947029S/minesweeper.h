#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <stdint.h>
int32_t checkvalid(int32_t,int32_t,int32_t,int32_t);
void generatemine(int32_t,int32_t,int32_t,int32_t *,int32_t *);
void printmap(int32_t,int32_t,int32_t *,int32_t *,int32_t *);
int32_t mapopen(int32_t,int32_t,int32_t,int32_t,int32_t *, int32_t *);
int32_t checkflag(int32_t,int32_t,int32_t *,int32_t *);

#endif
