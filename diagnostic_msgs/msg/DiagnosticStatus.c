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
 * @file DiagnosticStatus.c
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#include "diagnostic_msgs/msg/DiagnosticStatus.h"

#include <ucdr/microcdr.h>
#include <string.h>





bool diagnostic_msgs_msg_DiagnosticStatus_serialize_topic(ucdrBuffer* writer, const diagnostic_msgs_msg_DiagnosticStatus* topic)
{
    bool success = true;

        success &= ucdr_serialize_uint8_t(writer, topic->level);

        success &= ucdr_serialize_string(writer, topic->name);

        success &= ucdr_serialize_string(writer, topic->message);

        success &= ucdr_serialize_string(writer, topic->hardware_id);

        success &= ucdr_serialize_uint32_t(writer, topic->values_size);
        for(size_t i = 0; i < topic->values_size; ++i)
        {
            success &= diagnostic_msgs_msg_KeyValue_serialize_topic(writer, &topic->values[i]);
        }

    return success && !writer->error;
}

bool diagnostic_msgs_msg_DiagnosticStatus_deserialize_topic(ucdrBuffer* reader, diagnostic_msgs_msg_DiagnosticStatus* topic)
{
    bool success = true;

        success &= ucdr_deserialize_uint8_t(reader, &topic->level);

        success &= ucdr_deserialize_string(reader, topic->name, 255);

        success &= ucdr_deserialize_string(reader, topic->message, 255);

        success &= ucdr_deserialize_string(reader, topic->hardware_id, 255);

        success &= ucdr_deserialize_uint32_t(reader, &topic->values_size);
        if(topic->values_size > 100)
        {
            reader->error = true;
        }
        else
        {
            for(size_t i = 0; i < topic->values_size; ++i)
            {
                success &= diagnostic_msgs_msg_KeyValue_deserialize_topic(reader, &topic->values[i]);
            }
        }

    return success && !reader->error;
}

uint32_t diagnostic_msgs_msg_DiagnosticStatus_size_of_topic(const diagnostic_msgs_msg_DiagnosticStatus* topic, uint32_t size)
{
    uint32_t previousSize = size;
        size += ucdr_alignment(size, 1) + 1;

        size += ucdr_alignment(size, 4) + 4 + (uint32_t)strlen(topic->name) + 1;

        size += ucdr_alignment(size, 4) + 4 + (uint32_t)strlen(topic->message) + 1;

        size += ucdr_alignment(size, 4) + 4 + (uint32_t)strlen(topic->hardware_id) + 1;

        size += ucdr_alignment(size, 4) + 4;
        for(size_t i = 0; i < topic->values_size; ++i)
        {
            size += diagnostic_msgs_msg_KeyValue_size_of_topic(&topic->values[i], size);
        }

    return size - previousSize;
}