#ifndef PLAYER_H 
#define PLAYER_H 

typedef struct {
  char name[50];
  int  hp;
  int attack;
} Player;

void init_player(Player *player, const char *name);

#endif
