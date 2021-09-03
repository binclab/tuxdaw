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

#include "browser.h"

void init_browser()
{
	browser = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	browserbook = gtk_notebook_new();
	browserbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	pluginbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	samplebox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	camview = gtk_drawing_area_new();
	browserlabel = gtk_label_new("Browser");
	pluginlabel = gtk_label_new("Plugins");
	samplelabel = gtk_label_new("Samples");
	init_player();
	gtk_notebook_set_scrollable((GtkNotebook*)browserbook, TRUE);
	gtk_widget_set_size_request(browserbook, bwidth, -1);
	gtk_widget_set_size_request(camview, -1, bwidth - 64);
	gtk_widget_set_vexpand(browserbook, TRUE);
	gtk_notebook_append_page((GtkNotebook*)browserbook, browserbox, browserlabel);
	gtk_notebook_append_page((GtkNotebook*)browserbook, pluginbox, pluginlabel);
	gtk_notebook_append_page((GtkNotebook*)browserbook, samplebox, samplelabel);
	gtk_box_append((GtkBox*)browser, browserbook);
	gtk_box_append((GtkBox*)browser, camview);
}


