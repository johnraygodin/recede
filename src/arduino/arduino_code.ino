
#include <BLEDevice.h>
#include <WiFi.h>
#include<HTTPClient.h>

const char* ssid = "Recede";
const char* password = "09870987";
const char* serverName = "http://192.168.30.57/albert.php"; //"http://192.168.30.57/jellie.php"; //"http://192.168.30.57/catherine.php"; //  

String deviceName;
const int pin = 5;
int secondsCount1, secondsCount2, secondsCount3 = 0;
int awayCount1, awayCount2, awayCount3 = 0;

String value = "";
String value1 = "Catherine G. Duero | BSIT-4A | 09508716087";
String value2 = "Jellie Marie J. Jover | BSIT-4A | 09927203982";
String value3 = "Albert S. Parreño | BSIT-4A | 09567000352";


int cutOff = -52;
int rssi;
String dot = "";
////////////////////////////////////////////////////////////////////
BLEServer* server;

#define SERVICE_UUID1 "4fafc201-1fb5-459e-8fcc-c5c9c331914a" //declaration of service uuids to advertise (server side, suppose to be)
#define SERVICE_UUID2 "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define SERVICE_UUID3 "4fafc201-1fb5-459e-8fcc-c5c9c331914c"
////////////////////////////////////////////////////////////////////

BLEUUID serviceUUID1("4fafc201-1fb5-459e-8fcc-c5c9c331914a"); //declaration of known service uuids to scan (client side, suppose to be)
BLEUUID serviceUUID2("4fafc201-1fb5-459e-8fcc-c5c9c331914b");
BLEUUID serviceUUID3("4fafc201-1fb5-459e-8fcc-c5c9c331914c");

BLEScan* scan;
BLEClient* pClient;

BLEAdvertisedDevice device;


void setup() {
  Serial.begin(115200);
  pinMode(pin,OUTPUT);
  Serial.println("Scanning...");
  BLEDevice::init("Recede3");       //Per ESP, we change the .php file, BLE advertising name,and the advertised UUID
  
  server = BLEDevice::createServer();
  BLEAdvertising* advertising = BLEDevice::getAdvertising();
  advertising->addServiceUUID(SERVICE_UUID3);
  BLEDevice::startAdvertising();
}

