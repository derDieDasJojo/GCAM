/**
 *  gui_menu_edit.c
 *  Source code file for G-Code generation, simulation, and visualization
 *  library.
 *
 *  Copyright (C) 2006 - 2010 by Justin Shumaker
 *  Copyright (C) 2014 by Asztalos Attila Oszkár
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "gui_menu_edit.h"
#include "gui_menu_util.h"
#include "gui.h"
#include "gui_define.h"
#include "gui_machines.h"
#include "gui_tab.h"

/* NOT AN EXACT CONVERSION - uses x25 for round values */
#define SCALED_INCHES(x) (GCODE_UNITS ((&gui->gcode), x))

void
gui_menu_edit_remove_menuitem_callback (GtkWidget *widget, gpointer data)
{
  gcode_block_t *selected_block;
  GtkTreeIter selected_iter;
  GtkTreeModel *model;
  GtkTreePath *path;
  gui_t *gui;

  gui = (gui_t *)data;

  get_selected_block (gui, &selected_block, &selected_iter);

  if (!selected_block)
    return;

  /* Removing locked blocks is prohibited */
  if (selected_block->flags & GCODE_FLAGS_LOCK)
    return;

  model = gtk_tree_view_get_model (GTK_TREE_VIEW (gui->gcode_block_treeview));
  path = gtk_tree_model_get_path (model, &selected_iter);

  if (selected_block->prev)
  {
    gtk_tree_path_prev (path);
  }
  else if (selected_block->next)
  {
    gtk_tree_path_next (path);
  }
  else
  {
    gtk_tree_path_up (path);
  }

  gtk_tree_selection_select_path (gtk_tree_view_get_selection (GTK_TREE_VIEW (gui->gcode_block_treeview)), path);

  remove_and_destroy_primitive (gui, selected_block, &selected_iter);

  gui_renumber_whole_tree (gui);

  get_selected_block (gui, &selected_block, &selected_iter);

  gui_tab_display (gui, selected_block, 0);

  update_menu_by_selected_item (gui, selected_block);

  gui->opengl.rebuild_view_display_list = 1;

  gui_opengl_context_redraw (&gui->opengl, selected_block);

  gtk_tree_path_free (path);

  update_project_modified_flag (gui, 1);
}

void
gui_menu_edit_optimize_order_menuitem_callback (GtkWidget *widget, gpointer data)
{
  gcode_block_t *selected_block;
  GtkTreeIter selected_iter;
  gui_t *gui;

  gui = (gui_t *)data;

  get_selected_block (gui, &selected_block, &selected_iter);

  gcode_util_merge_list_fragments (&selected_block->listhead);

  gui_recreate_subtree_of (gui, &selected_iter);

  update_menu_by_selected_item (gui, selected_block);
  gui_tab_display (gui, selected_block, 1);

  gui->opengl.rebuild_view_display_list = 1;
  gui_opengl_context_redraw (&gui->opengl, selected_block);

  update_project_modified_flag (gui, 1);
}

static void
pattern_on_assistant_close_cancel (GtkWidget *assistant, gpointer data)
{
  GtkWidget **wlist;

  wlist = (GtkWidget **)data;

  gtk_widget_destroy (assistant);

  free (wlist);
}

/**
 * Generate a periodic pattern from the contents of the currently selected block
 */

static void
pattern_on_assistant_apply (GtkWidget *assistant, gpointer data)
{
  gui_t *gui;
  GtkWidget **wlist;
  GtkTreeIter selected_iter, new_iter;
  gcode_block_t *selected_block;

  wlist = (GtkWidget **)data;                                                   // Retrieve a reference to the GUI context;

  gui = (gui_t *)wlist[0];                                                      // Using that, retrieve a reference to 'gui';

  get_selected_block (gui, &selected_block, &selected_iter);                    // Retrieve the currently selected block / iter;

  /* *INDENT-OFF* */

  if (selected_block->type == GCODE_TYPE_SKETCH)                                // If it's a 'sketch' block, call the sketch pattern generator;
  {
    gcode_sketch_pattern (selected_block,
      gtk_spin_button_get_value (GTK_SPIN_BUTTON (wlist[1])),
      gtk_spin_button_get_value (GTK_SPIN_BUTTON (wlist[2])),
      gtk_spin_button_get_value (GTK_SPIN_BUTTON (wlist[3])),
      gtk_spin_button_get_value (GTK_SPIN_BUTTON (wlist[4])),
      gtk_spin_button_get_value (GTK_SPIN_BUTTON (wlist[5])),
      gtk_spin_button_get_value (GTK_SPIN_BUTTON (wlist[6])));                  // The parameters for the pattern are retrieved directly from the GUI widgets;
  }
  else if (selected_block->type == GCODE_TYPE_DRILL_HOLES)                      // If it's a 'drill holes' block, call the drill holes pattern generator;
  {
    gcode_drill_holes_pattern (selected_block,
      gtk_spin_button_get_value (GTK_SPIN_BUTTON (wlist[1])),
      gtk_spin_button_get_value (GTK_SPIN_BUTTON (wlist[2])),
      gtk_spin_button_get_value (GTK_SPIN_BUTTON (wlist[3])),
      gtk_spin_button_get_value (GTK_SPIN_BUTTON (wlist[4])),
      gtk_spin_button_get_value (GTK_SPIN_BUTTON (wlist[5])),
      gtk_spin_button_get_value (GTK_SPIN_BUTTON (wlist[6])));                  // The parameters for the pattern are retrieved directly from the GUI widgets;
  }

  /* *INDENT-ON* */

  new_iter = gui_insert_after_iter (gui, &selected_iter, selected_block);       // Make a sub-tree from the updated block and insert it after the original iter;

  set_selected_row_with_iter (gui, &new_iter);                                  // Move selection from the original iter to the newly created and inserted one;

  gtk_tree_store_remove (gui->gcode_block_store, &selected_iter);               // Remove the original iter so the new one effectively takes its place;

  gui_renumber_whole_tree (gui);                                                // The new iter / subtree lacks order numbers - update the entire tree;

  gui->opengl.rebuild_view_display_list = 1;
  gui_opengl_context_redraw (&gui->opengl, selected_block);                     // Do a graphic repaint;

  update_project_modified_flag (gui, 1);                                        // Finally, mark the project as 'changed'.
}

