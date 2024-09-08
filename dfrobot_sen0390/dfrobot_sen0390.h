// - namespace:  dfrobot_sen0390
// - class:      DFRobotSEN0930Sensor

#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/i2c/i2c.h"

namespace esphome {
    namespace dfrobot_sen0390 {

        class DFRobotSEN0930Sensor : public sensor::Sensor, public PollingComponent, public i2c::I2CDevice {
            public:
            void setup() override;
            void update() override;
            void dump_config() override;
        };

    }  // namespace dfrobot_sen0390
}  // namespace esphome
