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
 * @file Pose.c
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#include "geometry_msgs/msg/Pose.h"

#include <ucdr/microcdr.h>
#include <string.h>

bool geometry_msgs_msg_Pose_serialize_topic(ucdrBuffer* writer, const geometry_msgs_msg_Pose* topic)
{
    bool success = true;

        success &= geometry_msgs_msg_Point_serialize_topic(writer, &topic->position);
        success &= geometry_msgs_msg_Quaternion_serialize_topic(writer, &topic->orientation);
    return success && !writer->error;
}

bool geometry_msgs_msg_Pose_deserialize_topic(ucdrBuffer* reader, geometry_msgs_msg_Pose* topic)
{
    bool success = true;

        success &= geometry_msgs_msg_Point_deserialize_topic(reader, &topic->position);
        success &= geometry_msgs_msg_Quaternion_deserialize_topic(reader, &topic->orientation);
    return success && !reader->error;
}

uint32_t geometry_msgs_msg_Pose_size_of_topic(const geometry_msgs_msg_Pose* topic, uint32_t size)
{
    uint32_t previousSize = size;
        size += geometry_msgs_msg_Point_size_of_topic(&topic->position, size);
        size += geometry_msgs_msg_Quaternion_size_of_topic(&topic->orientation, size);
    return size - previousSize;
}