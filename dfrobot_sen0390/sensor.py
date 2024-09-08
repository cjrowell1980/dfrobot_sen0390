# - namespace:  dfrobot_sen0390
# - class:      DFRobotSEN0930Sensor

import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import i2c, sensor
from esphome.const import (
    CONF_CALCULATED_LUX,
    STATE_CLASS_MEASUREMENT,
    DEVICE_CLASS_LUX,
    UNIT_LUX,
)

DEPENDENCIES = ["i2c"]

dfrobot_sen0390_ns = cg.esphome_ns.namespace("dfrobot_sen0390")
DFRobotSen0390Sensor = dfrobot_sen0390_ns.class_(
    "SEN0390Sensor", sensor.Sensor, cg.PollingComponent, i2c.I2CDevice
)

CONFIG_SCHEMA = cv.All(
	sensor.sensor_schema(
    	DFRobotSEN0390Sensor,
        unit_of_measurement=UNIT_LUX,
        device_class=DEVICE_CLASS_LUX,
        state_class=STATE_CLASS_MEASUREMENT,
    )
    .extend(cv.polling_component_schema("60s"))
    .extend(i2c.i2c_device_schema(0x4A))
)

async def to_code(config):
    var = await sensor.new_sensor(config)
    await cg.register_component(var, config)
    await i2c.register_i2c_device(var, config)