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

#ifndef MAIN_H_
#define MAIN_H_

#include "gui/shared.h"

GtkApplication *app;
GdkDevice *cursor;
GdkDisplay *display;
GdkDisplayManager *dispmanager;
GdkMonitor *monitor, *projector;
GdkRectangle geometry;
GdkSeat *seat;
GtkIconTheme *theme;
GListModel *monitors;
GSList *displays;
GtkStyleContext *context;
GtkCssProvider*provider;

extern void init_logowindow(), init_mainwindow();

static void set_accelarators(), show_preferences();

static void open_project(), new_project(), save_project(), save_project_as();
static void export_project();
static void quit_tuxdaw();

static GActionEntry app_entries[] =
{
  { "new", new_project, NULL, NULL, NULL },
  { "open", open_project, NULL, NULL, NULL },
  { "save", save_project, NULL, NULL, NULL },
  { "saveas", save_project, NULL, NULL, NULL },
  { "export", export_project, NULL, NULL, NULL },
  { "quit", quit_tuxdaw, NULL, NULL, NULL }
};

#endif /* MAIN_H_ */