static void
pattern_create_page1 (GtkWidget *assistant, gpointer data)
{
  gui_t *gui;
  GtkWidget *table;
  GtkWidget *label;
  GtkWidget *iterations_spin;
  GtkWidget *translatex_spin;
  GtkWidget *translatey_spin;
  GtkWidget *rotate_aboutx_spin;
  GtkWidget *rotate_abouty_spin;
  GtkWidget *rotation_spin;
  GtkWidget **wlist;
  GdkPixbuf *pixbuf;

  wlist = (GtkWidget **)data;

  gui = (gui_t *)wlist[0];

  table = gtk_table_new (6, 2, TRUE);
  gtk_table_set_col_spacings (GTK_TABLE (table), TABLE_SPACING);
  gtk_table_set_row_spacings (GTK_TABLE (table), TABLE_SPACING);
  gtk_container_set_border_width (GTK_CONTAINER (table), BORDER_WIDTH);

  label = gtk_label_new ("Iterations");
  gtk_table_attach_defaults (GTK_TABLE (table), label, 0, 1, 0, 1);

  iterations_spin = gtk_spin_button_new_with_range (2, 100, 1);
  gtk_spin_button_set_digits (GTK_SPIN_BUTTON (iterations_spin), 0);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (iterations_spin), 2);
  gtk_table_attach_defaults (GTK_TABLE (table), iterations_spin, 1, 2, 0, 1);

  label = gtk_label_new ("Translate(X)");
  gtk_table_attach_defaults (GTK_TABLE (table), label, 0, 1, 1, 2);

  translatex_spin = gtk_spin_button_new_with_range (-MAX_DIM_X, MAX_DIM_X, 0.01);
  gtk_spin_button_set_digits (GTK_SPIN_BUTTON (translatex_spin), 5);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (translatex_spin), 0.0);
  gtk_table_attach_defaults (GTK_TABLE (table), translatex_spin, 1, 2, 1, 2);

  label = gtk_label_new ("Translate(Y)");
  gtk_table_attach_defaults (GTK_TABLE (table), label, 0, 1, 2, 3);

  translatey_spin = gtk_spin_button_new_with_range (-MAX_DIM_Y, MAX_DIM_Y, 0.01);
  gtk_spin_button_set_digits (GTK_SPIN_BUTTON (translatey_spin), 5);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (translatey_spin), 0.0);
  gtk_table_attach_defaults (GTK_TABLE (table), translatey_spin, 1, 2, 2, 3);

  label = gtk_label_new ("Rotate About(X)");
  gtk_table_attach_defaults (GTK_TABLE (table), label, 0, 1, 3, 4);

  rotate_aboutx_spin = gtk_spin_button_new_with_range (-MAX_DIM_X, MAX_DIM_X, 0.01);
  gtk_spin_button_set_digits (GTK_SPIN_BUTTON (rotate_aboutx_spin), 5);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (rotate_aboutx_spin), 0.0);
  gtk_table_attach_defaults (GTK_TABLE (table), rotate_aboutx_spin, 1, 2, 3, 4);

  label = gtk_label_new ("Rotate About(Y)");
  gtk_table_attach_defaults (GTK_TABLE (table), label, 0, 1, 4, 5);

  rotate_abouty_spin = gtk_spin_button_new_with_range (-MAX_DIM_Y, MAX_DIM_Y, 0.01);
  gtk_spin_button_set_digits (GTK_SPIN_BUTTON (rotate_abouty_spin), 5);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (rotate_abouty_spin), 0.0);
  gtk_table_attach_defaults (GTK_TABLE (table), rotate_abouty_spin, 1, 2, 4, 5);

  label = gtk_label_new ("Rotation");
  gtk_table_attach_defaults (GTK_TABLE (table), label, 0, 1, 5, 6);

  rotation_spin = gtk_spin_button_new_with_range (-180.0, 180.0, 0.1);
  gtk_spin_button_set_digits (GTK_SPIN_BUTTON (rotation_spin), 5);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (rotation_spin), 0.0);
  gtk_table_attach_defaults (GTK_TABLE (table), rotation_spin, 1, 2, 5, 6);

  wlist[1] = iterations_spin;
  wlist[2] = translatex_spin;
  wlist[3] = translatey_spin;
  wlist[4] = rotate_aboutx_spin;
  wlist[5] = rotate_abouty_spin;
  wlist[6] = rotation_spin;

  gtk_widget_show_all (table);

  gtk_assistant_append_page (GTK_ASSISTANT (assistant), table);
  gtk_assistant_set_page_title (GTK_ASSISTANT (assistant), table, "Pattern");
  gtk_assistant_set_page_type (GTK_ASSISTANT (assistant), table, GTK_ASSISTANT_PAGE_CONFIRM);
  gtk_assistant_set_page_complete (GTK_ASSISTANT (assistant), table, TRUE);

  pixbuf = gtk_widget_render_icon (assistant, GCAM_STOCK_EDIT_GENERATE_PATTERN, GTK_ICON_SIZE_LARGE_TOOLBAR, NULL);
  gtk_assistant_set_page_header_image (GTK_ASSISTANT (assistant), table, pixbuf);
  g_object_unref (pixbuf);
}

