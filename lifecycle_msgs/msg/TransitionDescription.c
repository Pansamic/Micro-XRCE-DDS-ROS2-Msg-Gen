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
 * @file TransitionDescription.c
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#include "lifecycle_msgs/msg/TransitionDescription.h"

#include <ucdr/microcdr.h>
#include <string.h>

bool lifecycle_msgs_msg_TransitionDescription_serialize_topic(ucdrBuffer* writer, const lifecycle_msgs_msg_TransitionDescription* topic)
{
    bool success = true;

        success &= lifecycle_msgs_msg_Transition_serialize_topic(writer, &topic->transition);
        success &= lifecycle_msgs_msg_State_serialize_topic(writer, &topic->start_state);
        success &= lifecycle_msgs_msg_State_serialize_topic(writer, &topic->goal_state);
    return success && !writer->error;
}

bool lifecycle_msgs_msg_TransitionDescription_deserialize_topic(ucdrBuffer* reader, lifecycle_msgs_msg_TransitionDescription* topic)
{
    bool success = true;

        success &= lifecycle_msgs_msg_Transition_deserialize_topic(reader, &topic->transition);
        success &= lifecycle_msgs_msg_State_deserialize_topic(reader, &topic->start_state);
        success &= lifecycle_msgs_msg_State_deserialize_topic(reader, &topic->goal_state);
    return success && !reader->error;
}

uint32_t lifecycle_msgs_msg_TransitionDescription_size_of_topic(const lifecycle_msgs_msg_TransitionDescription* topic, uint32_t size)
{
    uint32_t previousSize = size;
        size += lifecycle_msgs_msg_Transition_size_of_topic(&topic->transition, size);
        size += lifecycle_msgs_msg_State_size_of_topic(&topic->start_state, size);
        size += lifecycle_msgs_msg_State_size_of_topic(&topic->goal_state, size);
    return size - previousSize;
}