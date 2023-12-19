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
 * @file KeyValue.c
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#include "diagnostic_msgs/msg/KeyValue.h"

#include <ucdr/microcdr.h>
#include <string.h>

bool diagnostic_msgs_msg_KeyValue_serialize_topic(ucdrBuffer* writer, const diagnostic_msgs_msg_KeyValue* topic)
{
    bool success = true;

        success &= ucdr_serialize_string(writer, topic->key);

        success &= ucdr_serialize_string(writer, topic->value);

    return success && !writer->error;
}

bool diagnostic_msgs_msg_KeyValue_deserialize_topic(ucdrBuffer* reader, diagnostic_msgs_msg_KeyValue* topic)
{
    bool success = true;

        success &= ucdr_deserialize_string(reader, topic->key, 255);

        success &= ucdr_deserialize_string(reader, topic->value, 255);

    return success && !reader->error;
}

uint32_t diagnostic_msgs_msg_KeyValue_size_of_topic(const diagnostic_msgs_msg_KeyValue* topic, uint32_t size)
{
    uint32_t previousSize = size;
        size += ucdr_alignment(size, 4) + 4 + (uint32_t)strlen(topic->key) + 1;

        size += ucdr_alignment(size, 4) + 4 + (uint32_t)strlen(topic->value) + 1;

    return size - previousSize;
}