void
gui_menu_edit_generate_pattern_menuitem_callback (GtkWidget *widget, gpointer data)
{
  gui_t *gui;
  GtkWidget *assistant;
  GtkWidget **wlist;

  gui = (gui_t *)data;

  assistant = gtk_assistant_new ();

  gtk_window_set_title (GTK_WINDOW (assistant), "Generate Pattern");
  gtk_window_set_default_size (GTK_WINDOW (assistant), -1, -1);
  gtk_window_set_screen (GTK_WINDOW (assistant), gtk_widget_get_screen (gui->window));
  gtk_window_set_transient_for (GTK_WINDOW (assistant), GTK_WINDOW (gui->window));

  wlist = (GtkWidget **)malloc (7 * sizeof (GtkWidget *));

  wlist[0] = (GtkWidget *)gui;

  pattern_create_page1 (assistant, wlist);

  g_signal_connect (G_OBJECT (assistant), "cancel", G_CALLBACK (pattern_on_assistant_close_cancel), wlist);
  g_signal_connect (G_OBJECT (assistant), "close", G_CALLBACK (pattern_on_assistant_close_cancel), wlist);
  g_signal_connect (G_OBJECT (assistant), "apply", G_CALLBACK (pattern_on_assistant_apply), wlist);

  gtk_widget_show (assistant);
}

void
gui_menu_edit_flip_direction_menuitem_callback (GtkWidget *widget, gpointer data)
{
  gcode_block_t *selected_block;
  GtkTreeIter selected_iter;
  gui_t *gui;

  gui = (gui_t *)data;

  get_selected_block (gui, &selected_block, &selected_iter);

  gcode_util_flip_direction (selected_block);

  gui_recreate_subtree_of (gui, &selected_iter);

  update_menu_by_selected_item (gui, selected_block);
  gui_tab_display (gui, selected_block, 1);

  gui->opengl.rebuild_view_display_list = 1;
  gui_opengl_context_redraw (&gui->opengl, selected_block);

  update_project_modified_flag (gui, 1);
}

static void
update_project_callback (GtkWidget *widget, gpointer data)
{
  GtkWidget **wlist;
  GtkTreeIter selected_iter;
  gui_t *gui;
  gcode_block_t *selected_block;
  int unit_in_use, chosen_unit, material_type;
  char *text_field, project_name[32];
  gfloat_t scale_factor;

  wlist = (GtkWidget **)data;

  gui = (gui_t *)wlist[0];

  scale_factor = 1.0;

  unit_in_use = gui->gcode.units;

  strcpy (project_name, gtk_entry_get_text (GTK_ENTRY (wlist[2])));

  text_field = gtk_combo_box_get_active_text (GTK_COMBO_BOX (wlist[3]));

  if (strcmp (text_field, "inch") == 0)
    chosen_unit = GCODE_UNITS_INCH;
  else
    chosen_unit = GCODE_UNITS_MILLIMETER;

  g_free (text_field);

  if ((unit_in_use == GCODE_UNITS_INCH) && (chosen_unit == GCODE_UNITS_MILLIMETER))
    scale_factor = GCODE_INCH2MM;

  if ((unit_in_use == GCODE_UNITS_MILLIMETER) && (chosen_unit == GCODE_UNITS_INCH))
    scale_factor = GCODE_MM2INCH;

  text_field = gtk_combo_box_get_active_text (GTK_COMBO_BOX (wlist[4]));

  if (strcmp (text_field, "aluminium") == 0)
  {
    material_type = GCODE_MATERIAL_ALUMINUM;
  }
  else if (strcmp (text_field, "foam") == 0)
  {
    material_type = GCODE_MATERIAL_FOAM;
  }
  else if (strcmp (text_field, "plastic") == 0)
  {
    material_type = GCODE_MATERIAL_PLASTIC;
  }
  else if (strcmp (text_field, "steel") == 0)
  {
    material_type = GCODE_MATERIAL_STEEL;
  }
  else if (strcmp (text_field, "wood") == 0)
  {
    material_type = GCODE_MATERIAL_WOOD;
  }
  else
  {
    /* Set default to steel since it's the safest choice */
    material_type = GCODE_MATERIAL_STEEL;
  }

  g_free (text_field);

  strcpy (gui->gcode.name, project_name);

  gui->gcode.units = chosen_unit;

  gui->gcode.material_type = material_type;

  gui->gcode.material_size[0] = gtk_spin_button_get_value (GTK_SPIN_BUTTON (wlist[5]));
  gui->gcode.material_size[1] = gtk_spin_button_get_value (GTK_SPIN_BUTTON (wlist[6]));
  gui->gcode.material_size[2] = gtk_spin_button_get_value (GTK_SPIN_BUTTON (wlist[7]));

  gui->gcode.material_origin[0] = gtk_spin_button_get_value (GTK_SPIN_BUTTON (wlist[8]));
  gui->gcode.material_origin[1] = gtk_spin_button_get_value (GTK_SPIN_BUTTON (wlist[9]));
  gui->gcode.material_origin[2] = gtk_spin_button_get_value (GTK_SPIN_BUTTON (wlist[10]));

  gui->gcode.ztraverse = gtk_spin_button_get_value (GTK_SPIN_BUTTON (wlist[11]));

  /* Machine Name */
  text_field = gtk_combo_box_get_active_text (GTK_COMBO_BOX (wlist[12]));

  {
    gui_machine_list_t machine_list;
    int i;

    gui_machines_init (&machine_list);
    gui_machines_read (&machine_list);

    for (i = 0; i < machine_list.num; i++)
    {
      if (strcmp (text_field, machine_list.machine[i].name) == 0)
      {
        strcpy (gui->gcode.machine_name, machine_list.machine[i].name);
        gui->gcode.machine_options = machine_list.machine[i].options;
      }
    }

    gui_machines_free (&machine_list);
  }

  g_free (text_field);

  {
    GtkTextIter start_iter, end_iter;

    gtk_text_buffer_get_start_iter (gtk_text_view_get_buffer (GTK_TEXT_VIEW (wlist[13])), &start_iter);
    gtk_text_buffer_get_end_iter (gtk_text_view_get_buffer (GTK_TEXT_VIEW (wlist[13])), &end_iter);

    strcpy (gui->gcode.notes, gtk_text_buffer_get_text (gtk_text_view_get_buffer (GTK_TEXT_VIEW (wlist[13])), &start_iter, &end_iter, FALSE));
  }

  /* Destroy the window along with all of its widgets */
  gtk_widget_destroy (wlist[1]);

  free (wlist);

  /**
   * Rescale the block tree to reflect the current unit if necessary
   */

  if (scale_factor != 1.0)
  {
    gcode_block_t *index_block;

    index_block = gui->gcode.listhead;

    while (index_block)
    {
      if (index_block->scale)
        index_block->scale (index_block, scale_factor);

      index_block = index_block->next;
    }
  }

  update_project_modified_flag (gui, 1);

  get_selected_block (gui, &selected_block, &selected_iter);
  gui_tab_display (gui, selected_block, 1);

  /**
   * Update OpenGL
   */

  gcode_prep (&gui->gcode);

  gui_opengl_context_prep (&gui->opengl);

  gui->opengl.rebuild_view_display_list = 1;
  gui_opengl_context_redraw (&gui->opengl, selected_block);
}

