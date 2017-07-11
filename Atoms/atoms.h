#ifndef ATOMS_H
#define ATOMS_H

#include <stdint.h>

#define MAX_LINE 255
#define MIN_WIDTH 2
#define MIN_HEIGHT 2
#define MAX_WIDTH 255
#define MAX_HEIGHT 255
#define MIN_PLAYERS 2
#define MAX_PLAYERS 6

typedef struct move_t move_t;
typedef struct grid_t grid_t;
typedef struct game_t game_t;
typedef struct save_t save_t;
typedef struct player_t player_t;
typedef struct save_file_t save_file_t;

enum color{
    Red,Green,Purple,Blue,Yellow,White,empty
};

// struct node;
// typedef struct node *PtrToNode;
// typedef PtrToNode PlayerList;
// typedef PtrToNode Position;
//
// struct node
// {
//     enum color Player;
//     Position next;
// };


struct move_t {
    int x;
    int y;
    move_t* parent;
    move_t* extra;
    player_t* old_owner;
};

struct game_t {
    move_t* moves;
};

struct grid_t {
    //player_t* owner;
    enum color owner;
    int atom_count;
};

struct player_t {
    enum color colour;
    int grids_owned;
};

struct save_t {
    char* filename;
    save_file_t* data;
};

struct save_file_t {
    uint8_t width;
    uint8_t height;
    uint8_t no_players;
    uint8_t** raw_move_data;
};

#endif
