/*
 * Copyright (c) 2020, RudyLo <luhuadong@163.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-02-01     luhuadong    the first version
 */

#ifndef __SGP30_H__
#define __SGP30_H__

#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>

#define SGP30LIB_VERSION               "1.0.0"

/* SGP30 i2c address 0x58 */
#define SGP30_I2CADDR                  PKG_USING_SGP30_I2C_ADDRESS

/* Custom sensor control cmd types */
#define  RT_SENSOR_CTRL_GET_BASELINE   (0x110)   /* Get device id */
#define  RT_SENSOR_CTRL_SET_BASELINE   (0x111)   /* Set the measure range of sensor. unit is info of sensor */
#define  RT_SENSOR_CTRL_SET_HUMIDITY   (0x112)   /* Set output date rate. unit is HZ */

#if defined(RT_VERSION_CHECK)
    #if (RTTHREAD_VERSION >= RT_VERSION_CHECK(5, 0, 2))
        #define RT_SIZE_TYPE   rt_ssize_t
    #else
        #define RT_SIZE_TYPE   rt_size_t
    #endif
#endif

struct sgp30_baseline
{
    rt_uint16_t eco2_base;
    rt_uint16_t tvoc_base;
};

struct sgp30_device
{
	struct rt_i2c_bus_device *i2c;

	rt_uint16_t TVOC;
	rt_uint16_t eCO2;
	rt_uint16_t rawH2;
	rt_uint16_t rawEthanol;
	rt_uint16_t serialnumber[3];

	rt_bool_t   is_ready;
	rt_mutex_t  lock;
};
typedef struct sgp30_device *sgp30_device_t;


rt_err_t       sgp30_init(struct sgp30_device *dev, const char *i2c_bus_name);
sgp30_device_t sgp30_create(const char *i2c_bus_name);
void           sgp30_delete(sgp30_device_t dev);

rt_bool_t sgp30_measure(sgp30_device_t dev);
rt_bool_t sgp30_measure_raw(sgp30_device_t dev);

rt_bool_t sgp30_get_baseline(sgp30_device_t dev, rt_uint16_t *eco2_base, rt_uint16_t *tvoc_base);
rt_bool_t sgp30_set_baseline(sgp30_device_t dev, rt_uint16_t eco2_base, rt_uint16_t tvoc_base);
rt_bool_t sgp30_set_humidity(sgp30_device_t dev, rt_uint32_t absolute_humidity);


rt_err_t rt_hw_sgp30_init(const char *name, struct rt_sensor_config *cfg);

#endif /* __SGP30_H__ */