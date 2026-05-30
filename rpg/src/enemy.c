#include <string.h>
#include "enemy.h"

void init_enemy(Enemy *enemy) {
  strcat(enemy->name, "Darth Vader");
  enemy->hp = 60;
  enemy->attack = 10;
}
