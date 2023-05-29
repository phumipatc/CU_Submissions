#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

EspSoftwareSerial::UART testSerial;

// WiFi credentials
const char* ssid = "no internet";
const char* password = "nointernet";

// Set your Firebase project's unique identifier
const char* firebaseHost = "embbeded-final-project-w-ecb5a-default-rtdb.asia-southeast1.firebasedatabase.app";

// Set your Firebase project's authentication credentials
const char* firebaseAuth = "jxLZrZjcQk7PCl4d1haju3DTsFcvi0iGaps1ZfnK";

// Create an instance of the Firebase Data object
FirebaseData firebaseData;

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
  
  // Initialize Firebase
  Firebase.begin(firebaseHost, firebaseAuth);
}
char buffer[20];
int cnt = 0;
void loop() {
  if(cnt == 12){
    buffer[cnt] = NULL;
    Serial.println(buffer);
    cnt = 0;

    int TDS_Value = 0;
    for(int i=1;i<=3;i++){
      TDS_Value*=10;
      TDS_Value+=buffer[i]-'0';
    }

    float Thermo_Value = 0;
    for(int i=5;i<=7;i++){
      Thermo_Value*=10;
      Thermo_Value+=buffer[i]-'0';
    }
    Thermo_Value/=10;

    int DissolvedO2_Value = 0;
    for(int i=9;i<=11;i++){
      DissolvedO2_Value*=10;
      DissolvedO2_Value+=buffer[i]-'0';
    }

    // Send the data to Firestore
    if (Firebase.setInt(firebaseData, "/TDS_Value", TDS_Value)) {
      Serial.println("TDS_Value sent to Firestore successfully");
    } else {
      Serial.println("Failed to send data to Firestore");
      Serial.println(firebaseData.errorReason());
    }
    if (Firebase.setFloat(firebaseData, "/Thermo_Value", Thermo_Value)) {
      Serial.println("Thermo_Value sent to Firestore successfully");
    } else {
      Serial.println("Failed to send data to Firestore");
      Serial.println(firebaseData.errorReason());
    }
    if (Firebase.setInt(firebaseData, "/DissolvedO2_Value", DissolvedO2_Value)) {
      Serial.println("DissolvedO2_Value sent to Firestore successfully");
    } else {
      Serial.println("Failed to send data to Firestore");
      Serial.println(firebaseData.errorReason());
    }

    testSerial.write("1");
    // Delay before sending the next data
    // delay(5000);
  }

  if(testSerial.available() > 0){
    buffer[cnt++] = testSerial.read();
    if(buffer[cnt-1] == 'A'){
      buffer[0] = 'A';
      cnt = 1;
    }
    // Serial.print("Received: ");
    // Serial.println(buffer[cnt-1]);
  }
}