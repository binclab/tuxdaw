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

#include "workarea.h"

void init_workarea()
{
	workarea = gtk_scrolled_window_new();
	fixed = gtk_fixed_new();
	init_sequencer();
	gtk_fixed_put((GtkFixed *)fixed, (GtkWidget *)sequencer, 50, 40);
	gtk_widget_set_size_request(workarea, geometry.width - bwidth, -1);
	gtk_scrolled_window_set_child((GtkScrolledWindow *)workarea, fixed);
	g_signal_connect_after(workarea, "realize", add_plugins, NULL);
}

static void add_plugins()
{
	//add_sequencer();
}
