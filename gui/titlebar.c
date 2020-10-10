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
  * titlebar.c
  *
  *  Created on: 31 May 2020
  *      Author: Bret Joseph Antonio
  */

#include "titlebar.h"

void init_titlebar()
{
	titlebar = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	topheader = gtk_header_bar_new();
	bottomheader = gtk_header_bar_new();
	toptitle = gtk_label_new(NULL);
	bottomtitle = gtk_label_new(NULL);
	gtk_header_bar_set_title_widget((GtkHeaderBar *)topheader, toptitle);
	gtk_header_bar_set_title_widget((GtkHeaderBar *)bottomheader, bottomtitle);
	gtk_header_bar_set_show_title_buttons((GtkHeaderBar *)topheader, TRUE);
	gtk_header_bar_set_show_title_buttons((GtkHeaderBar *)bottomheader, FALSE);
	construct_topheader();
	construct_bottomheader();
	gtk_box_append((GtkBox *)titlebar, topheader);
	gtk_box_append((GtkBox *)titlebar, bottomheader);
}

void construct_topheader()
{
	construct_menubar();
	construct_remotebar();
	construct_meterbar();
}

void construct_bottomheader()
{
	construct_infobar();
	construct_seekbar();
	construct_projectbar();
	construct_navbar();
	construct_shortcuts();
}

static void construct_menubar()
{
	mainmenu = g_menu_new();
	menubar = gtk_popover_menu_bar_new_from_model((GMenuModel *)mainmenu);
	construct_filemenu();
	editmenu = g_menu_new();
	prefmenu = g_menu_new();
	infomenu = g_menu_new();
	g_menu_append_submenu(mainmenu, "Edit", (GMenuModel *)editmenu);
	g_menu_append_submenu(mainmenu, "Settings", (GMenuModel *)prefmenu);
	g_menu_append_submenu(mainmenu, "About", (GMenuModel *)infomenu);
	gtk_header_bar_pack_start((GtkHeaderBar *)topheader, menubar);
}

static void construct_remotebar()
{
	volbtn = gtk_volume_button_new();
	playbtn = gtk_toggle_button_new();
	stopbtn = gtk_button_new_from_icon_name("media-playback-stop");
	recordbtn = gtk_toggle_button_new();
	spinbtn = gtk_spin_button_new_with_range(33, 165, 1);
	remotebar = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	mediastream = gtk_media_file_new();
	mediacontrol = gtk_media_controls_new(mediastream);
	gtk_button_set_icon_name((GtkButton *)playbtn, "media-playback-start");
	gtk_button_set_icon_name((GtkButton *)recordbtn, "media-record");
	gtk_spin_button_set_value((GtkSpinButton *)spinbtn, 132);
	gtk_box_append((GtkBox *)remotebar, playbtn);
	gtk_box_append((GtkBox *)remotebar, stopbtn);
	gtk_box_append((GtkBox *)remotebar, recordbtn);
	gtk_box_append((GtkBox *)remotebar, spinbtn);
	construct_timebar();
	gtk_header_bar_pack_start((GtkHeaderBar *)topheader, volbtn);
	gtk_header_bar_pack_start((GtkHeaderBar *)topheader, remotebar);
	g_signal_connect(playbtn, "toggled", (GCallback)toggle_play, NULL);
	g_signal_connect(stopbtn, "clicked", (GCallback)click_stop, NULL);
}

static void construct_meterbar()
{
	meterbar = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	for (int i = 0; i < 5; i++)
	{
		GtkWidget *button = gtk_button_new();
		gtk_box_append((GtkBox *)meterbar, button);
	}
	gtk_header_bar_pack_start((GtkHeaderBar *)topheader, meterbar);
}

static void construct_infobar()
{
	infobar = gtk_info_bar_new();
	pitchbtn = gtk_scale_button_new(0, 100, 1, NULL);
	gtk_widget_set_size_request(infobar, 204, -1);
	gtk_header_bar_pack_start((GtkHeaderBar *)bottomheader, infobar);
	gtk_header_bar_pack_start((GtkHeaderBar *)bottomheader, pitchbtn);
}

static void construct_seekbar()
{
	seekscale = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL, 0, 100, 1);
	gtk_scale_set_draw_value((GtkScale *)seekscale, FALSE);
	gtk_widget_set_size_request(seekscale, 220, -1);
	gtk_header_bar_pack_start((GtkHeaderBar *)bottomheader, seekscale);
}

static void construct_projectbar()
{
	projectbar = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	patstore = gtk_list_store_new(NUM_COLS, G_TYPE_STRING);
	snapcombo = gtk_combo_box_text_new();
	patcombo = gtk_combo_box_new_with_model_and_entry((GtkTreeModel *)patstore);
	patentry = gtk_combo_box_get_child((GtkComboBox *)patcombo);
	patbuffer = gtk_entry_get_buffer((GtkEntry *)patentry);
	gtk_widget_set_size_request(patcombo, 168, -1);
	populate_snaplist();
	populate_patlist();
	gtk_box_append((GtkBox *)projectbar, snapcombo);
	gtk_box_append((GtkBox *)projectbar, patcombo);
	gtk_header_bar_pack_start((GtkHeaderBar *)bottomheader, projectbar);
}

static void construct_navbar()
{
	navbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	for (int i = 0; i < 5; i++)
	{
		GtkWidget *button = gtk_button_new();
		gtk_box_append((GtkBox *)navbox, button);
	}
	gtk_header_bar_pack_end((GtkHeaderBar *)bottomheader, navbox);//end
}

