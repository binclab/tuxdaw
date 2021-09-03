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

#include "sequencer.h"
#include "icons.h"

bool stepview = TRUE;

G_DEFINE_TYPE(TuxdawSequencerChannel, tuxdaw_sequencer_channel, GTK_TYPE_BOX)

void init_sequencer()
{
    sequencer = tuxdaw_plugin_container_new(TRUE);
    body = (GtkBox *)sequencer->body;
    init_header();
    init_body();
}

static void init_header()
{
    gtk_label_set_text((GtkLabel *)sequencer->title, "Sequencer");
    gtk_widget_add_css_class(sequencer->title, "plugintitle");
}

static void init_body()
{
    GtkWidget *channel;
    for (int i = 0; i < 10; i++)
    {
        channel = tuxdaw_sequencer_channel_new();
        gtk_box_append(body, channel);
    }
}

static void tuxdaw_sequencer_channel_init(TuxdawSequencerChannel *channel)
{
    GtkWidget *activebtn = gtk_check_button_new(),
              *volbtn = gtk_volume_button_new(),
              *panbtn = gtk_scale_button_new(-1, 1, 0.1, NULL),
              *selectbtn = gtk_toggle_button_new(),
              *stack = gtk_stack_new(),
              *stepview = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0),
              *stepbtn;
    
    for (int i = 0; i < 16; i++)
    {
        stepbtn = gtk_toggle_button_new();
        //gtk_widget_set_name(stepbtn, "StepButton");
        /*if (i < 4 || (i >= 8 && i < 12))
            gtk_widget_add_css_class(stepbtn, "bluestepbtn");
        else if (i < 8 || i >= 12)
            gtk_widget_add_css_class(stepbtn, "greenstepbtn");
        gtk_widget_add_css_class(stepbtn, "rounded");*/
        gtk_widget_add_css_class(stepbtn, "circular");
        gtk_box_append((GtkBox *)stepview, stepbtn);
    }

    gtk_scale_button_set_value((GtkScaleButton*)volbtn, 6);
    gtk_scale_button_set_value((GtkScaleButton*)panbtn, 0);
    gtk_scale_button_set_icons((GtkScaleButton*)panbtn, NULL );
    gtk_check_button_set_active((GtkCheckButton*)activebtn, TRUE);
    GtkStackPage *stepstack = gtk_stack_add_child((GtkStack *)stack, stepview);
    gtk_stack_page_set_visible(stepstack, TRUE);
    gtk_box_append(&channel->parent, activebtn);
    gtk_box_append(&channel->parent, volbtn);
    gtk_box_append(&channel->parent, panbtn);
    gtk_box_append(&channel->parent, selectbtn);
    gtk_box_append(&channel->parent, stack);
}

static void tuxdaw_sequencer_channel_class_init(TuxdawSequencerChannelClass *channelclass)
{
    //
}

GtkWidget *tuxdaw_sequencer_channel_new()
{
    return g_object_new(TUXDAW_SEQUENCER_CHANNEL_TYPE, "orientation", GTK_ORIENTATION_HORIZONTAL, NULL);
}

