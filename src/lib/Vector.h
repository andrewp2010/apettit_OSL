#include "Params.h"

#ifndef VECTOR_H
#define VECTOR_H

#define VECTOR_DB vector(0.0, 0.0, 0.0)

#define VECTOR_INPUTS \
    VECTOR("", inputV, VECTOR_DB, string label = "Vector")

#define VECTOR_OUTPUTS \
    OUT_FLOAT(resultV, 0.0)

#endif // VECTOR_H