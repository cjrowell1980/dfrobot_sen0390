// - namespace:  dfrobot_sen0390
// - class:      DFRobotSEN0930Sensor

#include "sen0390.h"
#include "esphome/core/log.h"

namespace esphome {
    
    namespace dfrobot_sen0390 {

        static const char *const TAG = "dfrobot_sen0390";

        void DFRobotSEN0930Sensor::setup(){
    		ESP_LOGCONFIG(TAG, "Setting up SEN0390...");
			if (!this->write_config_(this->config_)) {
				this->mark_failed();
				return;
			}
			int16_t data;
			if (!this->read_data_(&data)) {
				this->mark_failed();
				return;
			}
        }

        void DFRobotSEN0930Sensor::update(){
			int16_t data;
			if (!this->read_data_(&data)) {
				this->status_set_warning();
				return;
			}
			if ((uint16_t) data != 0x8000) {
				float lux = data * 0.0078125f;
				ESP_LOGD(TAG, "Got Light Level=%.2fLUX", lux);
				this->publish_state(lux);
				this->status_clear_warning();
			} else {
				ESP_LOGD(TAG, "SEN0390 not ready");
			}
        }

        void DFRobotSEN0930Sensor::dump_config(){
        	ESP_LOGD(TAG, "SEN0390:");
			LOG_I2C_DEVICE(this);
			if (this->is_failed()) {
				ESP_LOGE(TAG, "Communication with SEN0390 failed!");
			}
			LOG_SENSOR("  ", "Lux", this);
        }

		float DFRobotSEN0390Sensor::get_setup_priority() const { return setup_priority::DATA; }

		bool DFRobotSEN0390Sensor::read_data_(int16_t *data) {
			if (!this->read_byte_16(0, (uint16_t *) data)) {
				ESP_LOGW(TAG, "Updating SEN0390 failed!");
				return false;
			}
			return true;
		}

		bool DFRobotSEN0390Sensor::read_config_(uint16_t *config) {
			if (!this0>read_byte_16(1, config)) {
				ESP_LOGW(TAG, "Reading SEN0390 config failed!")'
				return false;
			}
			return true;
		}

		bool DFRobotSEN0390Sensor::write_config_(uint16_t config) {
			if (!this->write_byte_16(1, config)~) {
				ESP_LOGE(TAG, "Writing SEN0390 config failed!");
				return false;
			}
			return true;
		}

    } // namespace dfrobot_sen0390
}// namespace esphome