#include "pebble.h"
//
#define NUM_MENU_SECTIONS 2
#define NUM_FIRST_MENU_ITEMS 3
#define NUM_SECOND_MENU_ITEMS 0
//
static Window *window;
static SimpleMenuLayer *simple_menu_layer;
static SimpleMenuSection menu_sections[NUM_MENU_SECTIONS];
static SimpleMenuItem first_menu_items[NUM_FIRST_MENU_ITEMS];
static SimpleMenuItem second_menu_items[NUM_SECOND_MENU_ITEMS];
//
//
//
static void regional_select_callback(int index, void *ctx) {
  
  first_menu_items[index].title = "Make new menu";
  first_menu_items[index].subtitle = "I need to learn how";
  layer_mark_dirty(simple_menu_layer_get_layer(simple_menu_layer));

}
//
//
//
static void cred_select_callback(int index, void *ctx) {
  
  first_menu_items[index].title = "Make new menu";
  first_menu_items[index].subtitle = "I need learn how";
  layer_mark_dirty(simple_menu_layer_get_layer(simple_menu_layer));
}
//
//
//
static void team_select_callback(int index, void *ctx) {
  
first_menu_items[index].title = "Make new window";
  first_menu_items[index].subtitle = "I need to learn how";
  layer_mark_dirty(simple_menu_layer_get_layer(simple_menu_layer));

}
//
//
//
static void window_load(Window *window) {
  int num_a_items = 0;
  first_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Regionals",
    .subtitle = "Information on events",
    .callback = regional_select_callback,
  };
  //
  //
  //
  first_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Team Lookup",
    .subtitle = "Information on a team",
    .callback = team_select_callback,
  };
  //
  //
  //
  first_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "       FRC SCOUT",
    .subtitle = "        By Team 2383",
    .callback = cred_select_callback
  };
  //
  //
  //
  menu_sections[0] = (SimpleMenuSection){
    .title = "       == FRC Scout == ",
    .num_items = NUM_FIRST_MENU_ITEMS,
    .items = first_menu_items,
  };
  //
  //
  //
  menu_sections[1] = (SimpleMenuSection){
    .title = "       == FRC Scout == ",
    .num_items = NUM_SECOND_MENU_ITEMS,
    .items = second_menu_items,
  };
  //
  //
  //
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);
  simple_menu_layer = simple_menu_layer_create(bounds, window, menu_sections, NUM_MENU_SECTIONS, NULL);
  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}
void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
}
int main(void) {
  window = window_create();
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  //
  //
  //
  window_stack_push(window, true /* Animated */);
  app_event_loop();
  window_destroy(window);
}
