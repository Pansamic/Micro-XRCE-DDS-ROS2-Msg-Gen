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
 * @file PointCloud2Subscriber.c
 * Subscriber example.
 *
 * This file was generated by the tool microxrceddsgen.
 */

#include "PointCloud2.h"
#include <uxr/client/client.h>
#include <stdio.h>

#define STREAM_HISTORY  8
#define BUFFER_SIZE     UXR_CONFIG_UDP_TRANSPORT_MTU * STREAM_HISTORY


const char* participant_xml = "<dds>"
                                  "<participant>"
                                      "<rtps>"
                                          "<name>default_xrce_participant</name>"
                                      "</rtps>"
                                  "</participant>"
                              "</dds>";
const char* topic_xml = "<dds>"
                            "<topic>"
                                "<name>PointCloud2PubSubTopic</name>"
                                "<dataType>sensor_msgs::msg::PointCloud2</dataType>"
                            "</topic>"
                        "</dds>";
const char* subscriber_xml = "";
const char* datareader_xml = "<dds>"
                                 "<data_reader>"
                                     "<topic>"
                                         "<kind>NO_KEY</kind>"
                                         "<name>PointCloud2PubSubTopic</name>"
                                         "<dataType>sensor_msgs::msg::PointCloud2</dataType>"
                                     "</topic>"
                                 "</data_reader>"
                             "</dds>";

void on_topic(
        uxrSession* session,
        uxrObjectId object_id,
        uint16_t request_id,
        uxrStreamId stream_id,
        struct ucdrBuffer* mb,
        uint16_t length,
        void* args)
{
    (void) session; (void) object_id; (void) request_id; (void) stream_id; (void) length; (void) args;

    sensor_msgs_msg_PointCloud2 topic;
    sensor_msgs_msg_PointCloud2_deserialize_topic(mb, &topic);

    printf("Received topic\n");
}

int main(void)
{
    // Transport
    uxrUDPTransport transport;
    if(!uxr_init_udp_transport(&transport, UXR_IPv4, "127.0.0.1", "2018"))
    {
        printf("Error at create transport.\n");
        return 1;
    }

    // Session
    uxrSession session;
    uxr_init_session(&session, &transport.comm, 0xCCCCDDDD);
    uxr_set_topic_callback(&session, on_topic, NULL);
    if(!uxr_create_session(&session))
    {
        printf("Error at create session.\n");
        return 1;
    }

    // Streams
    uint8_t output_reliable_stream_buffer[BUFFER_SIZE];
    uxrStreamId reliable_out = uxr_create_output_reliable_stream(&session, output_reliable_stream_buffer, BUFFER_SIZE, STREAM_HISTORY);

    uint8_t input_reliable_stream_buffer[BUFFER_SIZE];
    uxrStreamId reliable_in = uxr_create_input_reliable_stream(&session, input_reliable_stream_buffer, BUFFER_SIZE, STREAM_HISTORY);

    // Create entities
    uxrObjectId participant_id = uxr_object_id(0x01, UXR_PARTICIPANT_ID);
    uint16_t participant_req = uxr_buffer_create_participant_xml(&session, reliable_out, participant_id, 0, participant_xml, UXR_REPLACE);

    uxrObjectId topic_id = uxr_object_id(0x01, UXR_TOPIC_ID);
    uint16_t topic_req = uxr_buffer_create_topic_xml(&session, reliable_out, topic_id, participant_id, topic_xml, UXR_REPLACE);

    uxrObjectId subscriber_id = uxr_object_id(0x01, UXR_SUBSCRIBER_ID);
    uint16_t subscriber_req = uxr_buffer_create_subscriber_xml(&session, reliable_out, subscriber_id, participant_id, subscriber_xml, UXR_REPLACE);

    uxrObjectId datareader_id = uxr_object_id(0x01, UXR_DATAREADER_ID);
    uint16_t datareader_req = uxr_buffer_create_datareader_xml(&session, reliable_out, datareader_id, subscriber_id, datareader_xml, UXR_REPLACE);

    // Send create entities message and wait its status
    uint8_t status[4];
    uint16_t requests[4] = {participant_req, topic_req, subscriber_req, datareader_req};
    if(!uxr_run_session_until_all_status(&session, 1000, requests, status, 4))
    {
        printf("Error at create entities: participant: %i topic: %i subscriber: %i datareader: %i\n", status[0], status[1], status[2], status[3]);
        return 1;
    }

    // Request topics
    uxrDeliveryControl delivery_control = {0};
    delivery_control.max_samples = UXR_MAX_SAMPLES_UNLIMITED;
    uint16_t read_data_req = uxr_buffer_request_data(&session, reliable_out, datareader_id, reliable_in, &delivery_control);

    // Read topics
    while(true)
    {
        uint8_t read_data_status;
        (void) uxr_run_session_until_all_status(&session, UXR_TIMEOUT_INF, &read_data_req, &read_data_status, 1);
    }

    // Delete resources
    uxr_delete_session(&session);

    return 0;
}

