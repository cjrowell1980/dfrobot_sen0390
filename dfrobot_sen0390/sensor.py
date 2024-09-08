# - namespace:  dfrobot_sen0390
# - class:      DFRobotSEN0930Sensor

import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import i2c, sensor
from esphome.const import (
    CONF_CALCULATED_LUX,
    UNIT_LUX
)

DEPENDENCIES = ["i2c"]

dfrobot_sen0390_ns = cg.esphome_ns.namespace("dfrobot_sen0390")
DFRobotSen0390Sensor = dfrobot_sen0390_ns.class_(
    "SEN0390Sensor", sensor.Sensor, cg.PollingComponent, i2c.I2CDevice
)