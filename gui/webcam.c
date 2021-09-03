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

#include "webcam.h"

void init_player()
{
    #if defined (GDK_WINDOWING_X11)
    //window_handle = gdk_x11_surface_get_xid(surface);
    #elif defined (GDK_WINDOWING_WAYLAND)
    window_handle = gdk_wayland_surface_get_wl_surface(camview);
    #endif

    //player = gst_parse_launch("v4l2src ! autovideosink", &error);
    //gst_video_overlay_set_window_handle((GstVideoOverlay*)player, window_handle);
}