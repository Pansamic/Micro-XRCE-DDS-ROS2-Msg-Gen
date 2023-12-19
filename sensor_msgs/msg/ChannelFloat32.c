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
 * @file ChannelFloat32.c
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#include "sensor_msgs/msg/ChannelFloat32.h"

#include <ucdr/microcdr.h>
#include <string.h>

bool sensor_msgs_msg_ChannelFloat32_serialize_topic(ucdrBuffer* writer, const sensor_msgs_msg_ChannelFloat32* topic)
{
    bool success = true;

        success &= ucdr_serialize_string(writer, topic->name);

        success &= ucdr_serialize_sequence_float(writer, topic->values, topic->values_size);

    return success && !writer->error;
}

bool sensor_msgs_msg_ChannelFloat32_deserialize_topic(ucdrBuffer* reader, sensor_msgs_msg_ChannelFloat32* topic)
{
    bool success = true;

        success &= ucdr_deserialize_string(reader, topic->name, 255);

        success &= ucdr_deserialize_sequence_float(reader, topic->values, 100, &topic->values_size);

    return success && !reader->error;
}

uint32_t sensor_msgs_msg_ChannelFloat32_size_of_topic(const sensor_msgs_msg_ChannelFloat32* topic, uint32_t size)
{
    uint32_t previousSize = size;
        size += ucdr_alignment(size, 4) + 4 + (uint32_t)strlen(topic->name) + 1;

        size += ucdr_alignment(size, 4) + 4;
        size += ucdr_alignment(size, 4) + topic->values_size * 4;

    return size - previousSize;
}