static void construct_shortcuts()
{
	shortbar = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	for (int i = 0; i < 5; i++)
	{
		GtkWidget *button = gtk_button_new();
		gtk_box_append((GtkBox *)shortbar, button);
	}
	gtk_header_bar_pack_end((GtkHeaderBar *)bottomheader, shortbar);//end
}

static void add_actions()
{
	//g_action_map_add_action((GActionMap*)app, NULL);
}

static void construct_filemenu()
{
	GMenu *filesection = g_menu_new(), *savesection = g_menu_new();
	GMenu *exportsection = g_menu_new(), *exportmenu = g_menu_new();
	GMenu *quitsection = g_menu_new() /*, *saveasmenu = g_menu_new()*/;
	filemenu = g_menu_new();
	g_menu_append(filesection, "New", "app.new");
	g_menu_append(filesection, "Open", "app.open");
	g_menu_append_section(filemenu, NULL, (GMenuModel *)filesection);

	g_menu_append(savesection, "Save", "app.save");
	g_menu_append(savesection, "Save As", "app.saveas");
	g_menu_append_section(filemenu, NULL, (GMenuModel *)savesection);

	g_menu_append(exportmenu, "wav", "app.exportwav");
	g_menu_append(exportmenu, "mp3", "app.exportmp3");
	g_menu_append_submenu(exportsection, "Export", (GMenuModel *)exportmenu);
	g_menu_append_section(filemenu, NULL, (GMenuModel *)exportsection);

	g_menu_append(quitsection, "Quit", "app.quit");
	g_menu_append_section(filemenu, NULL, (GMenuModel *)quitsection);

	g_menu_append_submenu(mainmenu, "File", (GMenuModel *)filemenu);
	g_signal_connect(app, "startup", (GCallback)add_actions, NULL);
}

static void construct_timebar()
{
	timebar = gtk_info_bar_new();
	gtk_widget_set_valign(timebar, GTK_ALIGN_CENTER);
	gtk_widget_set_halign(timebar, GTK_ALIGN_CENTER);
	GtkWidget *lbl1 = gtk_label_new("0"), *lbl2  = gtk_label_new(":"), *lbl3  = gtk_label_new("0");
	gtk_info_bar_add_child((GtkInfoBar*)timebar, lbl1);
	gtk_info_bar_add_child((GtkInfoBar*)timebar, lbl2);
	gtk_info_bar_add_child((GtkInfoBar*)timebar, lbl3);
	gtk_box_append((GtkBox *)remotebar, timebar);
}

static void populate_snaplist()
{
	for (int i = 0; i < G_N_ELEMENTS(snaplist); i++)
	{
		gtk_combo_box_text_append_text((GtkComboBoxText *)snapcombo, snaplist[i]);
	}
	gtk_combo_box_set_active((GtkComboBox *)snapcombo, 0);
}

static void populate_patlist()
{
	gtk_entry_set_has_frame((GtkEntry *)patentry, TRUE);
	gtk_entry_set_max_length((GtkEntry *)patentry, 12);
	gtk_entry_set_icon_from_icon_name((GtkEntry *)patentry, GTK_ENTRY_ICON_PRIMARY, "list-add");
	gtk_combo_box_set_entry_text_column((GtkComboBox*)patcombo, NAME_COLUMN);

	for (gint i = 0; i < G_N_ELEMENTS(patlist); i++)
	{
		char buffer[12];
		snprintf(buffer, 12, "Pattern %02d", i + 1);
		gtk_list_store_append(patstore, &patiter);
		//gtk_list_store_set(patstore, &patiter, NAME_COLUMN, patlist[i].patname, -1);
		gtk_list_store_set(patstore, &patiter, NAME_COLUMN, buffer, -1);
	}
	gtk_combo_box_set_active((GtkComboBox *)patcombo, NAME_COLUMN);
	g_signal_connect(patentry, "icon-press", (GCallback)add_pattern, NULL);
	g_signal_connect_after(patbuffer, "deleted-text", (GCallback)change_patname, NULL);
	g_signal_connect_after(patbuffer, "inserted-text", (GCallback)change_patname, NULL);
}

static void change_patname()
{
	const gchar *name = gtk_entry_buffer_get_text((GtkEntryBuffer*)patbuffer);
	gtk_combo_box_get_active_iter((GtkComboBox*)patcombo, &patiter);
	gtk_list_store_set(patstore, &patiter, NAME_COLUMN, name, -1);
	//gtk_combo_box_set_active((GtkComboBox *)patcombo, NAME_COLUMN);
}

static void add_pattern()
{
	char buffer[12];
	patnum = patnum + 1;
	snprintf(buffer, 12, "Pattern %02d", patnum);
	if (patnum <16)
	{
		gtk_list_store_append(patstore, &patiter);
		gtk_list_store_set(patstore, &patiter, NAME_COLUMN, buffer, -1);
	}
}

static void toggle_play()
{
	if (gtk_toggle_button_get_active((GtkToggleButton *)playbtn))
	{
		gtk_button_set_icon_name((GtkButton *)playbtn, "media-playback-pause");
	}
	else
		gtk_button_set_icon_name((GtkButton *)playbtn, "media-playback-start");
}

static void click_stop()
{
	if (gtk_toggle_button_get_active((GtkToggleButton *)playbtn))
		gtk_toggle_button_set_active((GtkToggleButton *)playbtn, FALSE);
}