#include <string.h>

#include "player.h"

void init_player(PLayer *player, const char *name) {
  strcat(player->name, name);
  player->hp = 100;
  player->attack = 15;
}
