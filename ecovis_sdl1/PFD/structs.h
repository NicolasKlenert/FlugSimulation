/*
 * Author     : Angel Chiou
 * Date       : 10/06/2007
 * Filename   : PFD.h
 * Description:
 * Changes    :
 */
#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct {
    int value;
    int source;
    bool valid;
    bool initialized;
} int_A429;

typedef struct {
    float value;
    int source;
    bool valid;
    bool initialized;
} float_A429;

#endif
