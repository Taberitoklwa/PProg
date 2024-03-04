/**
 * @brief It defines a textual graphic engine
 *
 * @file graphic_engine.c
 * @author Profesores PPROG
 * @version 3.5
 * @date 26-01-2024
 * @copyright GNU Public License
 */

#include "graphic_engine.h"

#include <stdio.h>
#include <stdlib.h>

#include "command.h"
#include "libscreen.h"
#include "space.h"
#include "types.h"

#define WIDTH_MAP 48
#define WIDTH_DES 29
#define WIDTH_BAN 23
#define HEIGHT_MAP 13
#define HEIGHT_BAN 1
#define HEIGHT_HLP 2
#define HEIGHT_FDB 3

struct _Graphic_engine {
  Area *map, *descript, *banner, *help, *feedback; /* <Pointers to an area type structure> */
};

Graphic_engine *graphic_engine_create() {
  static Graphic_engine *ge = NULL;

  if (ge) {
    return ge;
  }



  screen_init(HEIGHT_MAP + HEIGHT_BAN + HEIGHT_HLP + HEIGHT_FDB + 4, WIDTH_MAP + WIDTH_DES + 3);
  ge = (Graphic_engine *)malloc(sizeof(Graphic_engine));
  if (ge == NULL) {
    return NULL;
  }

  /* <Initialize the members of the structure by calling the screen_area_init function> */

  ge->map = screen_area_init(1, 1, WIDTH_MAP, HEIGHT_MAP);
  ge->descript = screen_area_init(WIDTH_MAP + 2, 1, WIDTH_DES, HEIGHT_MAP);
  ge->banner = screen_area_init((int)((WIDTH_MAP + WIDTH_DES + 1 - WIDTH_BAN) / 2), HEIGHT_MAP + 2, WIDTH_BAN, HEIGHT_BAN);
  ge->help = screen_area_init(1, HEIGHT_MAP + HEIGHT_BAN + 2, WIDTH_MAP + WIDTH_DES + 1, HEIGHT_HLP);
  ge->feedback = screen_area_init(1, HEIGHT_MAP + HEIGHT_BAN + HEIGHT_HLP + 3, WIDTH_MAP + WIDTH_DES + 1, HEIGHT_FDB);

  return ge;
}

void graphic_engine_destroy(Graphic_engine *ge) {
  if (!ge) return;

  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->banner);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);

  screen_destroy();
  free(ge);
}


void graphic_engine_paint_game(Graphic_engine *ge, Game *game){

  /* Assigns default values ​​to the different Id type variables, pointers, chars etc. */
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, id_east = NO_ID, id_west= NO_ID, obj_loc = NO_ID;
  Space *space_act = NULL;
  Id obj = NO_ID;
  int objinspace;
  char str[255];
  Command last_cmd = UNKNOWN;
  Object **objects;
  int nobjects;
  extern char *cmd_to_str[N_CMD][N_CMDT];
  int i;

  last_cmd = game_get_last_command(game);
  /* Paint the in the map area */
  screen_area_clear(ge->map);
  if ((id_act = game_get_player_location(game)) != NO_ID) {
    space_act = game_get_space(game, id_act);
    id_back = space_get_north(space_act);
    id_east = space_get_east(space_act);
    id_west = space_get_west(space_act);
    id_next = space_get_south(space_act);

    n_objects=game_get_num_objects;

    for(i=0, i<n_objects, i++){
      if (game_get_object_location(game, game->objects[i]) == id_back)
      obj = game_get;
    else
      obj = ' ';
    }
    if (game_get_object_location(game, game->objects[0]) == id_back)
      obj = '*';
    else
      obj = ' ';

    if (id_back != NO_ID) {
      sprintf(str, "  |         %2d|", (int)id_back);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |     %c     |", obj);
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "        ^");
      screen_area_puts(ge->map, str);
    }

    if (game_get_object_location(game, game->objects[0]) == id_act)
      obj = '*';
    else
      obj = ' ';

    if (id_act != NO_ID) {
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "  | m0^     %2d|", (int)id_act);
      screen_area_puts(ge->map, str);

      if (id_east != NO_ID && id_west != NO_ID){
        sprintf(str, "<-|     %c     |-->", obj);
        screen_area_puts(ge->map, str);
      }
      else if(id_west != NO_ID){
        sprintf(str, "<-|     %c     |", obj);
        screen_area_puts(ge->map, str);
      }
      else if(id_east != NO_ID){
        sprintf(str, "  |     %c     |-->", obj);
        screen_area_puts(ge->map, str);
      }
      else{
        sprintf(str, "  |     %c     |", obj);
        screen_area_puts(ge->map, str);
      }
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
    }

    if (game_get_object_location(game, game->objects[0]) == id_next)
      obj = '*';
    else
      obj = ' ';

    if (id_next != NO_ID) {
      sprintf(str, "        v");
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |         %2d|", (int)id_next);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |     %c     |", obj);
      screen_area_puts(ge->map, str);
    }
  }

  /* Paint in the description area */
  screen_area_clear(ge->descript);
  
  /*Painting the object location*/

  objects = game_get_objects(game);
  nobjects = game_get_num_objects(game);
  if(nobjects>0){
    sprintf(str, " Objects location: ");
    screen_area_puts(ge->descript, str);
      for(i=0; i<nobjects; i++){
        if((obj_loc=game_get_object_location(game, objects[i]))!=NO_ID){
              sprintf(str, " O%ld %ld", object_get_id(objects[i]), obj_loc);
              screen_area_puts(ge->descript, str);
        }

    }
  }

  if(last_cmd==CHAT && game->last_cmd_status==OK){
    sprintf(str, "Message: hello"),
    screen_area_puts(ge->descript, str);
  }





  /* Paint in the banner area */
  screen_area_puts(ge->banner, " The anthill game ");

  /* Paint in the help area */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "     next or n, back or b, right or r, left or l, attack or a, chat or c, exit or e");
  screen_area_puts(ge->help, str);

  /* Paint in the feedback area */
  if(game->last_cmd_status == OK ){
    sprintf(str, " %s (%s):  OK", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);
    screen_area_puts(ge->feedback, str);
  }
  else{
    sprintf(str, " %s (%s): ERROR", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);
    screen_area_puts(ge->feedback, str);
  }



  /* Dump to the terminal */
  screen_paint();
  printf("prompt:> ");
}