/**
 * Construct a dialog that allows configuration of miscellaneous parameters of
 * the project, populate it with current values and hook up a callback for the 
 * dialog's "update" event, supplied with a context list of relevant objects;
 * WARNING: Any change in the structure of "wlist" affecting the spin buttons 
 * will break "base_unit_changed_callback" unless it gets updated accordingly
 * NOTE: This is a callback for the "New Project" item of the "File" menu
 */

void
gui_menu_edit_project_settings_menuitem_callback (GtkWidget *widget, gpointer data)
{
  GtkWidget *window;
  GtkWidget *table;
  GtkWidget *label;
  GtkWidget *name_entry;
  GtkWidget *base_unit_combo;
  GtkWidget *material_type_combo;
  GtkWidget *material_sizex_spin;
  GtkWidget *material_sizey_spin;
  GtkWidget *material_sizez_spin;
  GtkWidget *material_originx_spin;
  GtkWidget *material_originy_spin;
  GtkWidget *material_originz_spin;
  GtkWidget *machine_combo;
  GtkWidget *ztraverse_spin;
  GtkWidget *notes_sw;
  GtkWidget *notes_textview;
  GtkWidget *update_button;
  GtkWidget **wlist;
  gui_t *gui;

  gui = (gui_t *)data;

  wlist = (GtkWidget **)malloc (14 * sizeof (GtkWidget *));

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_modal (GTK_WINDOW (window), TRUE);
  gtk_window_set_transient_for (GTK_WINDOW (window), GTK_WINDOW (gui->window));
  gtk_window_set_position (GTK_WINDOW (window), GTK_WIN_POS_MOUSE);
  gtk_window_set_title (GTK_WINDOW (window), "Project Settings");
  gtk_window_set_resizable (GTK_WINDOW (window), FALSE);

  table = gtk_table_new (9, 4, FALSE);
  gtk_table_set_col_spacings (GTK_TABLE (table), TABLE_SPACING);
  gtk_table_set_row_spacings (GTK_TABLE (table), TABLE_SPACING);
  gtk_container_set_border_width (GTK_CONTAINER (table), 4);
  gtk_container_add (GTK_CONTAINER (window), table);

  label = gtk_label_new ("Project Name");
  gtk_table_attach_defaults (GTK_TABLE (table), label, 0, 1, 0, 1);

  name_entry = gtk_entry_new ();
  gtk_entry_set_max_length (GTK_ENTRY (name_entry), 32);
  gtk_table_attach_defaults (GTK_TABLE (table), name_entry, 1, 4, 0, 1);
  gtk_entry_set_text (GTK_ENTRY (name_entry), gui->gcode.name);

  label = gtk_label_new ("Base Unit");
  gtk_table_attach_defaults (GTK_TABLE (table), label, 0, 1, 1, 2);

  base_unit_combo = gtk_combo_box_new_text ();
  gtk_combo_box_append_text (GTK_COMBO_BOX (base_unit_combo), "inch");
  gtk_combo_box_append_text (GTK_COMBO_BOX (base_unit_combo), "millimeter");
  gtk_combo_box_set_active (GTK_COMBO_BOX (base_unit_combo), gui->gcode.units);
  g_signal_connect (base_unit_combo, "changed", G_CALLBACK (base_unit_changed_callback), wlist);
  gtk_table_attach_defaults (GTK_TABLE (table), base_unit_combo, 1, 4, 1, 2);

  label = gtk_label_new ("Material Type");
  gtk_table_attach_defaults (GTK_TABLE (table), label, 0, 1, 2, 3);

  material_type_combo = gtk_combo_box_new_text ();
  gtk_combo_box_append_text (GTK_COMBO_BOX (material_type_combo), "aluminium");
  gtk_combo_box_append_text (GTK_COMBO_BOX (material_type_combo), "foam");
  gtk_combo_box_append_text (GTK_COMBO_BOX (material_type_combo), "plastic");
  gtk_combo_box_append_text (GTK_COMBO_BOX (material_type_combo), "steel");
  gtk_combo_box_append_text (GTK_COMBO_BOX (material_type_combo), "wood");
  gtk_combo_box_set_active (GTK_COMBO_BOX (material_type_combo), gui->gcode.material_type);
  gtk_table_attach_defaults (GTK_TABLE (table), material_type_combo, 1, 4, 2, 3);

  label = gtk_label_new ("Material Size (XYZ)");
  gtk_table_attach_defaults (GTK_TABLE (table), label, 0, 1, 3, 4);

  material_sizex_spin = gtk_spin_button_new_with_range (SCALED_INCHES (0.01), SCALED_INCHES (MAX_DIM_X), SCALED_INCHES (0.01));
  gtk_spin_button_set_digits (GTK_SPIN_BUTTON (material_sizex_spin), 3);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (material_sizex_spin), gui->gcode.material_size[0]);
  gtk_table_attach_defaults (GTK_TABLE (table), material_sizex_spin, 1, 2, 3, 4);

  material_sizey_spin = gtk_spin_button_new_with_range (SCALED_INCHES (0.01), SCALED_INCHES (MAX_DIM_Y), SCALED_INCHES (0.01));
  gtk_spin_button_set_digits (GTK_SPIN_BUTTON (material_sizey_spin), 3);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (material_sizey_spin), gui->gcode.material_size[1]);
  gtk_table_attach_defaults (GTK_TABLE (table), material_sizey_spin, 2, 3, 3, 4);

  material_sizez_spin = gtk_spin_button_new_with_range (SCALED_INCHES (0.01), SCALED_INCHES (MAX_DIM_Z), SCALED_INCHES (0.01));
  gtk_spin_button_set_digits (GTK_SPIN_BUTTON (material_sizez_spin), 3);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (material_sizez_spin), gui->gcode.material_size[2]);
  gtk_table_attach_defaults (GTK_TABLE (table), material_sizez_spin, 3, 4, 3, 4);

  label = gtk_label_new ("Material Origin (XYZ)");
  gtk_table_attach_defaults (GTK_TABLE (table), label, 0, 1, 4, 5);

  material_originx_spin = gtk_spin_button_new_with_range (SCALED_INCHES (0.0), SCALED_INCHES (MAX_DIM_X), SCALED_INCHES (0.01));
  gtk_spin_button_set_digits (GTK_SPIN_BUTTON (material_originx_spin), 3);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (material_originx_spin), gui->gcode.material_origin[0]);
  gtk_table_attach_defaults (GTK_TABLE (table), material_originx_spin, 1, 2, 4, 5);

  material_originy_spin = gtk_spin_button_new_with_range (SCALED_INCHES (0.0), SCALED_INCHES (MAX_DIM_Y), SCALED_INCHES (0.01));
  gtk_spin_button_set_digits (GTK_SPIN_BUTTON (material_originy_spin), 3);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (material_originy_spin), gui->gcode.material_origin[1]);
  gtk_table_attach_defaults (GTK_TABLE (table), material_originy_spin, 2, 3, 4, 5);

  material_originz_spin = gtk_spin_button_new_with_range (SCALED_INCHES (-MAX_DIM_Z), SCALED_INCHES (MAX_DIM_Z), SCALED_INCHES (0.01));
  gtk_spin_button_set_digits (GTK_SPIN_BUTTON (material_originz_spin), 3);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (material_originz_spin), gui->gcode.material_origin[2]);
  gtk_table_attach_defaults (GTK_TABLE (table), material_originz_spin, 3, 4, 4, 5);

  label = gtk_label_new ("Traverse(Z)");
  gtk_table_attach_defaults (GTK_TABLE (table), label, 0, 1, 5, 6);

  ztraverse_spin = gtk_spin_button_new_with_range (SCALED_INCHES (0.0), SCALED_INCHES (MAX_CLR_Z), SCALED_INCHES (0.01));
  gtk_spin_button_set_digits (GTK_SPIN_BUTTON (ztraverse_spin), 2);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (ztraverse_spin), gui->gcode.ztraverse);
  gtk_table_attach_defaults (GTK_TABLE (table), ztraverse_spin, 1, 4, 5, 6);

  {
    gui_machine_list_t machine_list;
    int i;

    gui_machines_init (&machine_list);
    gui_machines_read (&machine_list);

    label = gtk_label_new ("Machine");
    gtk_table_attach_defaults (GTK_TABLE (table), label, 0, 1, 6, 7);
    machine_combo = gtk_combo_box_new_text ();

    /* Current name is first if one exists */
    if (strcmp (gui->gcode.machine_name, ""))
      gtk_combo_box_append_text (GTK_COMBO_BOX (machine_combo), gui->gcode.machine_name);

    for (i = 0; i < machine_list.num; i++)
      if (strcmp (gui->gcode.machine_name, machine_list.machine[i].name))
        gtk_combo_box_append_text (GTK_COMBO_BOX (machine_combo), machine_list.machine[i].name);

    gtk_combo_box_set_active (GTK_COMBO_BOX (machine_combo), 0);
    gtk_table_attach_defaults (GTK_TABLE (table), machine_combo, 1, 4, 6, 7);

    gui_machines_free (&machine_list);
  }

  label = gtk_label_new ("Notes");
  gtk_table_attach_defaults (GTK_TABLE (table), label, 0, 1, 7, 8);

  notes_sw = gtk_scrolled_window_new (NULL, NULL);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (notes_sw), GTK_SHADOW_ETCHED_IN);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (notes_sw), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);
  gtk_table_attach_defaults (GTK_TABLE (table), notes_sw, 1, 4, 7, 8);

  notes_textview = gtk_text_view_new ();
  gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW (notes_textview), GTK_WRAP_WORD_CHAR);

  gtk_text_buffer_insert_at_cursor (gtk_text_view_get_buffer (GTK_TEXT_VIEW (notes_textview)), gui->gcode.notes, -1);

  gtk_container_add (GTK_CONTAINER (notes_sw), notes_textview);

  wlist[0] = (GtkWidget *)gui;
  wlist[1] = window;
  wlist[2] = name_entry;
  wlist[3] = base_unit_combo;
  wlist[4] = material_type_combo;
  wlist[5] = material_sizex_spin;
  wlist[6] = material_sizey_spin;
  wlist[7] = material_sizez_spin;
  wlist[8] = material_originx_spin;
  wlist[9] = material_originy_spin;
  wlist[10] = material_originz_spin;
  wlist[11] = ztraverse_spin;
  wlist[12] = machine_combo;
  wlist[13] = notes_textview;

  update_button = gtk_button_new_with_label ("Update");
  gtk_table_attach_defaults (GTK_TABLE (table), update_button, 3, 4, 8, 9);
  g_signal_connect (G_OBJECT (update_button), "clicked", G_CALLBACK (update_project_callback), wlist);

  gtk_widget_show_all (window);
}

