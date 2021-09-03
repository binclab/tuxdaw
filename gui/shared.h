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

#ifndef GUI_SHARED_H_
#define GUI_SHARED_H_

#include <gtk/gtk.h>
//#include <gst/gst.h>
//#include <gst/video/videooverlay.h>
#include <ladspa.h>

#if defined (GDK_WINDOWING_X11)
#include <gdk/x11/gdkx.h>
#elif defined (GDK_WINDOWING_WAYLAND)
#include <gdk/wayland/gdkwayland.h>
#endif

extern GtkApplication *app;

extern GdkDisplay *display;
extern GdkDisplayManager *dispmanager;
extern GdkMonitor *monitor, *projector;
extern GdkRectangle geometry;
extern GdkSurface *surface;
extern GListModel *monitors;
extern GSList *displays;
extern GdkSeat *seat;
extern GdkDevice *cursor;
extern GtkCssProvider *provider;
extern GtkStyleContext *context;

extern GtkWidget *logowindow, *mainwindow, *extrawindow;
extern GtkWidget *workarea, *titlebar, *browser, *camview;
extern GtkIconTheme *theme;
extern int bwidth;

void init_titlebar(), init_browser(), init_workarea(), init_player();
void init_sequencer();
#endif /* GUI_SHARED_H_ */
