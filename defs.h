#ifndef DEFS_H
#define DEFS_H

typedef unsigned long long U64; // Making a type (typedef means define type, so I'm basically making my own type) that allocates 64 bits of memory meaning I can have 64 bits.

#define NAME "Xerves 1.0" // Defining the name of my engine, currently the name is the officla name "Xerves" and the version is 1.0.
#define BRD_SQ_NUM 120 // The total number of squares there are in the move searching system, whereas in game its only 64. This is because of faster move searching and to negate errors.
#define MAXGAMEMOVES 2048
#define POP(b) PopBit(b)
#define CNT(b) CountBits(b)
#define CLRBIT(bb, sq) ((bb) &= ClearMask[(sq)])
#define SETBIT(bb, sq) ((bb) |= SetMask[(sq)])


enum {EMPTY, wP, wN, wB, wR, wQ, wK, bP, bN, bB, bR, bQ, bK};  // The only pieces that can exist on a square. Besides empty, the first letter references the color and the second letter references the class of the piece.

enum {FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE}; // The FILE A - H that exists on a chess board. Needed for hierarchical purposes.

enum {RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE}; // The RANK 1 - 8 that exists on a chess board. Needed for hierarchical purposes.

enum { // Contains all the indexes of the squares on the chess board.
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
    A2 = 31, B2, C2, D2, E2, F2, G2, H2,
    A3 = 41, B3, C3, D3, E3, F3, G3, H3,
    A4 = 51, B4, C4, D4, E4, F4, G4, H4,
    A5 = 61, B5, C5, D5, E5, F5, G5, H5,
    A6 = 71, B6, C6, D6, E6, F6, G6, H6,
    A7 = 81, B7, C7, D7, E7, F7, G7, H7,
    A8 = 91, B8, C8, D8, E8, F8, G8, H8, NO_SQ
}; 

enum {FALSE, TRUE};  // To use booleans.

enum { WKCA = 1, WQCA = 2, BKCA = 4, BQCA = 8}; // Castling permission. colour_letter + KCA = King Side Castling, colour_letter + QCA = Queen Side Castling.

typedef struct{

    int move;
    int castlePerm;
    int enPas;
    int fiftyMove;
    U64 posKey;


} S_UNDO;

enum {WHITE, BLACK, BOTH}; // Array containing the sides/colours of the game.

typedef struct { // The Board Object containg the variables it needs to operate.

    int pieces[BRD_SQ_NUM]; 
    U64 pawns[3];

    int KingSq[2];

    int side;
    int enPas;
    int fiftyMove;

    int ply;
    int hisPly;


    U64 posKey;

    int pieceNumber[13];
    int bigPiece[3];
    int majorPiece[3];
    int minorPiece[3];

    S_UNDO history[MAXGAMEMOVES];

} S_BOARD; 

// Macros //
#define FR2SQ(f,r) ( (21 + (f) ) + ( (r) * 10 ) )
#define SQ64(sq120) (Sq120ToSq64[(sq120)])
#define SQ120(sq64) (Sq64ToSq120[(sq64)])

// Globals //

extern int Sq120ToSq64[BRD_SQ_NUM];
extern int Sq64ToSq120[64];
extern U64 SetMask[64];
extern U64 ClearMask[64];   

// Functions //

extern void AllInit(); 

// init.c

// bitboards.c
extern void PrintBitBoard(U64 bb);
extern int PopBit(U64 *bb);
extern int CountBits(U64 b);

#endif