void
gui_menu_edit_duplicate_menuitem_callback (GtkWidget *widget, gpointer data)
{
  gcode_block_t *selected_block, *duplicate_block;
  GtkTreeIter selected_iter;
  gui_t *gui;

  gui = (gui_t *)data;

  get_selected_block (gui, &selected_block, &selected_iter);

  if (selected_block)
    if (selected_block->clone)
      selected_block->clone (&duplicate_block, &gui->gcode, selected_block);

  insert_primitive (gui, duplicate_block, selected_block, &selected_iter, GUI_INSERT_AFTER);

  update_project_modified_flag (gui, 1);
}

static void
scale_on_assistant_close_cancel (GtkWidget *assistant, gpointer data)
{
  GtkWidget **wlist;

  wlist = (GtkWidget **)data;

  gtk_widget_destroy (assistant);

  free (wlist);
}

static void
scale_on_assistant_apply (GtkWidget *assistant, gpointer data)
{
  gui_t *gui;
  GtkWidget **wlist;
  GtkTreeIter selected_iter;
  gcode_block_t *selected_block;
  gfloat_t factor;

  wlist = (GtkWidget **)data;                                                   // Retrieve a reference to the GUI context;

  gui = (gui_t *)wlist[0];                                                      // Using that, retrieve a reference to 'gui';

  get_selected_block (gui, &selected_block, &selected_iter);

  factor = gtk_spin_button_get_value (GTK_SPIN_BUTTON (wlist[1]));

  selected_block->scale (selected_block, factor);

  gui->opengl.rebuild_view_display_list = 1;
  gui_opengl_context_redraw (&gui->opengl, selected_block);

  update_project_modified_flag (gui, 1);

  gui_tab_display (gui, selected_block, 1);
}

