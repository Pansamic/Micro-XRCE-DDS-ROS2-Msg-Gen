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
 * @file WrenchStamped.c
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#include "geometry_msgs/msg/WrenchStamped.h"

#include <ucdr/microcdr.h>
#include <string.h>

bool geometry_msgs_msg_WrenchStamped_serialize_topic(ucdrBuffer* writer, const geometry_msgs_msg_WrenchStamped* topic)
{
    bool success = true;

        success &= std_msgs_msg_Header_serialize_topic(writer, &topic->header);
        success &= geometry_msgs_msg_Wrench_serialize_topic(writer, &topic->wrench);
    return success && !writer->error;
}

bool geometry_msgs_msg_WrenchStamped_deserialize_topic(ucdrBuffer* reader, geometry_msgs_msg_WrenchStamped* topic)
{
    bool success = true;

        success &= std_msgs_msg_Header_deserialize_topic(reader, &topic->header);
        success &= geometry_msgs_msg_Wrench_deserialize_topic(reader, &topic->wrench);
    return success && !reader->error;
}

uint32_t geometry_msgs_msg_WrenchStamped_size_of_topic(const geometry_msgs_msg_WrenchStamped* topic, uint32_t size)
{
    uint32_t previousSize = size;
        size += std_msgs_msg_Header_size_of_topic(&topic->header, size);
        size += geometry_msgs_msg_Wrench_size_of_topic(&topic->wrench, size);
    return size - previousSize;
}
