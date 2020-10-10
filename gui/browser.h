/*
 * Copyright (C) 2020 Bret Joseph Antonio
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
 * browser.h created 31 May 2020 at 17:28:49
 */

#ifndef GUI_BROWSER_H_
#define GUI_BROWSER_H_

#include "shared.h"

GtkWidget *browser, *browserbook, *browserlabel, *browserbook, *camview;
GtkWidget *filelabel, *pluginlabel, *samplelabel, *browserbox, *pluginbox, *samplebox;

GtkMediaStream stream;


int bwidth;

#endif /* GUI_BROWSER_H_ */