void loop() {

  scan = BLEDevice::getScan();
  scan->setActiveScan(true);
  BLEScanResults results = scan->start(1);
  
  for(int i = 0; i < results.getCount(); i = i + 1){
    device = results.getDevice(i);
    rssi = device.getRSSI();
  
    /*Serial.println("RSSI Value is: ");
    Serial.println(rssi);*/
  
    deviceName = (device.getName().c_str());
    
/////////////////////////////////////////////////////////////////////////

      if(device.isAdvertisingService(serviceUUID1) && rssi > cutOff){
        digitalWrite(pin,HIGH);
        delay(500); //Delay between loops
        secondsCount1 = secondsCount1 + 1;
        Serial.print("Recede 1's Count: ");
        Serial.println(secondsCount1);
        
        if(secondsCount1 == 10){
          Serial.print("The value of value1 is: ");
          Serial.println(value1);
          
          //if (value1 != ""){
            
            Serial.print("We have uploaded ");
            Serial.print(value1);
            Serial.print(" to the database.");
            
            Serial.print("Uploading to the Database" );
            WiFi.begin(ssid, password);
            Serial.print("Connecting to " );
            Serial.println(ssid);
            
            while(WiFi.status() != WL_CONNECTED){
              delay(1000);
              Serial.print(dot);
              dot = dot + ".";
              
              if(dot == "....."){
                Serial.print("//////////RESTARTING WIFI//////////");
                Serial.print("Uploading to the Database " );
                WiFi.begin(ssid, password);
                Serial.print("Connecting to " );
                Serial.println(ssid);
                dot = "";
              }
            }//while
                Serial.println("");
                Serial.print("Connected to WiFi network with IP Address: ");
                Serial.println(WiFi.localIP());
                
                if(WiFi.status()== WL_CONNECTED){
                  HTTPClient http;
                  
                  http.begin(serverName);
                  
                  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

                  value = value1;
                  String httpRequestData =  "&value= " + value;
                  Serial.print("httpRequestData: ");
                  Serial.println(httpRequestData);
                
                  int httpResponseCode = http.POST(httpRequestData);
                
                  if (httpResponseCode > 0){
                    Serial.print("HTTP Response code: ");
                    Serial.println(httpResponseCode);
                  }
                  else{
                    Serial.print("Error code: ");
                    Serial.println(httpResponseCode);
                  }
                  http.end();
                  
                }//wifi status
                else{
                  Serial.println("WiFi Disconnected");
                }

                WiFi.disconnect();
                
                dot = "";
                value = "";
                awayCount1 = 0;
                secondsCount1 = 0;
          
          //}//if value
              
        }//secondscount
        if(secondsCount1 > 10){
          secondsCount1 = 10;//if the countdown exceeds 10, return count to 9
        }
      }// if device name && rssi > cutOff
          
      if(device.isAdvertisingService(serviceUUID1) && rssi < cutOff){
        digitalWrite(pin,LOW);
        delay(500); //Delay between loops
        awayCount1 = awayCount1 + 1;
        Serial.print("Recede 1's Away Count: ");
        Serial.println(awayCount1);
          if(awayCount1 == 3){//3 seconds of being away
            
            secondsCount1 = 0;
            awayCount1 = 0;
            
          }  
      }// if device name && rssi < cutOff
      else{
        digitalWrite(pin,LOW);
      }// else
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

      if(device.isAdvertisingService(serviceUUID2) && rssi > cutOff){
        digitalWrite(pin,HIGH);
        delay(500); //Delay between loops
        secondsCount2 = secondsCount2 + 1;
        Serial.print("Recede 2's Seconds Count: ");
        Serial.println(secondsCount2);
        
        if(secondsCount2 == 10){
          
          Serial.print("The value of value2 is: ");
          Serial.println(value2);
          
          //if (value2 != ""){
            
            Serial.print("We have uploaded ");
            Serial.print(value2);
            Serial.print(" to the database.");
            
            Serial.print("Uploading to the Database " );
            WiFi.begin(ssid, password);
            Serial.print("Connecting to " );
            Serial.println(ssid);
            
            while(WiFi.status() != WL_CONNECTED){
              delay(1000);
              Serial.print(dot);
              dot = dot + ".";
              
              if(dot == "....."){
                Serial.print("//////////RESTARTING WIFI//////////");
                Serial.print("Uploading to the Database " );
                WiFi.begin(ssid, password);
                Serial.print("Connecting to " );
                Serial.println(ssid);
                dot = "";
              }
            }//while
                Serial.println("");
                Serial.print("Connected to WiFi network with IP Address: ");
                Serial.println(WiFi.localIP());
                
                if(WiFi.status()== WL_CONNECTED){
                  HTTPClient http;
                  
                  http.begin(serverName);
                  
                  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

                  value = value2;
                  String httpRequestData =  "&value= " + value;
                  Serial.print("httpRequestData: ");
                  Serial.println(httpRequestData);
                
                  int httpResponseCode = http.POST(httpRequestData);
                
                  if (httpResponseCode > 0){
                    Serial.print("HTTP Response code: ");
                    Serial.println(httpResponseCode);
                  }
                  else{
                    Serial.print("Error code: ");
                    Serial.println(httpResponseCode);
                  }
                  http.end();
                  
                }//wifi status
                else{
                  Serial.println("WiFi Disconnected");
                }
                
                WiFi.disconnect();
                
                dot = "";
                value = "";
                awayCount2 = 0;
                secondsCount2 = 0;
          
          //}//if value
              
        }//secondscount
        if(secondsCount2 > 10){
          secondsCount2 = 10;//if the countdown exceeds 10, return count to 9
        }
      }// if device name && rssi > cutOff
          
      if(device.isAdvertisingService(serviceUUID2) && rssi < cutOff){
        digitalWrite(pin,LOW);
        delay(500); //Delay between loops
        awayCount2 = awayCount2 + 1;
        Serial.print("Recede 2's Away Count: ");
        Serial.println(awayCount2);
          if(awayCount2 == 2){//3 seconds of being away
            
            secondsCount2 = 0;
            awayCount2 = 0;
            
          }  
      }// if device name && rssi < cutOff
      else{
        digitalWrite(pin,LOW);
      }// else
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

      if(device.isAdvertisingService(serviceUUID3) && rssi > cutOff){
        digitalWrite(pin,HIGH);
        delay(500); //Delay between loops
        secondsCount3 = secondsCount3 + 1;
        Serial.print("Recede 3's Seconds Count: ");
        Serial.println(secondsCount3);
        
        if(secondsCount3 == 10){
          
          Serial.print("The value of value3 is: ");
          Serial.println(value3);
          
          //if (value3 != ""){
            
            Serial.print("We have uploaded ");
            Serial.print(value3);
            Serial.print(" to the database.");
            
            Serial.print("Uploading to the Database " );
            WiFi.begin(ssid, password);
            Serial.print("Connecting to " );
            Serial.println(ssid);
            
            while(WiFi.status() != WL_CONNECTED){
              delay(1000);
              Serial.print(dot);
              dot = dot + ".";
              
              if(dot == "....."){
                Serial.print("//////////RESTARTING WIFI//////////");
                Serial.print("Uploading to the Database " );
                WiFi.begin(ssid, password);
                Serial.print("Connecting to " );
                Serial.println(ssid);
                dot = "";
              }
            }//while
                Serial.println("");
                Serial.print("Connected to WiFi network with IP Address: ");
                Serial.println(WiFi.localIP());
                
                if(WiFi.status()== WL_CONNECTED){
                  HTTPClient http;
                  
                  http.begin(serverName);
                  
                  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

                  value = value3;
                  String httpRequestData =  "&value= " + value;
                  Serial.print("httpRequestData: ");
                  Serial.println(httpRequestData);
                
                  int httpResponseCode = http.POST(httpRequestData);
                
                  if (httpResponseCode > 0){
                    Serial.print("HTTP Response code: ");
                    Serial.println(httpResponseCode);
                  }
                  else{
                    Serial.print("Error code: ");
                    Serial.println(httpResponseCode);
                  }
                  http.end();
                  
                }//wifi status
                else{
                  Serial.println("WiFi Disconnected");
                }

               WiFi.disconnect();
               
                dot = "";
                value = "";
                awayCount3 = 0;
                secondsCount3 = 0;
          
          //}//if value
              
        }//secondscount
        if(secondsCount3 > 10){
          secondsCount3 = 10;//if the countdown exceeds 10, return count to 9
        }
      }// if device name && rssi > cutOff
          
      if(device.isAdvertisingService(serviceUUID3) && rssi < cutOff){
        digitalWrite(pin,LOW);
        delay(500); //Delay between loops
        awayCount3 = awayCount3 + 1;
        Serial.print("Recede 3's Away Count: ");
        Serial.println(awayCount3);
          if(awayCount3 == 3){//3 seconds of being away
            
            secondsCount3 = 0;
            awayCount3 = 0;
            
          }  
      }// if device name && rssi < cutOff
      else{
        digitalWrite(pin,LOW);
      }// else
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
      
  }//for loop

  scan->clearResults();
  Serial.println("/////////////////SCANNING/////////////////");
}//void loop
