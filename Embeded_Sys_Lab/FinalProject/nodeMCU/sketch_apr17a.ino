#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <Firebase_ESP_Client.h>
#include <ArduinoJson.h>

EspSoftwareSerial::UART testSerial;

// WiFi credentials
const char* ssid = "everyday_space_user";
const char* password = "XGWN7rrg";

// Firebase Credentials
#define FIREBASE_HOST "your-project-id.firebaseio.com"
#define FIREBASE_AUTH "YourFirebaseAuthToken"
#define COLLECTION_NAME = "dataFromNodeMCU"

// Define the Firebase Data object
FirebaseData fbdo;

// Define the FirebaseAuth data for authentication data
FirebaseAuth auth;

// Define the FirebaseConfig data for config data
FirebaseConfig config;

// Assign the project host and api key 
config.host = FIREBASE_HOST;
config.api_key = API_KEY;

config.signer.test_mode = true;

// Assign the user sign in credentials
auth.user.email = USER_EMAIL;
auth.user.password = USER_PASSWORD;

// Optional, set AP reconnection in setup()
// Firebase.reconnectWiFi(true);

// Optional, set number of error retry
// Firebase.RTDB.setMaxRetry(&fbdo, 3);

// Optional, set number of error resumable queues
// Firebase.RTDB.setMaxErrorQueue(&fbdo, 30);

// Optional, use classic HTTP GET and POST requests.
// This option allows get and delete functions (PUT and DELETE HTTP requests) works for
// device connected behind the Firewall that allows only GET and POST requests.
// Firebase.RTDB.enableClassicRequest(&fbdo, true);

// #if defined(ESP8266)
// Optional, set the size of BearSSL WiFi to receive and transmit buffers
// Firebase may not support the data transfer fragmentation, you may need to reserve the buffer to match
// the data to transport.
// fbdo.setBSSLBufferSize(1024, 1024); // minimum size is 512 bytes, maximum size is 16384 bytes
// #endif


// Optional, set the size of HTTP response buffer
// Prevent out of memory for large payload but data may be truncated and can't determine its type.
// fbdo.setResponseSize(1024); // minimum size is 1024 bytes

void setup() {
  Serial.begin(9600);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  testSerial.begin(115200, EspSoftwareSerial::SWSERIAL_8N1, D7, D8, false, 95, 11);
  
  // Initialize the library with the Firebase authen and config.
  Firebase.begin(&config, &auth);
}
char buffer[10];
void loop() {
  // Your code here
  if(testSerial.available() > 0){
    int cnt = 0;
    while(cnt != 12){
      while(testSerial.available() > 0){
        buffer[cnt++] = testSerial.read();
        // Serial.print("Received: ");
        // Serial.println(receivedData);
        // Serial.println(buffer[cnt-1]);
      }
    }
    buffer[cnt] = NULL;
    Serial.println(buffer);

    //Send data to firebase
    // Prepare data to send
    int value = 0;
    for(int i=1;i<3;i++){
      value*=10;
      value+=buffer[i]-'0';
    }
    jsonBuffer.clear();
    jsonBuffer.add("TDS_Value", value);
    String json;
    jsonBuffer.toString(json);

    // Send data to Firebase
    Firebase.setString(firebaseData, "/" + collectionName, json);

    if (firebaseData.dataAvailable()) {
      if (firebaseData.dataType() == "string") {
        Serial.print("Data sent to Firebase: ");
        Serial.println(firebaseData.stringData());
      }
    }

    // Delay before sending the next data
    delay(2000);
  }

}
