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
 * @file Float32MultiArray.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _Float32MultiArray_H_
#define _Float32MultiArray_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <stdbool.h>
#include "MultiArrayLayout.h"

typedef struct std_msgs_msg_Float32MultiArray
{
    std_msgs_msg_MultiArrayLayout layout;
    uint32_t data_size;
    float data[100];

} std_msgs_msg_Float32MultiArray;

struct ucdrBuffer;

bool std_msgs_msg_Float32MultiArray_serialize_topic(struct ucdrBuffer* writer, const std_msgs_msg_Float32MultiArray* topic);
bool std_msgs_msg_Float32MultiArray_deserialize_topic(struct ucdrBuffer* reader, std_msgs_msg_Float32MultiArray* topic);
uint32_t std_msgs_msg_Float32MultiArray_size_of_topic(const std_msgs_msg_Float32MultiArray* topic, uint32_t size);


#ifdef __cplusplus
}
#endif

#endif // _Float32MultiArray_H_