static void
scale_create_page1 (GtkWidget *assistant, gpointer data)
{
  gui_t *gui;
  GtkWidget *hbox;
  GtkWidget *label;
  GtkWidget *factor_spin;
  GtkWidget **wlist;
  GdkPixbuf *pixbuf;
  GtkTreeIter selected_iter;
  gcode_block_t *selected_block;

  wlist = (GtkWidget **)data;

  gui = (gui_t *)wlist[0];

  get_selected_block (gui, &selected_block, &selected_iter);

  hbox = gtk_hbox_new (TRUE, TABLE_SPACING);
  gtk_container_set_border_width (GTK_CONTAINER (hbox), BORDER_WIDTH);

  label = gtk_label_new ("Factor");
  gtk_box_pack_start (GTK_BOX (hbox), label, TRUE, TRUE, 0);

  factor_spin = gtk_spin_button_new_with_range (0.0001, SCALED_INCHES (10.0), 0.001);
  gtk_spin_button_set_digits (GTK_SPIN_BUTTON (factor_spin), MANTISSA);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (factor_spin), 1.0);
  gtk_box_pack_start (GTK_BOX (hbox), factor_spin, TRUE, TRUE, 0);

  wlist[1] = factor_spin;

  gtk_widget_show_all (hbox);

  gtk_assistant_append_page (GTK_ASSISTANT (assistant), hbox);
  gtk_assistant_set_page_title (GTK_ASSISTANT (assistant), hbox, "Scale");
  gtk_assistant_set_page_type (GTK_ASSISTANT (assistant), hbox, GTK_ASSISTANT_PAGE_CONFIRM);
  gtk_assistant_set_page_complete (GTK_ASSISTANT (assistant), hbox, TRUE);

  pixbuf = gtk_widget_render_icon (assistant, GCAM_STOCK_EDIT_SCALE, GTK_ICON_SIZE_LARGE_TOOLBAR, NULL);
  gtk_assistant_set_page_header_image (GTK_ASSISTANT (assistant), hbox, pixbuf);
  g_object_unref (pixbuf);
}

void
gui_menu_edit_scale_menuitem_callback (GtkWidget *widget, gpointer data)
{
  gui_t *gui;
  GtkWidget *assistant;
  GtkWidget **wlist;

  gui = (gui_t *)data;

  assistant = gtk_assistant_new ();

  gtk_window_set_title (GTK_WINDOW (assistant), "Scale");
  gtk_window_set_default_size (GTK_WINDOW (assistant), -1, -1);
  gtk_window_set_screen (GTK_WINDOW (assistant), gtk_widget_get_screen (gui->window));
  gtk_window_set_transient_for (GTK_WINDOW (assistant), GTK_WINDOW (gui->window));

  /* Setup Global Widgets */
  wlist = (GtkWidget **)malloc (2 * sizeof (GtkWidget *));

  wlist[0] = (void *)gui;

  scale_create_page1 (assistant, wlist);

  g_signal_connect (G_OBJECT (assistant), "cancel", G_CALLBACK (scale_on_assistant_close_cancel), wlist);
  g_signal_connect (G_OBJECT (assistant), "close", G_CALLBACK (scale_on_assistant_close_cancel), wlist);
  g_signal_connect (G_OBJECT (assistant), "apply", G_CALLBACK (scale_on_assistant_apply), wlist);

  gtk_widget_show (assistant);
}

