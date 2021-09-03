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

#include "container.h"

gboolean animate = FALSE;
double startx, starty, cursorx, cursory;
static GParamSpec *plugin_container_props[NUM_PROPERTIES];

G_DEFINE_TYPE_WITH_CODE(TuxdawPluginContainer, tuxdaw_plugin_container, GTK_TYPE_BOX,
                        G_ADD_PRIVATE(TuxdawPluginContainer))

static void tuxdaw_plugin_container_init(TuxdawPluginContainer *container)
{
  container->header = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  container->body = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  container->gesture = gtk_gesture_drag_new();
  container->title = gtk_label_new(NULL);
  gtk_widget_add_css_class((GtkWidget *)&container->parent, "bordered");
  gtk_widget_add_css_class(container->header, "botborder");
  gtk_widget_add_css_class(container->header, "greyback");
  gtk_widget_set_size_request((GtkWidget *)&container->parent, 640, 480);
  gtk_widget_add_controller(container->title, (GtkEventController *)container->gesture);
  gtk_widget_set_hexpand(container->title, TRUE);
  gtk_box_append((GtkBox *)container->header, container->title);
  gtk_box_append(&container->parent, container->header);
  gtk_box_append(&container->parent, container->body);
  g_signal_connect(container->gesture, "drag-begin", (GCallback)plugin_drag_begin, container);
  g_signal_connect(container->gesture, "drag-update", (GCallback)plugin_drag_update, container);
  g_signal_connect(container->gesture, "drag-end", (GCallback)plugin_drag_end, container);
}

static void tuxdaw_plugin_container_class_init(TuxdawPluginContainerClass *containerclass)
{
  GObjectClass *gobjectclass = (GObjectClass *)containerclass;
  gobjectclass->set_property = plugin_container_set_property;
  gobjectclass->get_property = plugin_container_get_property;
  plugin_container_props[PROP_CUSTOM] =
      g_param_spec_boolean("custom",
                           "Plugin Container", "Whether to use a custom plugin container header.",
                           FALSE, G_PARAM_READWRITE);
  g_object_class_install_properties(gobjectclass, NUM_PROPERTIES, plugin_container_props);
}

TuxdawPluginContainer *tuxdaw_plugin_container_new(bool custom)
{
  TuxdawPluginContainer *gobject = g_object_new(TUXDAW_PLUGIN_CONTAINER_TYPE,
                                                "orientation", GTK_ORIENTATION_VERTICAL,
                                                "custom", custom,
                                                NULL);
  return gobject;
}

void set_header_contents(TuxdawPluginContainer *container)
{
  GtkWidget *button1 = gtk_button_new();
  GtkWidget *button2 = gtk_button_new();
  GtkWidget *button3 = gtk_button_new();
  GtkWidget *button4 = gtk_button_new();
  GtkWidget *button5 = gtk_button_new();
  GtkWidget *button6 = gtk_button_new();
  gtk_box_prepend((GtkBox *)container->header, button3);
  gtk_box_prepend((GtkBox *)container->header, button2);
  gtk_box_prepend((GtkBox *)container->header, button1);
  gtk_box_append((GtkBox *)container->header, button4);
  gtk_box_append((GtkBox *)container->header, button5);
  gtk_box_append((GtkBox *)container->header, button6);
}

void plugin_container_set_property(GObject *object, guint prop_id, const GValue *value, GParamSpec *pspec)
{
  TuxdawPluginContainer *plugincontainer = (TuxdawPluginContainer *)object;
  TuxdawPluginContainerPrivate *priv = tuxdaw_plugin_container_get_instance_private(plugincontainer);

  switch (prop_id)
  {
  case PROP_CUSTOM:
    priv->custom = g_value_get_boolean(value);
    if (priv->custom)
      set_header_contents(plugincontainer);
    break;
  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID(object, prop_id, pspec);
    break;
  }
}

void plugin_container_get_property(GObject *object, guint prop_id, GValue *value, GParamSpec *pspec)
{
  TuxdawPluginContainer *plugincontainer = (TuxdawPluginContainer *)object;
  TuxdawPluginContainerPrivate *priv = tuxdaw_plugin_container_get_instance_private(plugincontainer);
  switch (prop_id)
  {
  case PROP_CUSTOM:
    g_value_set_boolean(value, priv->custom);
    break;
  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID(object, prop_id, pspec);
    break;
  }
}

void plugin_drag_begin(GtkGestureDrag *gesture,
                       gdouble start_x, gdouble start_y, TuxdawPluginContainer *plugin)
{
  GdkCursor *mouse = gdk_cursor_new_from_name("grab", NULL);
  gtk_widget_set_cursor(plugin->title, mouse);
  gtk_fixed_get_child_position((GtkFixed *)fixed, (GtkWidget *)plugin, &startx, &starty);
}

void plugin_drag_update(GtkGestureDrag *gesture,
                        gdouble offsetx, gdouble offsety, TuxdawPluginContainer *plugin)
{

  if (animate)
  {
    startx = coordinate(startx + offsetx);
    starty = coordinate(starty + offsety);
    gtk_fixed_move((GtkFixed *)fixed, (GtkWidget *)plugin, startx, starty);
  }
}

void plugin_drag_end(GtkGestureDrag *gesture,
                     gdouble offsetx, gdouble offsety, TuxdawPluginContainer *plugin)
{
  GdkCursor *mouse = gdk_cursor_new_from_name("default", NULL);
  gtk_widget_set_cursor(plugin->title, mouse);
  if (!animate)
  {
    startx = coordinate(startx + offsetx);
    starty = coordinate(starty + offsety);
    gtk_fixed_move((GtkFixed *)fixed, (GtkWidget *)plugin, startx, starty);
  }
}

double coordinate(double size)
{
  if (size < 0)
    return 0;
  else
    return size;
}
