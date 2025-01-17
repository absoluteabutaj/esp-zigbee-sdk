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
#include "zcl/esp_zigbee_zcl_common.h"
/**
 * @brief  Create an empty attribute list.
 *
 * @note  This attribute list is ready for certain cluster id to add / update attribute refer to esp_zb_xx_cluster_add_attr() and esp_zb_cluster_update_attr().
 * @note  Attribute list groups up a cluster.
 *
 * @param[in] cluster_id The cluster id for attribute list refer to esp_zb_zcl_cluster_id
 *
 * @return pointer to  @ref esp_zb_attribute_list_s
 *
 */
esp_zb_attribute_list_t *esp_zb_zcl_attr_list_create(uint16_t cluster_id);

/**
 * @brief  Get ZCL attribute descriptor.
 *
 * @note  Getting the local attribute from the specific endpoint and cluster.
 *
 * @param[in] endpoint The endpoint
 * @param[in] cluster_id Cluster id for attribute list refer to esp_zb_zcl_cluster_id
 * @param[in] cluster_role Cluster role of this cluster, either server or client role refer to esp_zb_zcl_cluster_role
 * @param[in] attr_id Attribute id
 *
 * @return pointer to  @ref esp_zb_zcl_attr_s
 *
 */
esp_zb_zcl_attr_t *esp_zb_zcl_get_attribute(uint8_t endpoint, uint16_t cluster_id, uint8_t cluster_role, uint16_t attr_id);

/**
 * @brief  Set ZCL attribute value.
 *
 * @note  Set the local attribute from the specific endpoint, cluster and attribute.
 *
 * @param[in] endpoint The endpoint
 * @param[in] cluster_id Cluster id for attribute list refer to esp_zb_zcl_cluster_id
 * @param[in] cluster_role Cluster role of this cluster, either server or client role refer to esp_zb_zcl_cluster_role
 * @param[in] attr_id Attribute id
 * @param[in] value_p pointer to new value

 * @note It will force write the attribute value even if it's read-only.
 * @return zcl status refer to esp_zb_zcl_status_t
 *
 */
esp_zb_zcl_status_t esp_zb_zcl_set_attribute_val(uint8_t endpoint, uint16_t cluster_id, uint8_t cluster_role,
        uint16_t attr_id, void *value_p);

/**
 * @brief Add an attribute in basic cluster.
 *
 * @param[in] attr_list A pointer to attribute list @ref esp_zb_attribute_list_s
 * @param[in] attr_id  An attribute id to be added
 * @param[in] value_p A pointer to attribute value wants to add
 *
 * @return
 *      - ESP_OK on success
 *      - ESP_ERR_INVALID_ARG if attribute is existed or unsupported
 *
 */
esp_err_t esp_zb_basic_cluster_add_attr(esp_zb_attribute_list_t *attr_list, uint16_t attr_id, void *value_p);

/**
 * @brief Add an attribute in power config cluster.
 *
 * @param[in] attr_list A pointer to attribute list @ref esp_zb_attribute_list_s
 * @param[in] attr_id  An attribute id to be added
 * @param[in] value_p A pointer to attribute value wants to add
 * @note Attribute for battery information, battery settings 2 and 3 sets haven't supported yet.
 * @return
 *      - ESP_OK on success
 *      - ESP_ERR_INVALID_ARG if attribute is existed or unsupported
 *
 */
esp_err_t esp_zb_power_config_cluster_add_attr(esp_zb_attribute_list_t *attr_list, uint16_t attr_id, void *value_p);

/**
 * @brief Add an attribute in identify cluster.
 *
 * @param[in] attr_list A pointer to attribute list @ref esp_zb_attribute_list_s
 * @param[in] attr_id  An attribute id to be added
 * @param[in] value_p A pointer to attribute value wants to add
 *
 * @return
 *      - ESP_OK on success
 *      - ESP_ERR_INVALID_ARG if attribute is existed or unsupported
 *
 */
esp_err_t esp_zb_identify_cluster_add_attr(esp_zb_attribute_list_t *attr_list, uint16_t attr_id, void *value_p);

/**
 * @brief Add an attribute in groups cluster.
 *
 * @param[in] attr_list A pointer to attribute list @ref esp_zb_attribute_list_s
 * @param[in] attr_id  An attribute id to be added
 * @param[in] value_p A pointer to attribute value wants to add
 *
 * @return
 *      - ESP_OK on success
 *      - ESP_ERR_INVALID_ARG if attribute is existed or unsupported
 *
 */
