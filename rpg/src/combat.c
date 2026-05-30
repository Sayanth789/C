#include <stdio.h>

#include "combat.h"

void battle(Player *player, Enemy *enemy) {
  printf("\nBattle Started\n");

  while (player->hp > 0 && enemy->hp > 0) {
    enemy->hp -= player->attack;

    printf("%s hits %s for %d damage\n", 
      player->name,
      enemy->name,
      player->attack
    );

    if (enemy->hp <= 0) {
      printf("%s defeated!\n", enemy->name);
      break;
    }
    player->hp -= enemy->attack;

    printf("%s hits %s for %d damage\n", 
      enemy->name,
      player->name,
      enemy->attack
    );

    printf("%s HP %d\n", player->name, player->hp);
    printf("%s HP %d\n", enemy->name, enemy->hp);
      

  }
  if (player->hp <= 0) {
      printf("Game Over!\n");
  }
}



