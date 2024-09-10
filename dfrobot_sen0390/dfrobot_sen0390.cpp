// - namespace:  dfrobot_sen0390
// - class:      DFRobotSEN0390Sensor

#include "sen0390.h"
#include "esphome/core/log.h"

namespace esphome {
    
    namespace dfrobot_sen0390 {

        static const char *const TAG = "dfrobot_sen0390";

		bool DFRobotSEN0390Sensor::enable_pin_setup_complete = false;

		void DFRobotSEN0390Sensor::dump_config() {
			LOG_SENSOR("", "DFRobot_SEN0390", this);
			LOG_I2C_DEVICE(this);
			LOG_PIN("  Enable Pin: ", this->enable_pin_);
		}

		void DFRobotSEN0390Sensor::setup() {
			ESP_LOGD(TAG, "'%s' - setup BEGIN", this->name_.c_str());
			if (!esphome::dfrobot_sen0390::enable_pin_setup_complete) {
				if (dfrobot_sen0390->enable_pin)
			}
		}

    } // namespace dfrobot_sen0390
}// namespace esphome