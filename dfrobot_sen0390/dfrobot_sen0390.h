// - namespace:  dfrobot_sen0390
// - class:      DFRobotSEN0390Sensor

#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/i2c/i2c.h"

namespace esphome {
    namespace dfrobot_sen0390 {

        struct {
            uint8_t TIM :3;
            uint8_t CDR :1;
            uint8_t BIT_4 :1;
            uint8_t BIT_5 :1;
            uint8_t MANUAL :1;
            uint8_t BIT_7 :1;
        }__attribute__((packed)) sLightConfig_t;        

        enum eManualMode {
            eAutomatic = 0<<6, // default
            eManual = 1<<6,
        };

        enum eCDRMode {
            eCDR_0 = 0<<3,
            eCDR_1 = 1<<3,
        };

        enum eTimeMode {
            eTime800ms = 0,
            eTime400ms = 1,
            eTime200ms = 2,
            eTime100ms = 3,
            eTime50ms = 4,
            eTime25ms = 5,
            eTime12_5ms = 6,
            eTime6_25ms = 7,
        };

        class DFRobotSEN0390Sensor : public sensor::Sensor, public PollingComponent, public i2c::I2CDevice {
            public:
                float get_setup_priority() const override { return setup_priority::DATA; }
            	void setup() override;
                void dump_config() override;
                void update() override;
                
                void set_acquisition_mode(eManualMode manual_mode) { this->manual_mode_ = manual_mode; }
                void set_cdr_mode(eCdrMode cdr_mode) { this->cdr_mode_ = cdr_mode; }
                void set_acquisition_time(eTimeMode time_mode) { this->time_mode_ = time_mode; }

            protected:
                eManualMode manual_mode_;
                eCdrMode cdr_mode_;
                eTimeMode time_mode_;
        };

    }  // namespace dfrobot_sen0390
}  // namespace esphome
