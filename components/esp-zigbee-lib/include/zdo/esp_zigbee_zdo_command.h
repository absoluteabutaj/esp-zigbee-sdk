/*
 * SPDX-FileCopyrightText: 2022-2023 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include "esp_zigbee_type.h"
#include "esp_zigbee_zdo_common.h"

/* MATCH DESC REQ ZCL configuration */
#define ESP_ZB_MATCH_DESC_REQ_TIMEOUT              (5 * ESP_ZB_TIME_ONE_SECOND)            /* timeout for finding */
#define ESP_ZB_MATCH_DESC_REQ_ROLE                 ESP_ZB_NWK_BROADCAST_RX_ON_WHEN_IDLE    /* find non-sleep Zigbee device, 0xFFFD */

#define ESP_ZB_IEEE_ADDR_REQ_TIMEOUT                (5 * ESP_ZB_TIME_ONE_SECOND)            /* timeout for ieee address */
#define ESP_ZB_NODE_DESC_REQ_TIMEOUT                (5 * ESP_ZB_TIME_ONE_SECOND)            /* timeout for node descriptor */
#define ESP_ZB_BIND_DEVICE_REQ_TIMEOUT              (5 * ESP_ZB_TIME_ONE_SECOND)            /* timeout for binding */
#define ESP_ZB_ACTIVE_EP_REQ_TIMEOUT                (5 * ESP_ZB_TIME_ONE_SECOND)            /* timeout for active endpoint */
#define ESP_ZB_SIMPLE_DESC_REQ_TIMEOUT              (5 * ESP_ZB_TIME_ONE_SECOND)            /* timeout for simple descriptor */
#define ESP_ZB_PERMIT_JOIN_REQ_TIMEOUT              (5 * ESP_ZB_TIME_ONE_SECOND)            /* timeout for permit join */
#define ESP_ZB_DEVICE_LEAVE_REQ_TIMEOUT             (5 * ESP_ZB_TIME_ONE_SECOND)            /* timeout for device leave */

/** Find device callback
 *
 * @brief A ZDO match desc request callback for user to get response info.
 *
 * @note User's callback get response from the remote device that local node wants to find a particular device on endpoint.
 *
 * @param[in] zdo_status  The ZDO response status, refer to `esp_zb_zdp_status`
 * @param[in] addr  A short address of the device response, 0xFFFF - invalid address
 * @param[in] endpoint An endpoint of the device response, 0xFF - invalid endpoint
 * @param[in] user_ctx  User information context, set in `esp_zb_zdo_find_xxx()`
 *
 */
typedef void (*esp_zb_zdo_match_desc_callback_t)(esp_zb_zdp_status_t zdo_status, uint16_t addr, uint8_t endpoint, void *user_ctx);

/** IEEE address request callback
 *
 * @brief A ZDO ieee address request callback for user to get response info.
 *
 * @note User's callback get response from the remote device that local node wants to get ieee address.
 *
 * @param[in] zdo_status The ZDO response status, refer to `esp_zb_zdp_status`
 * @param[in] ieee_addr  A ieee address of the device response, 0xFFFF FFFF FFFF FFFF - invalid ieee address
 * @param[in] user_ctx  User information context, set in `esp_zb_zdo_ieee_addr_req()`
 *
 */
typedef void (*esp_zb_zdo_ieee_addr_callback_t)(esp_zb_zdp_status_t zdo_status, esp_zb_ieee_addr_t ieee_addr, void *user_ctx);

/** Node descriptor callback
 *
 * @brief A ZDO Node descriptor request callback for user to get node desc info.
 *
 * @note User's callback get response from the remote device that local node wants to get node descriptor response.
 *
 * @param[in] zdo_status    The ZDO response status, refer to `esp_zb_zdp_status`
 * @param[in] addr          A short address of the device response, 0xFFFF - invalid address
 * @param[in] node_desc     A pointer to the node desc @ref esp_zb_af_node_desc_s
 * @param[in] user_ctx  User information context, set in `esp_zb_zdo_node_desc_req()`
 *
 */
typedef void (*esp_zb_zdo_node_desc_callback_t)(esp_zb_zdp_status_t zdo_status, uint16_t addr, esp_zb_af_node_desc_t *node_desc, void *user_ctx);

