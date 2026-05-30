#include <stdio.h>

#include "game.h"
#include "player.h"
#include "enemy.h"
#include "combat.h"


void start_game(void) {
  char player_name[50] = {0};

  printf("Enter thine name ...!");
  scanf("%49s", player_name);

  Player player;
  Enemy enemy;

  init_player(&player, player_name);
  init_enemy(&enemy);

  battle(&player, &enemy);
}