void
gui_menu_edit_attract_previous_menuitem_callback (GtkWidget *widget, gpointer data)
{
  gcode_block_t *selected_block;
  GtkTreeIter selected_iter;
  gui_t *gui;

  gui = (gui_t *)data;

  get_selected_block (gui, &selected_block, &selected_iter);

  if (selected_block)
  {
    gfloat_t p0[2], p1[2], t0[2], t1[2];

    if (!selected_block->ends)
      return;

    selected_block->ends (selected_block, p0, p1, GCODE_GET);
    if (selected_block->prev)
    {
      if (selected_block->prev->ends)
      {
        selected_block->prev->ends (selected_block->prev, t0, t1, GCODE_GET);
        selected_block->prev->ends (selected_block->prev, t0, p0, GCODE_SET);
      }
    }
  }

  gui->opengl.rebuild_view_display_list = 1;
  gui_opengl_context_redraw (&gui->opengl, selected_block);

  update_project_modified_flag (gui, 1);
}

void
gui_menu_edit_attract_next_menuitem_callback (GtkWidget *widget, gpointer data)
{
  gcode_block_t *selected_block;
  GtkTreeIter selected_iter;
  gui_t *gui;

  gui = (gui_t *)data;

  get_selected_block (gui, &selected_block, &selected_iter);

  if (selected_block)
  {
    gfloat_t p0[2], p1[2], t0[2], t1[2];

    if (!selected_block->ends)
      return;

    selected_block->ends (selected_block, p0, p1, GCODE_GET);

    if (selected_block->next)
    {
      if (selected_block->next->ends)
      {
        selected_block->next->ends (selected_block->next, t0, t1, GCODE_GET);
        selected_block->next->ends (selected_block->next, p1, t1, GCODE_SET);
      }
    }
  }

  gui->opengl.rebuild_view_display_list = 1;
  gui_opengl_context_redraw (&gui->opengl, selected_block);
}

static void
fillet_on_assistant_close_cancel (GtkWidget *assistant, gpointer data)
{
  GtkWidget **wlist;

  wlist = (GtkWidget **)data;

  gtk_widget_destroy (assistant);

  free (wlist);
}

static void
fillet_previous_on_assistant_apply (GtkWidget *assistant, gpointer data)
{
  gui_t *gui;
  GtkWidget **wlist;
  GtkTreeModel *model;
  GtkTreePath *path;
  GtkTreeIter selected_iter;
  gcode_block_t *selected_block, *prev_connected_block, *fillet_block;
  gfloat_t radius;

  wlist = (GtkWidget **)data;                                                   // Retrieve a reference to the GUI context;

  gui = (gui_t *)wlist[0];                                                      // Using that, retrieve a reference to 'gui';

  get_selected_block (gui, &selected_block, &selected_iter);

  radius = gtk_spin_button_get_value (GTK_SPIN_BUTTON (wlist[1]));

  prev_connected_block = gcode_sketch_prev_connected (selected_block);

  gcode_arc_init (&fillet_block, &gui->gcode, selected_block->parent);

  gcode_util_fillet (prev_connected_block, selected_block, fillet_block, radius);

  model = gtk_tree_view_get_model (GTK_TREE_VIEW (gui->gcode_block_treeview));
  path = gtk_tree_model_get_path (model, &selected_iter);

  if (selected_block->prev)
  {
    gtk_tree_path_prev (path);
    gtk_tree_model_get_iter (model, &selected_iter, path);
    insert_primitive (gui, fillet_block, selected_block->prev, &selected_iter, GUI_INSERT_AFTER);
  }
  else
  {
    gtk_tree_path_up (path);
    gtk_tree_model_get_iter (model, &selected_iter, path);
    insert_primitive (gui, fillet_block, selected_block->parent, &selected_iter, GUI_INSERT_UNDER);
  }

  get_selected_block (gui, &selected_block, &selected_iter);
  update_menu_by_selected_item (gui, selected_block);

  gui->opengl.rebuild_view_display_list = 1;
  gui_opengl_context_redraw (&gui->opengl, selected_block);

  update_project_modified_flag (gui, 1);

  gtk_tree_path_free (path);
}

static void
fillet_next_on_assistant_apply (GtkWidget *assistant, gpointer data)
{
  gui_t *gui;
  GtkWidget **wlist;
  GtkTreeIter selected_iter;
  gcode_block_t *selected_block, *next_connected_block, *fillet_block;
  gfloat_t radius;

  wlist = (GtkWidget **)data;                                                   // Retrieve a reference to the GUI context;

  gui = (gui_t *)wlist[0];                                                      // Using that, retrieve a reference to 'gui';

  get_selected_block (gui, &selected_block, &selected_iter);

  radius = gtk_spin_button_get_value (GTK_SPIN_BUTTON (wlist[1]));

  next_connected_block = gcode_sketch_next_connected (selected_block);

  gcode_arc_init (&fillet_block, &gui->gcode, selected_block->parent);

  gcode_util_fillet (selected_block, next_connected_block, fillet_block, radius);

  insert_primitive (gui, fillet_block, selected_block, &selected_iter, GUI_INSERT_AFTER);

  get_selected_block (gui, &selected_block, &selected_iter);
  update_menu_by_selected_item (gui, selected_block);

  gui->opengl.rebuild_view_display_list = 1;
  gui_opengl_context_redraw (&gui->opengl, selected_block);

  update_project_modified_flag (gui, 1);
}

