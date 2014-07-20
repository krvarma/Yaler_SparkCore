#include "application.h"

const char* _host = "try.yaler.net";
const char* _id = "<<yalerid>>";
const uint16_t _port = 80;

void sendResponse(TCPClient client) {
    client.println("HTTP/1.1 200 OK");
    client.println("Connection: close");
    client.println("Content-Length: 39");
    client.println("Hello, Spark Core and Yaler is awesome!");

    delay(1000);

    client.flush();
    client.stop();
}

TCPClient available()
{
    TCPClient client;
    boolean received = false;

    int x[16];

    Serial.println("connecting...");

    if (client.connect(_host, _port)) {
        Serial.println("connected");

        do {
            Serial.println("sending request...");

            client.print("POST /");
            client.print(_id);
            client.print(" HTTP/1.1\r\n");
            client.print("Upgrade: PTTH/1.0\r\n");
            client.print("Connection: Upgrade\r\n");
            client.print("Host: ");
            client.print(_host);
            client.print("\r\n\r\n");

            Serial.println("receiving response...");

            boolean timeout = false;

            int count = -32500;

            while (!timeout && !client.available()) {
                delay(1);
                if (count == 32500) { // 75000 ms
                    timeout = true;

                    Serial.print("timeout!");
                }

                count++;
            }



            if(!timeout){
                int index = 0;

                while(client.available()){
                    x[index % 16] = client.read();

                    Serial.print((char)x[index % 16]);

                    ++index;
                }

                client.flush();

                Serial.print((char)x[9]);
                Serial.print((char)x[10]);
                Serial.print((char)x[11]);

                if(x[9] == '2' && x[10] == '0' && x[11] == '4'){
                    Serial.println("No Content.");
                }
                else{
                    received = true;
                }
            }

            Serial.println();

            if(!received){
                delay(1000);
            }
        } while (!received);
    }

    return client;
}

void setup() {
    Serial.begin(9600);
}

void loop() {
    TCPClient client = available();

    if(client && client.connected()){
        Serial.print("Sending response to the client...");
        sendResponse(client);

        Serial.print("Done.");
        Serial.println();
    }

    delay(1000);
}