esp_err_t esp_zb_groups_cluster_add_attr(esp_zb_attribute_list_t *attr_list, uint16_t attr_id, void *value_p);

/**
 * @brief Add an attribute in scenes cluster.
 *
 * @param[in] attr_list A pointer to attribute list @ref esp_zb_attribute_list_s
 * @param[in] attr_id  An attribute id to be added
 * @param[in] value_p A pointer to attribute value wants to add
 *
 * @return
 *      - ESP_OK on success
 *      - ESP_ERR_INVALID_ARG if attribute is existed or unsupported
 *
 */
esp_err_t esp_zb_scenes_cluster_add_attr(esp_zb_attribute_list_t *attr_list, uint16_t attr_id, void *value_p);

/**
 * @brief Add an attribute in on_off cluster.
 *
 * @param[in] attr_list A pointer to attribute list @ref esp_zb_attribute_list_s
 * @param[in] attr_id  An attribute id to be added
 * @param[in] value_p A pointer to attribute value wants to add
 *
 * @return
 *      - ESP_OK on success
 *      - ESP_ERR_INVALID_ARG if attribute is existed or unsupported
 *
 */
esp_err_t esp_zb_on_off_cluster_add_attr(esp_zb_attribute_list_t *attr_list, uint16_t attr_id, void *value_p);

/**
 * @brief Add an attribute in on_off switch config cluster.
 *
 * @param[in] attr_list A pointer to attribute list @ref esp_zb_attribute_list_s
 * @param[in] attr_id  An attribute id to be added
 * @param[in] value_p A pointer to attribute value wants to add
 *
 * @return
 *      - ESP_OK on success
 *      - ESP_ERR_INVALID_ARG if attribute is existed or unsupported
 *
 */
esp_err_t esp_zb_on_off_switch_config_cluster_add_attr(esp_zb_attribute_list_t *attr_list, uint16_t attr_id, void *value_p);

/**
 * @brief Add an attribute in level cluster.
 *
 * @param[in] attr_list A pointer to attribute list @ref esp_zb_attribute_list_s
 * @param[in] attr_id  An attribute id to be added
 * @param[in] value_p A pointer to attribute value wants to add
 *
 * @return
 *      - ESP_OK on success
 *      - ESP_ERR_INVALID_ARG if attribute is existed or unsupported
 *
 */
esp_err_t esp_zb_level_cluster_add_attr(esp_zb_attribute_list_t *attr_list, uint16_t attr_id, void *value_p);

/**
 * @brief Add an attribute in color control cluster.
 *
 * @param[in] attr_list A pointer to attribute list @ref esp_zb_attribute_list_s
 * @param[in] attr_id  An attribute id to be added
 * @param[in] value_p A pointer to attribute value wants to add
 *
 * @return
 *      - ESP_OK on success
 *      - ESP_ERR_INVALID_ARG if attribute is existed or unsupported
 *
 */
esp_err_t esp_zb_color_control_cluster_add_attr(esp_zb_attribute_list_t *attr_list, uint16_t attr_id, void *value_p);

/**
 * @brief Add an attribute in time cluster.
 *
 * @param[in] attr_list A pointer to attribute list @ref esp_zb_attribute_list_s
 * @param[in] attr_id  An attribute id to be added
 * @param[in] value_p A pointer to attribute value wants to add
 *
 * @return
 *      - ESP_OK on success
 *      - ESP_ERR_INVALID_ARG if attribute is existed or unsupported
 *
 */
esp_err_t esp_zb_time_cluster_add_attr(esp_zb_attribute_list_t *attr_list, uint16_t attr_id, void *value_p);

/**
 * @brief Add an attribute in binary input cluster.
 *
 * @param[in] attr_list A pointer to attribute list @ref esp_zb_attribute_list_s
 * @param[in] attr_id  An attribute id to be added
 * @param[in] value_p A pointer to attribute value wants to add
 *
 * @return
 *      - ESP_OK on success
 *      - ESP_ERR_INVALID_ARG if attribute is existed or unsupported
 *
 */
esp_err_t esp_zb_binary_input_cluster_add_attr(esp_zb_attribute_list_t *attr_list, uint16_t attr_id, void *value_p);

/**
 * @brief Add an attribute in shade config cluster.
 *
 * @param[in] attr_list A pointer to attribute list @ref esp_zb_attribute_list_s
 * @param[in] attr_id  An attribute id to be added
 * @param[in] value_p A pointer to attribute value wants to add
 *
 * @return
 *      - ESP_OK on success
 *      - ESP_ERR_INVALID_ARG if attribute is existed or unsupported
 *
 */
