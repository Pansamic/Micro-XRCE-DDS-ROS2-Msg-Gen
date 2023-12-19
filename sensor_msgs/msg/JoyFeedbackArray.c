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
 * @file JoyFeedbackArray.c
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#include "sensor_msgs/msg/JoyFeedbackArray.h"

#include <ucdr/microcdr.h>
#include <string.h>

bool sensor_msgs_msg_JoyFeedbackArray_serialize_topic(ucdrBuffer* writer, const sensor_msgs_msg_JoyFeedbackArray* topic)
{
    bool success = true;

        success &= ucdr_serialize_uint32_t(writer, topic->array_size);
        for(size_t i = 0; i < topic->array_size; ++i)
        {
            success &= sensor_msgs_msg_JoyFeedback_serialize_topic(writer, &topic->array[i]);
        }
    return success && !writer->error;
}

bool sensor_msgs_msg_JoyFeedbackArray_deserialize_topic(ucdrBuffer* reader, sensor_msgs_msg_JoyFeedbackArray* topic)
{
    bool success = true;

        success &= ucdr_deserialize_uint32_t(reader, &topic->array_size);
        if(topic->array_size > 100)
        {
            reader->error = true;
        }
        else
        {
            for(size_t i = 0; i < topic->array_size; ++i)
            {
                success &= sensor_msgs_msg_JoyFeedback_deserialize_topic(reader, &topic->array[i]);
            }
        }
    return success && !reader->error;
}

uint32_t sensor_msgs_msg_JoyFeedbackArray_size_of_topic(const sensor_msgs_msg_JoyFeedbackArray* topic, uint32_t size)
{
    uint32_t previousSize = size;
        size += ucdr_alignment(size, 4) + 4;
        for(size_t i = 0; i < topic->array_size; ++i)
        {
            size += sensor_msgs_msg_JoyFeedback_size_of_topic(&topic->array[i], size);
        }
    return size - previousSize;
}