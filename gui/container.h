/*
 * Copyright (C) 2020  Bret Joseph Antonio
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef GUI_CONTAINER_H_INCLUDED
#define GUI_CONTAINER_H_INCLUDED

#include "shared.h"

#define TUXDAW_PLUGIN_CONTAINER_TYPE (tuxdaw_plugin_container_get_type ())

G_DECLARE_FINAL_TYPE (TuxdawPluginContainer, tuxdaw_plugin_container, TUXDAW, PLUGIN_CONTAINER, GtkBox)

TuxdawPluginContainer *tuxdaw_plugin_container_new(bool custom);

struct _TuxdawPluginContainer
{
    GtkBox parent;
    GtkWidget *header, *body, *title;
    GtkGesture *gesture;
};

typedef struct _TuxdawPluginContainerPrivate
{
    guint custom : 1;
} TuxdawPluginContainerPrivate;

enum {
  PROP_0,
  PROP_CUSTOM,
  NUM_PROPERTIES
};

void plugin_container_set_property(GObject *object,
					     guint prop_id, const GValue *value, GParamSpec *pspec);

void plugin_container_get_property (GObject *object,
					     guint prop_id, GValue *value, GParamSpec *pspec);

void set_header_contents(TuxdawPluginContainer *container);

void plugin_drag_begin(GtkGestureDrag *gesture,
               gdouble start_x, gdouble start_y, TuxdawPluginContainer *plugin);

void plugin_drag_update(GtkGestureDrag *gesture,
               gdouble offsetx, gdouble offsety, TuxdawPluginContainer *plugin);

void plugin_drag_end(GtkGestureDrag *gesture,
               gdouble offsetx, gdouble offsety, TuxdawPluginContainer *plugin);

double coordinate(double size);

extern GtkWidget *fixed;

#endif // GUI_CONTAINER_H_INCLUDED
