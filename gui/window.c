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

#include "window.h"

void init_logowindow()
{
	logowindow = gtk_window_new();
	mainwindow = gtk_window_new();
	gtk_window_set_application((GtkWindow *)logowindow, app);
	gtk_window_maximize((GtkWindow *)logowindow);
	gtk_widget_show(logowindow);
	get_managers();
	init_titlebar();
	init_browser();
	init_workarea();
}

void init_mainwindow()
{
	mainpane = gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);
	gtk_window_set_application((GtkWindow *)mainwindow, app);
	gtk_window_maximize((GtkWindow *)mainwindow);
	gtk_widget_set_size_request(mainwindow, 1024, 576);
	gtk_window_set_resizable((GtkWindow *)mainwindow, TRUE);
	gtk_window_set_titlebar((GtkWindow *)mainwindow, titlebar);
	gtk_paned_set_wide_handle((GtkPaned*)mainpane, TRUE);
	gtk_paned_set_start_child((GtkPaned *)mainpane, browser);
	gtk_paned_set_end_child((GtkPaned *)mainpane, workarea);
	gtk_paned_set_shrink_start_child((GtkPaned*)mainpane, TRUE);
	gtk_paned_set_resize_start_child((GtkPaned*)mainpane, FALSE);
	gtk_paned_set_shrink_end_child((GtkPaned*)mainpane, FALSE);
	gtk_paned_set_resize_end_child((GtkPaned*)mainpane, FALSE);
	gtk_window_set_child((GtkWindow *)mainwindow, mainpane);
	gtk_window_destroy((GtkWindow *)logowindow);
	gtk_window_present((GtkWindow *)mainwindow);
	g_signal_connect_after(mainwindow, "show", (GCallback)set_surface, NULL);
	g_idle_add((GSourceFunc)set_surface, NULL);
}

static void get_managers()
{
	//dispmanager = gdk_display_manager_get();
	//displays = gdk_display_manager_list_displays(dispmanager);
	//printf("%i\n", g_slist_length(displays));
	display = gdk_display_get_default();
    seat = gdk_display_get_default_seat(display);
    cursor = gdk_seat_get_pointer(seat);
	//display = g_slist_nth_data(displays, 0);
	monitors = gdk_display_get_monitors(display);
	monitor = g_list_model_get_item(monitors, 0);
	gdk_monitor_get_geometry(monitor, &geometry);
	if (geometry.width >= 1024)
		bwidth = 216;
	else
		bwidth = 100;
	printf("%i x %i\n", geometry.width, geometry.height);
	g_signal_connect(monitors, "items-changed", (GCallback)check_projector, NULL);
	check_projector();
}

static void check_projector()
{
	if (!projector && g_list_model_get_item(monitors, 1))
		projector = g_list_model_get_item(monitors, 1);
}

static bool set_surface()
{
    GtkNative *native = gtk_widget_get_native(mainwindow);
    surface = gtk_native_get_surface(native);
    return FALSE;
}
