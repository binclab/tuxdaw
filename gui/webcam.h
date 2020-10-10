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

#ifndef GUI_WEBCAM_H_
#define GUI_WEBCAM_H_

#include "shared.h"

GdkSurface *camsurface;
//GstElement *player;
GError *error;

guintptr window_handle;

#endif /* GUI_WEBCAM_H_ */
