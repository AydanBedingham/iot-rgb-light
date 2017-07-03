#include <Ethernet.h>
#include <PubSubClient.h>

const char* mqtt_client_name = "Light1Client"; //Unique Identifier
const char* mqtt_server = "m11.cloudmqtt.com";
const int mqtt_port = 12806;
const char* mqtt_user = "LightSubscriber";
const char* mqtt_pass = "<PASSWORD>";
const char* mqtt_topic = "Light1";

byte mac[] = {
  0xAE, 0xAD, 0xAE, 0xAE, 0xFE, 0xEE
};

EthernetClient ethClient;

void callback(char* topic, byte* payload, unsigned int length);
PubSubClient client(mqtt_server, mqtt_port, callback, ethClient);

void setup() {
  Serial.begin(9600);
  while (!Serial) { ;} 

  Serial.println("Started");
  setupLight();
  setLightColorYellow();
}



void processCommand(String command){
  Serial.print("Executing command:");
  Serial.println(command);
  
  if (command.equals("setLightColorRed")){ setLightColorRed(); }
  else if (command.equals("setLightColorBlue")){ setLightColorBlue(); }
  else if (command.equals("setLightColorGreen")){ setLightColorGreen(); } 
  else if (command.equals("setLightColorNone")){ setLightColorNone(); }
  else if (command.equals("setLightColorOrange")){ setLightColorOrange(); }
  else if (command.equals("setLightColorYellow")){ setLightColorYellow(); } 
  else if (command.equals("setLightColorTeal")){ setLightColorTeal(); }
}


void callback(char* topic, byte* payload, unsigned int length) {  
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("]: ");
  String payloadStr = "";
  for (int i=0;i<length;i++) {
    payloadStr += (char)payload[i];
  }
  Serial.println(payloadStr);
  
  processCommand(payloadStr);
}

void loop() {
  if (validateConnection()==false){
    setLightColorYellow();
  }
  client.loop();
}


bool validateConnection(){

  if (client.connected()==false){
    
    //Connect/Reconnect to network if necessary
    bool networkAvailable = validateNetworkConnection();

    if (networkAvailable){

      //Connect/Reconnect to MQTT Broker      
      if (connectToMQTTServer(mqtt_client_name, mqtt_user, mqtt_pass)==true){
        client.subscribe(mqtt_topic);
        setLightColorNone();
        
        return true;
      } else{
        return false;
      }
    } else{
      return false;
    }
    
  } else{
    return true;    
  }
}


bool connectToMQTTServer(const char* id, const char* user, const char* pass){
  if (client.connected()==true) { client.disconnect(); }
  
  Serial.println("Connecting to MQTT Broker...");
  if (client.connect(id, user, pass)) {
    Serial.println("Connected to MQTT Broker.");
    return true;
  } else{
    Serial.println("Failed to connect to MQTT Broker.");
    return false;
  }
}


bool wasConnectedToNetwork = false;
bool validateNetworkConnection(){
  Serial.println("Validating network status...");
  
  if (wasConnectedToNetwork==false){
    Serial.println("Connecting to network...");
  }
  
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to connect to network!");
    wasConnectedToNetwork = false;
  } else{
    if (wasConnectedToNetwork==false){
      Serial.print("Obtained IP Address: ");
      Serial.println(Ethernet.localIP());
    }
    Serial.println("Successfully validated network status.");
    wasConnectedToNetwork = true;
  }
  return wasConnectedToNetwork;
}