/** Bind request callback
 *
 * @brief A ZDO bind request callback for user to get response info.
 *
 * @note user's callback get response from the remote device that local node wants to bind.
 *
 * @param[in] zdo_status The ZDO response status, refer to `esp_zb_zdp_status`
 * @param[in] user_ctx  User information context, set in `esp_zb_zdo_device_bind_req()`
 *
 */
typedef void (*esp_zb_zdo_bind_callback_t)(esp_zb_zdp_status_t zdo_status, void *user_ctx);

/** Active endpoint callback
 *
 * @brief A ZDO active endpoint request callback for user to get response info.
 *
 * @note User's callback get response from the remote device that local node wants to get active endpoint.
 *
 * @param[in] zdo_status The ZDO response status, refer to `esp_zb_zdp_status`
 * @param[in] ep_count  A number of active endpoint
 * @param[in] ep_id_list A pointer of the endpoint id list
 * @param[in] user_ctx  User information context, set in `esp_zb_zdo_active_ep_req()`
 *
 */
typedef void (*esp_zb_zdo_active_ep_callback_t)(esp_zb_zdp_status_t zdo_status, uint8_t ep_count, uint8_t *ep_id_list, void *user_ctx);

/** Simple descriptor callback
 *
 * @brief A ZDO simple descriptor request callback for user to get simple desc info.
 *
 * @note User's callback get response from the remote device that local node wants to get simple desc.
 *
 * @param[in] zdo_status The ZDO response status, refer to `esp_zb_zdp_status`
 * @param[in] simple_desc  A pointer to the simple desc @ref esp_zb_af_simple_desc_1_1_s
 * @param[in] user_ctx  User information context, set in `esp_zb_zdo_simple_desc_req()`
 *
 */
typedef void (*esp_zb_zdo_simple_desc_callback_t)(esp_zb_zdp_status_t zdo_status, esp_zb_af_simple_desc_1_1_t *simple_desc, void *user_ctx);

/** Permit join request callback
 *
 * @brief A ZDO permit join request callback for user to get permit join response info.
 *
 * @note User's callback get response from the node requested to permit join.
 *
 * @param[in] zdo_status The ZDO response status, refer to `esp_zb_zdp_status`
 * @param[in] user_ctx  User information context, set in `esp_zb_zdo_permit_joining_req()`
 *
 */
typedef void (*esp_zb_zdo_permit_join_callback_t)(esp_zb_zdp_status_t zdo_status, void *user_ctx);

/** Leave request callback
 *
 * @brief A ZDO leave request callback for user to get leave status.
 *
 * @note User's callback get response from the device that wants to leave.
 *
 * @param[in] zdo_status The ZDO response status, refer to `esp_zb_zdp_status`
 * @param[in] user_ctx  User information context, set in `esp_zb_zdo_device_leave_req()`
 *
 */
typedef void (*esp_zb_zdo_leave_callback_t)(esp_zb_zdp_status_t zdo_status, void *user_ctx);

/**
 * @brief The Zigbee ZDO bind command struct
 *
 * @note Current implementation of the API ONLY supports 64 bit extended address's address mode. Other address mode will support later.
 *
 * @note Be aware of the one req_dst_addr is address that command send to, while dst_address is the destination of the binding entry.
 *
 * @note NOW the dst_addr_mode is default by ZB_BIND_DST_ADDR_MODE_64_BIT_EXTENDED. Later SDK will support other address mode.
 *
 */
typedef struct esp_zb_zdo_bind_req_param_s {
    esp_zb_ieee_addr_t src_address;                     /*!< The IEEE address for the source */
    uint8_t src_endp;                                   /*!< The source endpoint for the binding entry */
    uint16_t cluster_id;                                /*!< The identifier of the cluster on the source device that is bound to the destination */
    uint8_t dst_addr_mode;                              /*!< The destination address mode ref to esp_zb_zdo_bind_dst_addr_mode_t*/
    esp_zb_addr_u dst_address_u;                        /*!< The destination address for the binding entry */
    uint8_t dst_endp;                                   /*!< This field shall be present only if the
                                                         * DstAddrMode field has a value of
                                                         * refer to ZB_BIND_DST_ADDR_MODE_64_BIT_EXTENDED refer to bind_dst_addr_mode
                                                         * and, if present, shall be the
                                                         * destination endpoint for the binding entry. */
    uint16_t req_dst_addr;                              /*!< Destination address of the request send to */
} esp_zb_zdo_bind_req_param_t;

/**
 * @brief The Zigbee ZDO match descrpitor command struct
 */