esp_err_t esp_zb_shade_config_cluster_add_attr(esp_zb_attribute_list_t *attr_list, uint16_t attr_id, void *value_p);

/**
 * @brief Add an attribute in door lock cluster.
 *
 * @param[in] attr_list A pointer to attribute list @ref esp_zb_attribute_list_s
 * @param[in] attr_id  An attribute id to be added
 * @param[in] value_p A pointer to attribute value wants to add
 *
 * @return
 *      - ESP_OK on success
 *      - ESP_ERR_INVALID_ARG if attribute is existed or unsupported
 *
 */
esp_err_t esp_zb_door_lock_cluster_add_attr(esp_zb_attribute_list_t *attr_list, uint16_t attr_id, void *value_p);

/**
 * @brief Add an attribute in IAS zone cluster.
 *
 * @param[in] attr_list A pointer to attribute list @ref esp_zb_attribute_list_s
 * @param[in] attr_id  An attribute id to be added
 * @param[in] value_p A pointer to attribute value wants to add
 *
 * @return
 *      - ESP_OK on success
 *      - ESP_ERR_INVALID_ARG if attribute is existed or unsupported
 *
 */
esp_err_t esp_zb_ias_zone_cluster_add_attr(esp_zb_attribute_list_t *attr_list, uint16_t attr_id, void *value_p);

/**
 * @brief Add an attribute in temperature measurement cluster.
 *
 * @param[in] attr_list A pointer to attribute list @ref esp_zb_attribute_list_s
 * @param[in] attr_id  An attribute id to be added
 * @param[in] value_p A pointer to attribute value wants to add
 *
 * @return
 *      - ESP_OK on success
 *      - ESP_ERR_INVALID_ARG if attribute is existed or unsupported
 *
 */
esp_err_t esp_zb_temperature_meas_cluster_add_attr(esp_zb_attribute_list_t *attr_list, uint16_t attr_id, void *value_p);

/**
 * @brief Add an attribute in humidity measurement cluster.
 *
 * @param[in] attr_list A pointer to attribute list @ref esp_zb_attribute_list_s
 * @param[in] attr_id  An attribute id to be added
 * @param[in] value_p A pointer to attribute value wants to add
 *
 * @return
 *      - ESP_OK on success
 *      - ESP_ERR_INVALID_ARG if attribute is existed or unsupported
 *
 */
esp_err_t esp_zb_humidity_meas_cluster_add_attr(esp_zb_attribute_list_t *attr_list, uint16_t attr_id, void *value_p);

/**
 * @brief Add an attribute and variables in OTA client cluster.
 *
 * @param[in] attr_list A pointer to attribute list @ref esp_zb_attribute_list_s
 * @param[in] attr_id  An attribute id to be added
 * @param[in] value_p A pointer to attribute value wants to add
 *
 * @return
 *      - ESP_OK on success
 *      - ESP_ERR_INVALID_ARG if attribute is existed or unsupported
 *
 */
esp_err_t esp_zb_ota_cluster_add_attr(esp_zb_attribute_list_t *attr_list, uint16_t attr_id, void *value_p);

/**
* @brief Add customized attribute in customized cluster.
*
* @param[in] attr_list A pointer to attribute list @ref esp_zb_attribute_list_s
* @param[in] attr_id An attribute id to be added
* @param[in] attr_type Type of attribute to be added refer to esp_zb_zcl_attr_type
* @param[in] attr_access Access type of attribute to be added
* @param[in] value_p A pointer to attribute value wants to add
*
* @return
* - ESP_OK on success
* - ESP_ERR_INVALID_ARG if attribute is existed or unsupported
*
*/
esp_err_t esp_zb_custom_cluster_add_custom_attr(esp_zb_attribute_list_t *attr_list, uint16_t attr_id, uint8_t attr_type, uint8_t attr_access, void *value_p);

/**
 * @brief Update an attribute in a specific cluster.
 *
 * @param[in] attr_list A pointer to attribute list @ref esp_zb_attribute_list_s
 * @param[in] attr_id  An attribute id which wants to update
 * @param[in] value_p A pointer to attribute value wants to update
 *
 * @return
 *      - ESP_OK on success
 *      - ESP_ERR_INVALID_ARG if attribute list not initialized
 *      - ESP_ERR_NOT_FOUND the request update attribute is not found
 *
 */
esp_err_t esp_zb_cluster_update_attr(esp_zb_attribute_list_t *attr_list, uint16_t attr_id, void *value_p);

#ifdef __cplusplus
}
#endif
