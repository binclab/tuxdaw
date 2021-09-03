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

#ifndef GUI_SEQUENCER_H_INCLUDED
#define GUI_SEQUENCER_H_INCLUDED

#include "container.h"

#define TUXDAW_SEQUENCER_CHANNEL_TYPE (tuxdaw_sequencer_channel_get_type ())

TuxdawPluginContainer *sequencer;
GtkBox *body;

static void init_header(), init_body();

G_DECLARE_FINAL_TYPE (TuxdawSequencerChannel, tuxdaw_sequencer_channel, TUXDAW, SEQUENCER_CHANNEL, GtkBox)

GtkWidget *tuxdaw_sequencer_channel_new();

struct _TuxdawSequencerChannel
{
    GtkBox parent;
    GtkWidget *header, *body, *title;
    GtkGesture *gesture;
};

#endif // GUI_SEQUENCER_H_INCLUDED
