#include "stdio.h"
#include "defs.h"

int main()
{
    AllInit();

    U64 playBitBoard = 0ULL;

    playBitBoard |= (1ULL << SQ64(D2));
    playBitBoard |= (1ULL << SQ64(D3));
    playBitBoard |= (1ULL << SQ64(G2));

    return 0;
}