/*
 * Copyright 2020 Bret Joseph Antonio.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * shared.h
 *
 *  Created on: 26 May 2020
 *      Author: Bret Joseph Antonio
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

extern GtkWidget *logowindow, *mainwindow, *extrawindow;
extern GtkWidget *workarea, *titlebar, *browser, *camview;
extern int bwidth;

void init_titlebar(), init_browser(), init_workarea(), init_player();
void init_sequencer();
#endif /* GUI_SHARED_H_ */