typedef struct esp_zb_zdo_match_desc_req_param_s {
    uint16_t   dst_nwk_addr;                            /*!< NWK address that request sent to */
    uint16_t   addr_of_interest;                        /*!< NWK address of interest */
} esp_zb_zdo_match_desc_req_param_t;

/**
 * @brief The Zigbee ZDO ieee request command struct
 *
 */
typedef struct esp_zb_zdo_ieee_addr_req_param_s {
    uint16_t   dst_nwk_addr;                            /*!< NWK address that request sent to */
    uint16_t   addr_of_interest;                        /*!< NWK address of interest */
    uint8_t    request_type;                            /*!< Request type for this command: 0x00  Single device response 0x01 Extended response  */
    uint8_t    start_index;                             /*!< If the Request type for this command is Extended response, the StartIndex provides the
                                                         * starting index for the requested elements of the associated devices list */
} esp_zb_zdo_ieee_addr_req_param_t;

/**
 * @brief The Zigbee ZDO node descriptor command struct
 *
 */
typedef struct esp_zb_zdo_node_desc_req_param_s {
    uint16_t    dst_nwk_addr;                           /*!< NWK address that is used for IEEE address mapping.  */
} esp_zb_zdo_node_desc_req_param_t;

/**
 * @brief The Zigbee ZDO simple descriptor command struct
 *
 */
typedef struct esp_zb_zdo_simple_desc_req_param_s {
    uint16_t   addr_of_interest;                        /*!< NWK address of interest */
    uint8_t    endpoint;                                /*!< Endpoint of interest */
} esp_zb_zdo_simple_desc_req_param_t;

/**
 * @brief The Zigbee ZDO active endpoint command struct
 *
 */
typedef struct esp_zb_zdo_active_ep_req_param_s {
    uint16_t   addr_of_interest;                        /*!< NWK address of interest */
} esp_zb_zdo_active_ep_req_param_t;

/**
 * @brief The Zigbee ZDO permit join command struct
 *
 */
typedef struct esp_zb_zdo_permit_joining_req_param_s {
    uint16_t   dst_nwk_addr;                            /*!< NWK address that request sent to */
    uint8_t permit_duration;                            /*!< The length of time in seconds. 0x00 and 0xff indicate that permission is disabled or enabled */
    uint8_t tc_significance;                            /*!< If this is set to 0x01 and the remote device is the Trust Center, the command affects the Trust Center
                                                         * authentication policy as described in the sub-clauses below; If this is set to 0x00, there is no effect
                                                         * on the Trust Center */
} esp_zb_zdo_permit_joining_req_param_t;

/**
 * @brief The Zigbee ZDO leave command struct
 *
 */
typedef struct esp_zb_zdo_mgmt_leave_req_param_s {
    esp_zb_ieee_addr_t device_address;                  /*!< 64-bit IEEE address on device */
    uint16_t   dst_nwk_addr;                            /*!< NWK address that request sent to */
    unsigned int reserved: 6;                           /*!< Reserved */
    unsigned int remove_children: 1;                    /*!< Bitfield of remove children or not */
    unsigned int rejoin: 1;                             /*!< Bitfield of rejoin or not */
} esp_zb_zdo_mgmt_leave_req_param_t;

/********************* Declare functions **************************/
/* ZDO command list, more ZDO command will be supported later like node_desc, power_desc */

/**
 * @brief   Send bind device request command
 *
 * @param[in] cmd_req  Pointer to the bind request command @ref esp_zb_zdo_bind_req_param_s
 * @param[in] user_cb  A user callback that will be called if received bind response refer to esp_zb_zdo_bind_callback_t
 * @param[in] user_ctx A void pointer that contains the user defines additional information when callback trigger
 *
 */
void esp_zb_zdo_device_bind_req(esp_zb_zdo_bind_req_param_t *cmd_req, esp_zb_zdo_bind_callback_t user_cb, void *user_ctx);

/**
 * @brief   Send find on-off device request command
 *
 * @param[in] cmd_req  Pointer to the find request command @ref esp_zb_zdo_match_desc_req_param_s
 * @param[in] user_cb  A user callback that will be called if received find response refer to esp_zb_zdo_match_desc_callback_t
 * @param[in] user_ctx A void pointer that contains the user defines additional information when callback trigger
 *
 */
