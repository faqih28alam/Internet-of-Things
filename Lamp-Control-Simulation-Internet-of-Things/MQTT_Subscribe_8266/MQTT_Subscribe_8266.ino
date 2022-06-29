#include <AntaresESP8266MQTT.h>     // Inisiasi library MQTT Antares

#define ACCESSKEY "f7e014c81dd014ee:e8a270226e1134a5"       // Ganti dengan access key akun Antares anda
#define WIFISSID "kuntul"         // Ganti dengan SSID WiFi anda
#define PASSWORD "syalalala"     // Ganti dengan password WiFi anda

#define applicationName "Uhuy"   // Ganti dengan application name Antares yang telah dibuat
#define deviceName "Ultrasonik"     // Ganti dengan device Antares yang telah dibuat

const int relay1 = 4; //D1
const int relay2 = 5; //D2
const int relay3 = 2; //D4
const int relay4 = 14; //D5
const int relay5 = 12; //D6

AntaresESP8266MQTT antares(ACCESSKEY);    // Buat objek antares

/*
  Fungsi utama untuk mendapatkan topik dan payload dari setiap
  pesan MQTT yang diterima oleh ESP8266.
*/
void callback(char topic[], byte payload[], unsigned int length) {

  antares.get(topic, payload, length);  // Menyimpan topic dan payload ke penampungan data sementara

  Serial.println("New Message!");
  Serial.println("Topic: " + antares.getTopic());     // Print topic
  Serial.println("Payload: " + antares.getPayload()); // Print payload

  // Print data-data yang telah didapatkan
 `Serial.println("Room 1: " + antares.getString("Room 1"));
  Serial.println("Room 2: " + antares.getString("Room 2"));  
  Serial.println("Room 3: " + antares.getString("Room 3"));  
  Serial.println("Room 4: " + antares.getString("Room 4"));  
  Serial.println("Room 5: " + antares.getString("Room 5"));
}

void setup() {
  Serial.begin(115200);     // Buka komunikasi serial dengan baudrate 115200
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(relay5, OUTPUT);
  
  antares.setDebug(true);   // Nyalakan debug. Set menjadi "false" jika tidak ingin pesan-pesan tampil di serial monitor
  antares.wifiConnection(WIFISSID,PASSWORD);  // Mencoba untuk menyambungkan ke WiFi
  antares.setMqttServer();  // Inisiasi server MQTT Antares
  antares.setCallback(callback);  // Set fungsi callback menjadi fungsi callback seperti di atas
}
void loop() {
  /*
    Cek koneksi ke broker MQTT Antares. Jika disconnect,
    akan dicoba untuk menyambungkan lagi
   */
  antares.checkMqttConnection();
 String stat1 = antares.getString("Room 1");
  String stat2 = antares.getString("Room 2");
  String stat3 = antares.getString("Room 3");
  String stat4 = antares.getString("Room 4");
  String stat5 = antares.getString("Room 5");
  delay(1000);
  
        if(stat1=="Nyala"){
          digitalWrite(relay1, LOW);
          Serial.println("Lampu 1 Nyala");
        }
          if(stat1=="Mati"){
          digitalWrite(relay1, HIGH);
          Serial.println("Lampu 1 Mati");
        }
          if(stat2=="Nyala"){
          digitalWrite(relay2, LOW);
          Serial.println("Lampu 2 Nyala");
        }
         if(stat2=="Mati"){
          digitalWrite(relay2, HIGH);
          Serial.println("Lampu 2 Mati");
        }
          if(stat3=="Nyala"){
          digitalWrite(relay3, LOW);
          Serial.println("Lampu 3 Nyala");
        }
        if(stat3=="Mati"){
          digitalWrite(relay3, HIGH);
          Serial.println("Lampu 3 Mati");
        }
          if(stat4=="Nyala"){
          digitalWrite(relay4, LOW);
          Serial.println("Lampu 4 Nyala");
        }
        if(stat4=="Mati"){
          digitalWrite(relay4, HIGH);
          Serial.println("Lampu 4 Mati");
        }
          if(stat5=="Nyala"){
          digitalWrite(relay5, LOW);
          Serial.println("Lampu 5 Nyala");
        }
        if(stat5=="Mati"){
          digitalWrite(relay5, HIGH);
          Serial.println("Lampu 5 Mati");
        }
     delay(1000);   
}
