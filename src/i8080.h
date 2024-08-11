#ifndef I8080_H
#define I8080_H

#include <stdint.h>

typedef struct ConditionCodes {
    uint8_t z:1;
    uint8_t s:1;
    uint8_t p:1;
    uint8_t cy:1;
    uint8_t ac:1;
    uint8_t pad:3;
} ConditionCodes;

typedef struct State8080 {
    uint8_t a;
    uint8_t b;
    uint8_t c;
    uint8_t d;
    uint8_t e;
    uint8_t h;
    uint8_t l;
    uint16_t sp;
    uint16_t pc;
    uint8_t *memory;
    ConditionCodes cc;
    uint8_t int_enable;
} State8080;

int parity(int x, int size);
void logicFlags(State8080 *state);
void arithFlags(State8080 *state, uint16_t res);
void bcdArithFlags(State8080 *state, uint16_t res);
void unimplementedInstruction(State8080* state);
void emulate8080Op(State8080* state);

#endif