#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char board_t[3][3];
typedef struct {
  int x;
  int y;
} coord_t;
char *BOT_NAME = "Bot";

void print_board(board_t board) {
  printf("------------\n");
  for (int i = 0; i < 3; i++) {
    printf("| ");
    for (int j = 0; j < 3; j++) {
      printf("%c |", board[i][j]);
    }
    printf("\n");
  }
  printf("------------\n");
}

typedef struct Player {
  char marker;
  char *name;
  int is_human; // 0 bot; 1 human;
} player_t;

player_t *new_player(char marker, char *name, int is_human) {
  player_t *player = (player_t *)malloc(sizeof(player_t));
  player->marker = marker;
  player->name = name;
  player->is_human = is_human;
  return player;
};

player_t *player_from_input() {
  char is_human;
  char marker;
  char name_buffer[100];
  printf("Add a bot? (y/n): ");
  scanf(" %c", &is_human);
  switch (is_human) {
  case 'y':
    printf("Enter your name: ");
    scanf("%99s", &name_buffer);
    char *name = malloc(strlen(name_buffer) + 1);
    if (!name) return NULL;
    break;
  // TODO: choose marker

  case 'n':
    char *name = malloc(strlen(BOT_NAME) + 1);
    if (!name) return NULL;
    strcpy(name, BOT_NAME);
    break;
  default:
    printf("wrong input! Enten y or n");
    return NULL;
  }
  // TODO: return player
}

void greet_player(player_t *player) {
  printf("hello %s, your marker is %c\n", player->name, player->marker);
};

coord_t pick_a_spot_human() {
  coord_t spot;
  scanf("Enter coord for x: %d\n", &spot.x);
  scanf("Enter coord for y: %d\n", &spot.y);
  return spot;
}

coord_t pick_a_spot_bot() { return (coord_t){.x = 0, .y = 0}; }

void make_a_move(board_t *table, player_t *player) {
  switch (player->human) {
  case 0:
    pick_a_spot_bot();
    return;
  case 1:
    pick_a_spot_human();
    return;
  }
}

void make_a_move_player(player_t player) {}

int main() {
  board_t board = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

  print_board(board);
  // TODO: initiate players
  greet_player(player_1);
  greet_player(player_2);
  free(player_1);
  free(player_2);
  return 0;
}
