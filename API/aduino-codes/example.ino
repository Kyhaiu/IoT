#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "DHT.h"

// ====== DHT settings ======
#define DHTPIN 4      // Pino de dados do DHT11
#define DHTTYPE DHT11 // Tipo do sensor
DHT dht(DHTPIN, DHTTYPE);

// ====== WiFi settings ======
const char *ssid = "YOUR_WIFI_NAME";
const char *password = "YOUR_WIFI_PASSWORD";

// ====== API endpoints ======
const char *registerUrl = "http://192.168.1.100:3000/device/register";
const char *dataUrl = "http://192.168.1.100:3000/device/data";
const char *commandsUrl = "http://192.168.1.100:3000/device/commands/esp32_001";

// ====== Device info ======
const char *deviceId = "esp32_001";
const char *deviceName = "ESP32_DHT11";

// ====== LED pin ======
const int ledPin = 2;

void setup()
{
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  dht.begin();

  WiFi.begin(ssid, password);
  Serial.print("Conectando ao WiFi");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado.");
  registerDevice();
}

void loop()
{
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity))
  {
    Serial.println("Falha na leitura do sensor!");
  }
  else
  {
    sendData(temperature, humidity);
    fetchCommands();
  }

  delay(5000);
}

// ==================== FUNÇÕES ====================

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

    String body;
    serializeJson(doc, body);

    int code = http.POST(body);
    if (code > 0)
    {
      Serial.println("Dispositivo Registrado: " + http.getString());
    }
    else
    {
      Serial.println("Erro ao registrar o dispositivo: " + String(code));
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

    String body;
    serializeJson(doc, body);

    int code = http.POST(body);
    if (code > 0)
    {
      Serial.println("Dados enviados: " + http.getString());
    }
    else
    {
      Serial.println("Erro ao enviar os dados: " + String(code));
    }

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

      StaticJsonDocument<200> doc;
      if (deserializeJson(doc, payload) == DeserializationError::Ok)
      {
        JsonArray cmds = doc["commands"];
        for (JsonVariant cmd : cmds)
        {
          executeCommand(cmd.as<String>());
        }
      }
    }
    else
    {
      Serial.println("Erro ao buscar os comandos: " + String(code));
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
