/*
 * Author: Joost Renes
 * Version: 2017-05-24
 * Public Domain
 */
#ifndef DH_H
#define DH_H

#include "ladder.h"
#include "scalar.h"

int dh_keygen(
        unsigned char *pk,
        unsigned char *sk
        );
int dh_exchange(
        unsigned char *ss,
        unsigned char *pk,
        unsigned char *sk
        );

#endif