void esp_zb_zdo_find_on_off_light(esp_zb_zdo_match_desc_req_param_t *cmd_req, esp_zb_zdo_match_desc_callback_t user_cb, void *user_ctx);

/**
 * @brief   Send find color_dimmable device request command
 *
 * @param[in] cmd_req  Pointer to the find request command @ref esp_zb_zdo_match_desc_req_param_s
 * @param[in] user_cb  A user callback that will be called if received find response refer to esp_zb_zdo_match_desc_callback_t
 * @param[in] user_ctx A void pointer that contains the user defines additional information when callback trigger
 *
 */
void esp_zb_zdo_find_color_dimmable_light(esp_zb_zdo_match_desc_req_param_t *cmd_req, esp_zb_zdo_match_desc_callback_t user_cb, void *user_ctx);

/**
 * @brief   Send ieee request command
 *
 * @param[in] cmd_req  Pointer to the ieee address request command @ref esp_zb_zdo_ieee_addr_req_param_s
 * @param[in] user_cb  A user callback that will be called if received ieee address response refer to esp_zb_zdo_ieee_addr_callback_t
 * @param[in] user_ctx A void pointer that contains the user defines additional information when callback trigger
 *
 */
void esp_zb_zdo_ieee_addr_req(esp_zb_zdo_ieee_addr_req_param_t *cmd_req, esp_zb_zdo_ieee_addr_callback_t user_cb, void *user_ctx);

/**
 * @brief   Send node descriptor request command
 *
 * @param[in] cmd_req  Pointer to the node descriptor request command @ref esp_zb_zdo_node_desc_req_param_s
 * @param[in] user_cb  A user callback that will be called if received node desc response refer to esp_zb_zdo_node_desc_callback_t
 * @param[in] user_ctx A void pointer that contains the user defines additional information when callback trigger
 *
 */
void esp_zb_zdo_node_desc_req(esp_zb_zdo_node_desc_req_param_t *cmd_req, esp_zb_zdo_node_desc_callback_t user_cb, void *user_ctx);

/**
 * @brief   Send simple descriptor request command
 *
 * @param[in] cmd_req  Pointer to the simple descriptor request command @ref esp_zb_zdo_simple_desc_req_param_s
 * @param[in] user_cb  A user callback that will be called if received simple desc response refer to esp_zb_zdo_simple_desc_callback_t
 * @param[in] user_ctx A void pointer that contains the user defines additional information when callback trigger
 *
 */
void esp_zb_zdo_simple_desc_req(esp_zb_zdo_simple_desc_req_param_t *cmd_req, esp_zb_zdo_simple_desc_callback_t user_cb, void *user_ctx);

/**
 * @brief   Send active endpoint request command
 *
 * @param[in] cmd_req  Pointer to the active endpoint request command @ref esp_zb_zdo_active_ep_req_param_s
 * @param[in] user_cb  A user callback that will be called if received active ep response refer to esp_zb_zdo_active_ep_callback_t
 * @param[in] user_ctx A void pointer that contains the user defines additional information when callback trigger
 *
 */
void esp_zb_zdo_active_ep_req(esp_zb_zdo_active_ep_req_param_t *cmd_req, esp_zb_zdo_active_ep_callback_t user_cb, void *user_ctx);

/**
 * @brief   Send leave request command
 *
 * @param[in] cmd_req  Pointer to the leave request command @ref esp_zb_zdo_mgmt_leave_req_param_s
 * @param[in] user_cb  A user callback that will be called if received leave response refer to esp_zb_zdo_leave_callback_t
 * @param[in] user_ctx A void pointer that contains the user defines additional information when callback trigger
 *
 */
void esp_zb_zdo_device_leave_req(esp_zb_zdo_mgmt_leave_req_param_t *cmd_req, esp_zb_zdo_leave_callback_t user_cb, void *user_ctx);

/**
 * @brief   Send permit join request command
 *
 * @param[in] cmd_req  Pointer to the permit join request command @ref esp_zb_zdo_permit_joining_req_param_s
 * @param[in] user_cb  A user callback that will be called if received permit join response refer to esp_zb_zdo_permit_join_callback_t
 * @param[in] user_ctx A void pointer that contains the user defines additional information when callback trigger
 *
 */
void esp_zb_zdo_permit_joining_req(esp_zb_zdo_permit_joining_req_param_t *cmd_req, esp_zb_zdo_permit_join_callback_t user_cb, void *user_ctx);

#ifdef __cplusplus
}
#endif
