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

#ifndef GUI_TITLEBAR_H_
#define GUI_TITLEBAR_H_

#include "shared.h"

GMenu *mainmenu, *filemenu, *editmenu, *prefmenu, *infomenu;

GtkWidget *titlebar, *topheader, *bottomheader, *toptitle, *bottomtitle;
GtkWidget *menubar, *remotebar, *meterbar, *timebar, *mediacontrol, *winbar;
GtkWidget *infobar, *seekbar, *projectbar, *navbox, *shortbar;
GtkWidget *pitchbtn, *seekscale, *snapcombo, *snapdown, *patcombo, *patentry;
GtkWidget *volbtn, *playbtn, *stopbtn, *recordbtn, *spinbtn;
GtkWidget *seclabel, *minlabel;

GtkEntryBuffer *patbuffer;
GtkListStore *patstore;
GtkTreeIter patiter;
GtkMediaStream *mediastream;

static const gchar *snaplist[] =
    {
        "Beat",
        "Bar",
        "1/2",
        "1/3",
        "1/4",
        "1/6",
        "1/8",
        "None",
};

enum
{
    NAME_COLUMN,
    NUM_COLS
};

typedef struct
{
    const char *patname;
} PatList;

static PatList patlist[] = {
    {"Pattern Name"},
    {"Pattern Name"},
    {"Pattern Name"},
    {"Pattern Name"},
    {"Pattern Name"},
    {"Pattern 6"},
    {"Pattern 7"},
    {"Pattern 8"},
    {"Pattern 9"},
    {"Pattern 10"},
};

static void construct_topheader(), construct_bottomheader();
static void construct_menubar(), construct_remotebar(), construct_meterbar(), construct_timebar();
static void construct_infobar(), construct_seekbar(), construct_projectbar(), construct_navbar();
static void construct_shortcuts();
static void construct_filemenu();
static void add_actions();
static void populate_snaplist(), populate_patlist(), change_patname(), add_pattern();
static void toggle_play(), click_stop();

gint patnum = 10;

#endif /* GUI_TITLEBAR_H_ */
