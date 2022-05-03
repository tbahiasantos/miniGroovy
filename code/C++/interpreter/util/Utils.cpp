#include "Utils.h"

#include <cstdio>
#include <cstdlib>

void Utils::abort(int line) {
    printf("%02d: Operação inválida\n", line);
    exit(1);
}
