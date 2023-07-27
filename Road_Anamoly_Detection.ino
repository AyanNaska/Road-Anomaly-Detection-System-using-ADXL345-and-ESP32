#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>

// Replace with your WiFi credentials
const char* ssid = "Your_WiFi_SSID";
const char* password = "Your_WiFi_Password";

// ThingSpeak parameters
const char* server = "api.thingspeak.com";
const char* api_key = "Your_ThingSpeak_API_Key";
const int update_interval = 15000; // 15 seconds interval for updating ThingSpeak (adjust as needed)

// Initialize the ADXL345 sensor
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    delay(100);
  }

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");

  // Initialize the ADXL345 sensor
  if (!accel.begin()) {
    Serial.println("Could not find a valid ADXL345 sensor, check wiring!");
    while (1);
  }

  // Connect to ThingSpeak
  ThingSpeak.begin(client);
}

void loop() {
  // Read acceleration data
  sensors_event_t event;
  accel.getEvent(&event);
  
  // Check for jerks - you can adjust the threshold based on your requirements
  float jerkThreshold = 5.0; // Its the threshold
  float total_jerk = sqrt(pow(event.acceleration.x, 2) + pow(event.acceleration.y, 2) + pow(event.acceleration.z, 2));
  
  // Print the total jerk for debugging purposes
  Serial.print("Total Jerk: ");
  Serial.println(total_jerk);

  // If jerk exceeds the threshold, send data to ThingSpeak
  if (total_jerk > jerkThreshold) {
    // Send data to ThingSpeak
    int field_value = total_jerk; // You can change this to any other value or additional data you want to send
    ThingSpeak.writeField(YOUR_CHANNEL_ID, 1, field_value, YOUR_API_KEY);
    
    Serial.println("Data sent to ThingSpeak");
  }

  delay(update_interval);
}
