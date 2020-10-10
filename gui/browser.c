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
 * browser.c
 *
 *  Created on: 31 May 2020
 *      Author: Bret Joseph Antonio
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


