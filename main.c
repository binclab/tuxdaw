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
 *
 * main.c created 20 May 2020 at 12:14:49
 */

#include "main.h"

int main(int response, char **name)
{
    printf("Starting!...\n");
    app = gtk_application_new("org.binclab.daw", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "startup", (GCallback)set_accelarators, NULL);
    g_signal_connect(app, "activate", (GCallback)init_mainwindow, NULL);
    response = g_application_run((GApplication*)app, response, name);
    g_object_unref(app);
    printf("Goodbye!...\n");
    return response;
}

static void set_accelarators()
{
    const gchar *new_accels[2] ={ "<Ctrl>N", NULL };
    const gchar *open_accels[2] ={ "<Ctrl>Q", NULL };
    const gchar *save_accels[2] ={ "<Ctrl>S", NULL };
    const gchar *saveas_accels[2] ={ "<Shift><Ctrl>Q", NULL };
    const gchar *export_accels[2] ={ "<Ctrl>E", NULL };
    const gchar *quit_accels[2] ={ "<Ctrl>Q", NULL };
    gint entries = G_N_ELEMENTS(app_entries);
    g_action_map_add_action_entries((GActionMap*)app, app_entries, entries, app);
    gtk_application_set_accels_for_action(app, "app.new", new_accels);
    gtk_application_set_accels_for_action(app, "app.open", open_accels);
    gtk_application_set_accels_for_action(app, "app.save", save_accels);
    gtk_application_set_accels_for_action(app, "app.saveas", saveas_accels);
    gtk_application_set_accels_for_action(app, "app.export", export_accels);
    gtk_application_set_accels_for_action(app, "app.quit", quit_accels);
    init_logowindow();
}

static void quit_tuxdaw()
{
    g_application_quit((GApplication*)app);
}

static void open_project()
{

}

static void new_project()
{

}

static void save_project()
{

}

static void save_project_as()
{

}

static void export_project()
{

}

static void show_preferences()
{

}