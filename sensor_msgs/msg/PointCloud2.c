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
 * @file PointCloud2.c
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#include "sensor_msgs/msg/PointCloud2.h"

#include <ucdr/microcdr.h>
#include <string.h>

bool sensor_msgs_msg_PointCloud2_serialize_topic(ucdrBuffer* writer, const sensor_msgs_msg_PointCloud2* topic)
{
    bool success = true;

        success &= std_msgs_msg_Header_serialize_topic(writer, &topic->header);
        success &= ucdr_serialize_uint32_t(writer, topic->height);

        success &= ucdr_serialize_uint32_t(writer, topic->width);

        success &= ucdr_serialize_uint32_t(writer, topic->fields_size);
        for(size_t i = 0; i < topic->fields_size; ++i)
        {
            success &= sensor_msgs_msg_PointField_serialize_topic(writer, &topic->fields[i]);
        }

        success &= ucdr_serialize_bool(writer, topic->is_bigendian);

        success &= ucdr_serialize_uint32_t(writer, topic->point_step);

        success &= ucdr_serialize_uint32_t(writer, topic->row_step);

        success &= ucdr_serialize_sequence_uint8_t(writer, topic->data, topic->data_size);

        success &= ucdr_serialize_bool(writer, topic->is_dense);

    return success && !writer->error;
}

bool sensor_msgs_msg_PointCloud2_deserialize_topic(ucdrBuffer* reader, sensor_msgs_msg_PointCloud2* topic)
{
    bool success = true;

        success &= std_msgs_msg_Header_deserialize_topic(reader, &topic->header);
        success &= ucdr_deserialize_uint32_t(reader, &topic->height);

        success &= ucdr_deserialize_uint32_t(reader, &topic->width);

        success &= ucdr_deserialize_uint32_t(reader, &topic->fields_size);
        if(topic->fields_size > 100)
        {
            reader->error = true;
        }
        else
        {
            for(size_t i = 0; i < topic->fields_size; ++i)
            {
                success &= sensor_msgs_msg_PointField_deserialize_topic(reader, &topic->fields[i]);
            }
        }

        success &= ucdr_deserialize_bool(reader, &topic->is_bigendian);

        success &= ucdr_deserialize_uint32_t(reader, &topic->point_step);

        success &= ucdr_deserialize_uint32_t(reader, &topic->row_step);

        success &= ucdr_deserialize_sequence_uint8_t(reader, topic->data, 100, &topic->data_size);

        success &= ucdr_deserialize_bool(reader, &topic->is_dense);

    return success && !reader->error;
}

uint32_t sensor_msgs_msg_PointCloud2_size_of_topic(const sensor_msgs_msg_PointCloud2* topic, uint32_t size)
{
    uint32_t previousSize = size;
        size += std_msgs_msg_Header_size_of_topic(&topic->header, size);
        size += ucdr_alignment(size, 4) + 4;

        size += ucdr_alignment(size, 4) + 4;

        size += ucdr_alignment(size, 4) + 4;
        for(size_t i = 0; i < topic->fields_size; ++i)
        {
            size += sensor_msgs_msg_PointField_size_of_topic(&topic->fields[i], size);
        }

        size += ucdr_alignment(size, 1) + 1;

        size += ucdr_alignment(size, 4) + 4;

        size += ucdr_alignment(size, 4) + 4;

        size += ucdr_alignment(size, 4) + 4;
        size += ucdr_alignment(size, 1) + topic->data_size * 1;

        size += ucdr_alignment(size, 1) + 1;

    return size - previousSize;
}