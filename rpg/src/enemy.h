#ifndef ENEMY_H 

#define ENEMY_H

typedef struct {
    char name[50];
    int hp;
    int attack;
} Enemy;

void init_enemy(Enemy *enemy);

#endif
