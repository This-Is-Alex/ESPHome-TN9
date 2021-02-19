#include "esphome.h"
#include "IRTemp.h"

#define PIN_DATA 15
#define PIN_CLOCK 4
#define PIN_AQUIRE 2
#define SCALE CELSIUS
#define POLL_RATE 9000

class IRTempSensor : public PollingComponent, public Sensor {
 public:
  IRTemp *irTemp = new IRTemp(PIN_AQUIRE, PIN_CLOCK, PIN_DATA);
  Sensor *ambient_sensor = new Sensor();
  Sensor *ir_sensor = new Sensor();
  
  IRTempSensor() : PollingComponent(POLL_RATE) {}

  void setup() override {
    
  }
  void update() override {
    float ambientTemperature = irTemp->getAmbientTemperature(SCALE);
    float irTemperature = irTemp->getIRTemperature(SCALE);
    ambient_sensor->publish_state(ambientTemperature);
    ir_sensor->publish_state(irTemperature);
  }
};