static void
fillet_create_page1 (GtkWidget *assistant, gpointer data)
{
  gui_t *gui;
  GtkWidget *hbox;
  GtkWidget *label;
  GtkWidget *radius_spin;
  GtkWidget **wlist;
  GdkPixbuf *pixbuf;
  GtkTreeIter selected_iter;
  gcode_block_t *selected_block;
  gcode_tool_t *tool;

  wlist = (GtkWidget **)data;

  gui = (gui_t *)wlist[0];

  get_selected_block (gui, &selected_block, &selected_iter);
  tool = gcode_tool_find (selected_block);

  hbox = gtk_hbox_new (TRUE, TABLE_SPACING);
  gtk_container_set_border_width (GTK_CONTAINER (hbox), BORDER_WIDTH);

  label = gtk_label_new ("Radius");
  gtk_box_pack_start (GTK_BOX (hbox), label, TRUE, TRUE, 0);

  radius_spin = gtk_spin_button_new_with_range (0.0001, SCALED_INCHES (10.0), 0.001);
  gtk_spin_button_set_digits (GTK_SPIN_BUTTON (radius_spin), MANTISSA);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (radius_spin), SCALED_INCHES (0.5 * tool->diameter));
  gtk_box_pack_start (GTK_BOX (hbox), radius_spin, TRUE, TRUE, 0);

  wlist[1] = radius_spin;

  gtk_widget_show_all (hbox);

  gtk_assistant_append_page (GTK_ASSISTANT (assistant), hbox);
  gtk_assistant_set_page_title (GTK_ASSISTANT (assistant), hbox, "Fillet");
  gtk_assistant_set_page_type (GTK_ASSISTANT (assistant), hbox, GTK_ASSISTANT_PAGE_CONFIRM);
  gtk_assistant_set_page_complete (GTK_ASSISTANT (assistant), hbox, TRUE);

  if (strstr (gtk_window_get_title (GTK_WINDOW (assistant)), "prev"))
  {
    pixbuf = gtk_widget_render_icon (assistant, GCAM_STOCK_EDIT_FILLET_PREV, GTK_ICON_SIZE_LARGE_TOOLBAR, NULL);
    gtk_assistant_set_page_header_image (GTK_ASSISTANT (assistant), hbox, pixbuf);
    g_object_unref (pixbuf);
  }

  if (strstr (gtk_window_get_title (GTK_WINDOW (assistant)), "next"))
  {
    pixbuf = gtk_widget_render_icon (assistant, GCAM_STOCK_EDIT_FILLET_NEXT, GTK_ICON_SIZE_LARGE_TOOLBAR, NULL);
    gtk_assistant_set_page_header_image (GTK_ASSISTANT (assistant), hbox, pixbuf);
    g_object_unref (pixbuf);
  }
}

void
gui_menu_edit_fillet_previous_menuitem_callback (GtkWidget *widget, gpointer data)
{
  gui_t *gui;
  GtkWidget *assistant;
  GtkWidget **wlist;

  gui = (gui_t *)data;

  assistant = gtk_assistant_new ();

  gtk_window_set_title (GTK_WINDOW (assistant), "Fillet previous");
  gtk_window_set_default_size (GTK_WINDOW (assistant), -1, -1);
  gtk_window_set_screen (GTK_WINDOW (assistant), gtk_widget_get_screen (gui->window));
  gtk_window_set_transient_for (GTK_WINDOW (assistant), GTK_WINDOW (gui->window));

  /* Setup Global Widgets */
  wlist = (GtkWidget **)malloc (2 * sizeof (GtkWidget *));

  wlist[0] = (void *)gui;

  fillet_create_page1 (assistant, wlist);

  g_signal_connect (G_OBJECT (assistant), "cancel", G_CALLBACK (fillet_on_assistant_close_cancel), wlist);
  g_signal_connect (G_OBJECT (assistant), "close", G_CALLBACK (fillet_on_assistant_close_cancel), wlist);
  g_signal_connect (G_OBJECT (assistant), "apply", G_CALLBACK (fillet_previous_on_assistant_apply), wlist);

  gtk_widget_show (assistant);
}

void
gui_menu_edit_fillet_next_menuitem_callback (GtkWidget *widget, gpointer data)
{
  gui_t *gui;
  GtkWidget *assistant;
  GtkWidget *page;
  GtkWidget **wlist;

  gui = (gui_t *)data;

  assistant = gtk_assistant_new ();

  gtk_window_set_title (GTK_WINDOW (assistant), "Fillet next");
  gtk_window_set_default_size (GTK_WINDOW (assistant), -1, -1);
  gtk_window_set_screen (GTK_WINDOW (assistant), gtk_widget_get_screen (gui->window));
  gtk_window_set_transient_for (GTK_WINDOW (assistant), GTK_WINDOW (gui->window));

  /* Setup Global Widgets */
  wlist = (GtkWidget **)malloc (2 * sizeof (GtkWidget *));

  wlist[0] = (void *)gui;

  fillet_create_page1 (assistant, wlist);

  g_signal_connect (G_OBJECT (assistant), "cancel", G_CALLBACK (fillet_on_assistant_close_cancel), wlist);
  g_signal_connect (G_OBJECT (assistant), "close", G_CALLBACK (fillet_on_assistant_close_cancel), wlist);
  g_signal_connect (G_OBJECT (assistant), "apply", G_CALLBACK (fillet_next_on_assistant_apply), wlist);

  gtk_widget_show (assistant);
}
