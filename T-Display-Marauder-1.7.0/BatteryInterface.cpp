#include "BatteryInterface.h"
#include "lang_var.h"

#include <driver/adc.h>  // Added for MARAUDER_TTGO_TDISPLAY
#include "esp_adc_cal.h" // Added for MARAUDER_TTGO_TDISPLAY
BatteryInterface::BatteryInterface() {
  
}

void BatteryInterface::main(uint32_t currentTime) {
  if (currentTime != 0) {
    if (currentTime - initTime >= 3000) {
      //Serial.println("Checking Battery Level");
      this->initTime = millis();
      int8_t new_level = this->getBatteryLevel();
      //this->battery_level = this->getBatteryLevel();
      if (this->battery_level != new_level) {
        Serial.println(text00 + (String)new_level);
        this->battery_level = new_level;
        Serial.println("Battery Level: " + (String)this->battery_level);
      }
    }
  }
}

void BatteryInterface::RunSetup() {
  byte error;
  byte addr;

  #ifdef HAS_BATTERY

    Wire.begin(I2C_SDA, I2C_SCL);

    Serial.println("Checking for battery monitors...");

    Wire.beginTransmission(IP5306_ADDR);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.println("Detected IP5306");
      this->has_ip5306 = true;
      this->i2c_supported = true;
    }

    Wire.beginTransmission(MAX17048_ADDR);
    error = Wire.endTransmission();

    if (error == 0) {
      if (maxlipo.begin()) {
        Serial.println("Detected MAX17048");
        this->has_max17048 = true;
        this->i2c_supported = true;
      }
    }

    /*for(addr = 1; addr < 127; addr++ ) {
      Wire.beginTransmission(addr);
      error = Wire.endTransmission();

      if (error == 0)
      {
        Serial.print("I2C device found at address 0x");
        
        if (addr<16)
          Serial.print("0");

        Serial.println(addr,HEX);
        
        if (addr == IP5306_ADDR) {
          this->has_ip5306 = true;
          this->i2c_supported = true;
        }

        if (addr == MAX17048_ADDR) {
          if (maxlipo.begin()) {
            Serial.println("Detected MAX17048");
            this->has_max17048 = true;
            this->i2c_supported = true;
          }
        }
      }
    }*/

    /*if (this->maxlipo.begin()) {
      Serial.println("Detected MAX17048");
      this->has_max17048 = true;
      this->i2c_supported = true;
    }*/

    #ifdef MARAUDER_TTGO_TDISPLAY
      adc1_config_width(ADC_WIDTH_BIT_12);
      adc1_config_channel_atten(ADC1_CHANNEL_6, ADC_ATTEN_DB_11);  // GPIO 34
      esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_12, 1100, &adc_chars);
    #endif
    
    this->initTime = millis();
  #endif
}

int8_t BatteryInterface::getBatteryLevel() {

  if (this->has_ip5306) {
    Wire.beginTransmission(IP5306_ADDR);
    Wire.write(0x78);
    if (Wire.endTransmission(false) == 0 &&
        Wire.requestFrom(IP5306_ADDR, 1)) {
      this->i2c_supported = true;
      switch (Wire.read() & 0xF0) {
        case 0xE0: return 25;
        case 0xC0: return 50;
        case 0x80: return 75;
        case 0x00: return 100;
        default: return 0;
      }
    }
    this->i2c_supported = false;
    return -1;
  }


  if (this->has_max17048) {
    float percent = this->maxlipo.cellPercent();

    // Sometimes we dumb
    if (percent >= 100)
      return 100;
    else if (percent <= 0)
      return 0;
    else
      return percent;
  }

  #ifdef MARAUDER_TTGO_TDISPLAY  
    float voltage = readBatteryVoltage();
    Serial.print("Battery voltage read: ");
    Serial.println(voltage); // <-- Added this for confirmation

    if (voltage >= 4.1) return 100;
    else if (voltage >= 3.95) return 75;
    else if (voltage >= 3.8) return 50;
    else if (voltage >= 3.6) return 25;
    else return 0;
  #endif

  return -1;
}

#ifdef MARAUDER_TTGO_TDISPLAY
float BatteryInterface::readBatteryVoltage() {
  uint32_t raw = 0;
  const int samples = 20;

  for (int i = 0; i < samples; i++) {
    raw += adc1_get_raw(ADC1_CHANNEL_6);  // GPIO 34
    delay(2);
  }

  raw /= samples;
  uint32_t voltage_mv = esp_adc_cal_raw_to_voltage(raw, &adc_chars);  // calibrated mV
  float battery_voltage = (voltage_mv / 1000.0) * 2.02;  // Adjust last number as needed

  Serial.print("Raw ADC: ");
  Serial.println(raw);
  Serial.print("Calibrated voltage: ");
  Serial.print(battery_voltage);
  Serial.println(" V");

  return battery_voltage;
}
#endif
