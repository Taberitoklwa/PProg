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
#include <string.h>

#include "command.h"
#include "libscreen.h"
#include "space.h"
#include "types.h"

#define MAX_OBJECTS_SPACE 3  
#define WIDTH_LINE 21
#define WIDTH_MAP 48
#define WIDTH_DES 29
#define WIDTH_BAN 23
#define HEIGHT_MAP 16
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
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, id_east = NO_ID, id_west= NO_ID, obj_loc = NO_ID, idaux=NO_ID;
  Space *space_act = NULL;
  char objs[255]="";
  char str[500]="";
  int objsinspace=0, auxprinted=0;
  Cmd last_cmd = UNKNOWN;
  extern char *cmd_to_str[N_CMD][N_CMDT];
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

    objects = game_get_objects(game);
    nobjects = game_get_num_objects(game);

    /*Mirar primitivas de object_get_id*/

    sprintf(objs, " ");

    for(i=0, objsinspace=0; i<nobjects && objsinspace<=MAX_OBJECTS_SPACE ; i++){

      if(objsinspace==3){
        strcat(objs, "...");
        break;
      }

      if (game_get_object_location(game, game->objects[i]) == id_back){
        sprintf(str, "0%ld,", object_get_id(game->objects[i]));
        strcat(objs, str);  
        objsinspace++;
      }

    }


    if (id_back != NO_ID) {

      if(game_get_character(game, id_back)!=NULL && (character_get_hp(game_get_character(game, id_back))>0)){

        auxprinted=sprintf(str, "  |  m0^  %6s  %3d|", character_get_name(game_get_character(game, id_back)), (int)id_back);

      }
      else{

        auxprinted=sprintf(str, "  |  m0^          %3d|", (int)id_back);

      }
      screen_area_puts(ge->map, str);


      sprintf(str, "  |                  |");
      screen_area_puts(ge->map, str);
      auxprinted=sprintf(str, "  |%s            ", objs);
      for(;auxprinted<WIDTH_LINE; auxprinted++, strcat(str, " "));
      strcat(str, "|");
      screen_area_puts(ge->map, str);
      sprintf(str, "  +------------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "         ^");
      screen_area_puts(ge->map, str);
    }

    sprintf(objs, " ");

    for(i=0, objsinspace=0; i<nobjects && objsinspace<=MAX_OBJECTS_SPACE ; i++){

      if(objsinspace==3){
        strcat(objs, "...");
        break;
      }

      if (game_get_object_location(game, game->objects[i]) == id_act){
      sprintf(str, "0%ld,", object_get_id(game->objects[i]));
      strcat(objs, str);
      objsinspace++;
      }
    }


    if (id_act != NO_ID) {
      sprintf(str, "  +------------------+");
      screen_area_puts(ge->map, str);

      if(game_get_character(game, id_act)!=NULL && (character_get_hp(game_get_character(game, id_act))>0)){

        auxprinted=sprintf(str, "  |  m0^  %6s  %3d|", character_get_name(game_get_character(game, id_act)), (int)id_act);

      }
      else{

        auxprinted=sprintf(str, "  |  m0^          %3d|", (int)id_act);

      }

      screen_area_puts(ge->map, str);
      sprintf(str, "  |                  |");
      screen_area_puts(ge->map, str);

      if (id_east != NO_ID && id_west != NO_ID){
        auxprinted=sprintf(str, "<-|  %s", objs);
        for(; auxprinted<WIDTH_LINE; strcat(str, " "), auxprinted++);
        strcat(str, "|-->");
        screen_area_puts(ge->map, str);
      }
      else if(id_west != NO_ID){
        auxprinted=sprintf(str, "<-|  %s", objs);
        for(; auxprinted<WIDTH_LINE; strcat(str, " "), auxprinted++);
        strcat(str, "|");
        screen_area_puts(ge->map, str);
      }
      else if(id_east != NO_ID){
        auxprinted=sprintf(str, "  |  %s  ", objs);
        for(; auxprinted<WIDTH_LINE; strcat(str, " "), auxprinted++);
        strcat(str, "|-->");
        screen_area_puts(ge->map, str);
      }
      else{
        auxprinted=sprintf(str, "  |%s ", objs);
        for(; auxprinted<WIDTH_LINE; strcat(str, " "), auxprinted++);
        strcat(str, "|");
        screen_area_puts(ge->map, str);
      }
  
      sprintf(str, "  +------------------+");
      screen_area_puts(ge->map, str);
    }

    sprintf(objs, " ");

    for(i=0, objsinspace=0; i<nobjects && objsinspace<=MAX_OBJECTS_SPACE; i++){

      if(objsinspace==3){
        strcat(objs, "...");
        break;
      } 

      if (game_get_object_location(game, game->objects[i]) == id_next){
      sprintf(str, "0%ld,", object_get_id(game->objects[i]));
      strcat(objs, str);
      objsinspace++;
      }
    }

    if (id_next != NO_ID) {
      sprintf(str, "        v");
      screen_area_puts(ge->map, str);
      sprintf(str, "  +------------------+");
      screen_area_puts(ge->map, str);

      if(game_get_character(game, id_next)!=NULL && (character_get_hp(game_get_character(game, id_next))>0)){

        sprintf(str, "  |  m0^  %6s  %3d|", character_get_name(game_get_character(game, id_next)), (int)id_next);

      }
      else{

        sprintf(str, "  |  m0^          %3d|", (int)id_next);

      }
      screen_area_puts(ge->map, str);

      sprintf(str, "  |                  |");
      screen_area_puts(ge->map, str);
      auxprinted=sprintf(str, "  |%s            ", objs);
      for(;auxprinted<WIDTH_LINE; auxprinted++, strcat(str, " "));
      strcat(str, "|");
      screen_area_puts(ge->map, str);
  
    }
  }

  /* Paint in the description area */
  screen_area_clear(ge->descript);
  
  /*Painting the object location*/

  if(nobjects>0){
    sprintf(str, " Objects location: ");
    screen_area_puts(ge->descript, str);
      for(i=0; i<nobjects; i++){
        if((obj_loc=game_get_object_location(game, objects[i]))!=NO_ID){
              sprintf(str, " O%ld: %ld", object_get_id(objects[i]), obj_loc);
              screen_area_puts(ge->descript, str);
        } 

    }
  }

  sprintf(str," ");
  screen_area_puts(ge->descript, str);

  sprintf(str, "Characters:");
  screen_area_puts(ge->descript, str);

  for(i=0; i<game->n_characters; i++){
  
    sprintf(str, " %s: %d (%d)", character_get_name(game->characters[i]), (int)game_get_character_location(game, game->characters[i]), character_get_hp(game->characters[i]));
    screen_area_puts(ge->descript, str);

  }

  sprintf(str," ");
  screen_area_puts(ge->descript, str);

  if(game->player){
    sprintf(str, "Player: %d (%d)", (int)game_get_player_location(game), player_get_health(game->player));
    screen_area_puts(ge->descript, str);
    /*Cambiar*/
    
    if((idaux=player_get_object(game->player))!=NO_ID){
      sprintf(str, "Player has the object O%d", (int)idaux);
      screen_area_puts(ge->descript, str);
    }
    else{
      sprintf(str, "Player has no object");
      screen_area_puts(ge->descript, str);
    }
  }

  
  if(character_get_message(game_get_character(game,id_act))!=NULL && game_get_last_command(game)==CHAT && game_get_last_command_status(game)==OK){
    sprintf(str, " ");
    screen_area_puts(ge->descript, str);
    sprintf(str, "Message: %s", character_get_message(game_get_character(game,id_act)));
    screen_area_puts(ge->descript, str);
  }

  /*MIRAAAAR BIEN, SI CREO UNA VARIABLE AUXILIAR Y APUNTA NULL ME LANZA UNA VIOLACION DE SEGMENTO*/




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
