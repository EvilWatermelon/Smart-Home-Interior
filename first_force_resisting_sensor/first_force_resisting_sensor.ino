#include <ESP8266WiFi.h> // Enables the ESP8266 to connect to the local network (via WiFi)
#include <PubSubClient.h>

const int pin = A0;
int forceReading;

const char* ssid = "AndroidAP3D04";
const char* pw = "cwhb2400";
const char* mqtt_server = "192.168.43.17";
const char* sensor_name = "forceSensitive";

WiFiClient espClient;
PubSubClient client(espClient);
long lastmsg = 0;
char msg[50];
int value = 0;


void setup_wifi(){
    delay(100);
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, pw);
    while (WiFi.status() != WL_CONNECTED)
    {
      delay(500);
      Serial.print(".");
    }
      
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
 
    if (client.connect(sensor_name)){
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 6 seconds");
      // Wait 6 seconds before retrying
      delay(6000);
    }
  }
}
void setup() {
  pinMode(pin, INPUT);
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);

  if (!client.connected()) {
    reconnect();
  }
  
  client.loop();
 
}

void loop(){
  forceReading = analogRead(pin);

  String msg = "";
  char reader[25];

  if(forceReading >= 15) {
    msg = "Besetzt";
  } else {
    msg = "Nicht besetzt";
  }
  
  //msg = forceReading;
  msg.toCharArray(reader, 25);
  
  client.publish("forceReader1", reader);
  delay(200);
}
