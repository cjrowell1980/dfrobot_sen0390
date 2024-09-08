# example configuration
# LTR_ALS_PS AS SIMILAR ITEM

sensor:
  - platform: dfrobot_sen0390
    id: dfrobot_sen0390_lux_sensor
    name: DFRobot I2c Lux Sensor
    enable_pin: GPIO10

i2c:
  sda: GPIO0
  scl: GPIO1
  id: i2c_bus_0
  scan: true