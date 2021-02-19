# ESPHome TN9
A ESPHome custom sensor for TN9 Infrared temperature sensor
This library integrates a freetronics TN9 sensor with ESPHome using both the IR temperature sensor and ambient temperature sensor.
It uses the official library available at https://github.com/freetronics/IRTemp as a dependency.

# Setup
1. Put the file `tn9.h` into the same directory as your `.yaml` file for ESPHome. On HomeAssistant this is the path `config/esphome/tn9.h`
2. Update your `.yaml` file to include the custom sensor's file. This means adding a `includes` section under `esphome:` in the `.yaml` file. For example the top of my configuration file looks like:
  ```
  esphome:
    name: livingroom
    platform: ESP32
    board: esp-wrover-kit
    includes:
      - tn9.h
  ```
3. Configure the sensor in your `.yaml` file. You can change the name of the sensors if you want. This is how they will show up in ESPHome (and on your HomeAssistant dashboard if you are using HomeAssistant)
  ```
  sensor:
    - platform: custom
      lambda: |-
        auto temp_sensor = new IRTempSensor();
        App.register_component(temp_sensor);
        return {temp_sensor->ambient_sensor, temp_sensor->ir_sensor};
      sensors:
        - name: "Ambient Temperature"
          unit_of_measurement: '°C'
          accuracy_decimals: 2
        - name: "Infrared Temperature"
          unit_of_measurement: '°C'
          accuracy_decimals: 2
  ```
4. Put the IRTemp library files in the appropriate directory. You will need to clone https://github.com/freetronics/IRTemp and put `IRTemp.cpp` and `IRTemp.h` into the `src` folder of your ESPHome configuration. For example, my sample configuration named "livingroom" configured through HomeAssistant would need the files put into the path `config/esphome/livingroom/src`
5. Upload the new configuration to your ESPHome device. You're done, that's it !
