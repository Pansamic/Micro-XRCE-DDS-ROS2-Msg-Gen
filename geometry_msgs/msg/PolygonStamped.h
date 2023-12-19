// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file PolygonStamped.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _PolygonStamped_H_
#define _PolygonStamped_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <stdbool.h>
#include "std_msgs/msg/Header.h"
#include "Polygon.h"

typedef struct geometry_msgs_msg_PolygonStamped
{
    std_msgs_msg_Header header;
    geometry_msgs_msg_Polygon polygon;
} geometry_msgs_msg_PolygonStamped;

struct ucdrBuffer;

bool geometry_msgs_msg_PolygonStamped_serialize_topic(struct ucdrBuffer* writer, const geometry_msgs_msg_PolygonStamped* topic);
bool geometry_msgs_msg_PolygonStamped_deserialize_topic(struct ucdrBuffer* reader, geometry_msgs_msg_PolygonStamped* topic);
uint32_t geometry_msgs_msg_PolygonStamped_size_of_topic(const geometry_msgs_msg_PolygonStamped* topic, uint32_t size);


#ifdef __cplusplus
}
#endif

#endif // _PolygonStamped_H_