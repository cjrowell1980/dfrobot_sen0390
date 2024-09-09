# - namespace:  dfrobot_sen0390
# - class:      DFRobotSEN0930Sensor

import esphome.codegen as cg
import esphome.config_validation as cv
from esphome import pins
from esphome.components import (
    i2c,
    sensor,
) 
from esphome.const import (
    UNIT_LUX,
    ICON_BRIGHTNESS_5,
    STATE_CLASS_MEASUREMENT,
    CONF_ENABLE_PIN,
)

DEPENDENCIES = ["i2c"]

dfrobot_sen0390_ns = cg.esphome_ns.namespace("dfrobot_sen0390")
DFRobotSen0390Sensor = dfrobot_sen0390_ns.class_(
    "SEN0390Sensor", sensor.Sensor, cg.PollingComponent, i2c.I2CDevice
)

def check_keys(obj):
    if CONF_ENABLE_PIN not in obj:
        msg = "Enable pin needs to be set"
        raise cv.Invlaid(msg)
    return obj

CONFIG_SCHEMA = cv.All(
    sensor.sensor_schema(
        DFRobotSen0390Sensor,
        unit_of_measurement=UNIT_LUX,
        icon=ICON_BRIGHTNESS_5,
        state_class=STATE_CLASS_MEASUREMENT,
    )
    .extend(
        {
            cv.Required(CONF_ENABLE_PIN): pins.gpio_output_pin_schema,
        }
    )
    .extend(cv.polling_component_schema("60s"))
    .extend(i2c.i2c_device_schema(0x29)),
    check_keys,
)

async def to_code(config):
    var = await sensor.new_sensor(config)
    await cg.register_component(var, config)
    enable = await cg.gpio_pin_expression(config[CONF_ENABLE_PIN])
    cg.add(var.set_enable_pin(enable))
    await i2c.register_i2c_device(var, config)