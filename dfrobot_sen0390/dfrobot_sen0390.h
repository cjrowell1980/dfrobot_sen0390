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
                void dump_config() override;
                float get_setup_priority() const override;
                void update() override;
                void set_config(uint16_t config) { config_ = config; };
                
            protected:
            	bool read_data_(int16_t *data);
                bool read_config_(uint16_t *config);
                bool write_config(uint16_t config);
                
                uint16_t config_;
                
        };

    }  // namespace dfrobot_sen0390
}  // namespace esphome
