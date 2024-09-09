// - namespace:  dfrobot_sen0390
// - class:      DFRobotSEN0930Sensor

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

		

    } // namespace dfrobot_sen0390
}// namespace esphome