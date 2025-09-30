#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

// ====== WiFi settings ======
const char *ssid = "YOUR_WIFI_NAME";
const char *password = "YOUR_WIFI_PASSWORD";

// ====== API endpoints ======
const char *registerUrl = "http://192.168.1.100:3000/device/register"; // Replace with your PC IP
const char *dataUrl = "http://192.168.1.100:3000/device/data";
const char *commandsUrl = "http://192.168.1.100:3000/device/commands/esp32_001";

// ====== Device info ======
const char *deviceId = "esp32_001";
const char *deviceName = "Living Room";

// ====== LED pin ======
const int ledPin = 2; // Onboard LED for most ESP32 boards

void setup()
{
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");

  // Register device
  registerDevice();
}

void loop()
{
  // Send fake sensor data every 5 seconds
  sendData(random(20, 30), random(40, 60));

  // Fetch commands from API and execute
  fetchCommands();

  delay(5000);
}

// ====== Functions ======

void registerDevice()
{
  if (WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;
    http.begin(registerUrl);
    http.addHeader("Content-Type", "application/json");

    StaticJsonDocument<200> doc;
    doc["id"] = deviceId;
    doc["name"] = deviceName;

    String requestBody;
    serializeJson(doc, requestBody);

    int code = http.POST(requestBody);
    if (code > 0)
    {
      Serial.println("Device registered: " + http.getString());
    }
    else
    {
      Serial.println("Error registering device: " + String(code));
    }

    http.end();
  }
}

void sendData(float temperature, float humidity)
{
  if (WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;
    http.begin(dataUrl);
    http.addHeader("Content-Type", "application/json");

    StaticJsonDocument<200> doc;
    doc["id"] = deviceId;
    doc["data"]["temperature"] = temperature;
    doc["data"]["humidity"] = humidity;

    String requestBody;
    serializeJson(doc, requestBody);

    int code = http.POST(requestBody);
    if (code > 0)
      Serial.println("Data sent: " + http.getString());
    else
      Serial.println("Error sending data");

    http.end();
  }
}

void fetchCommands()
{
  if (WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;
    http.begin(commandsUrl);

    int code = http.GET();
    if (code > 0)
    {
      String payload = http.getString();
      Serial.println("Commands: " + payload);

      // Parse commands
      StaticJsonDocument<200> doc;
      DeserializationError err = deserializeJson(doc, payload);
      if (!err)
      {
        JsonArray commands = doc["commands"];
        for (JsonVariant cmd : commands)
        {
          executeCommand(cmd.as<String>());
        }
      }
    }
    else
    {
      Serial.println("Error fetching commands");
    }

    http.end();
  }
}

void executeCommand(const String &command)
{
  if (command == "LED_ON")
  {
    digitalWrite(ledPin, HIGH);
    Serial.println("LED turned ON");
  }
  else if (command == "LED_OFF")
  {
    digitalWrite(ledPin, LOW);
    Serial.println("LED turned OFF");
  }
  else
  {
    Serial.println("Unknown command: " + command);
  }
}
