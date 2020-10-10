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
  * webcam.c
  *
  *  Created on: 09 Aug 2020
  *      Author: Bret Joseph Antonio
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