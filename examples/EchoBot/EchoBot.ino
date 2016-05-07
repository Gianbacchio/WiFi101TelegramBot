/*******************************************************************
 *  this is a basic example how to program a Telegram Bot          *
 *  using TelegramBOT library on Arduino Zero and WiFiSchield101   *
 *                                                                 *
 *  Open a conversation with the bot, it will echo your messages   *
 *                                                                 *
 *  written by Giacarlo Bacchio                                    *
 *******************************************************************/

#include <WiFi101.h>
#include <SPI.h>
#include <TelegramBOT.h>


// Initialize Wifi connection to the router
char ssid[] = "yyyyyyyyyyyyyyyyyyy";              // your network SSID (name)
char pass[] = "xxxxxxxxxxxx";                              // your network key
int status = WL_IDLE_STATUS;


// Initialize Telegram BOT
#define BOTtoken "77330665:AAEIHv4RJxPnygoKD8nZqLnlpmd4hq7iR7s"  //token of EchoBOT
#define BOTname "EchoBot"
#define BOTusername "EchoBot_bot"
TelegramBOT bot(BOTtoken, BOTname, BOTusername);

int Bot_mtbs = 1000; //mean time between scan messages
long Bot_lasttime;   //last time messages' scan has been done


/********************************************
 * EchoMessages - function to Echo messages *
 ********************************************/
void Bot_EchoMessages() {

  for (int i = 1; i < bot.message[0][0].toInt() + 1; i++)      {
    bot.sendMessage(bot.message[i][4], bot.message[i][5], "");
  }
  bot.message[0][0] = "";   // All messages have been replied - reset new messages
}



void setup() {

  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  delay(3000);
  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue:
    while (true);
  }
  // attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);

  bot.begin();      // launch Bot functionalities
}



void loop() {

  if (millis() > Bot_lasttime + Bot_mtbs)  {
    bot.getUpdates(bot.message[0][1]);   // launch API GetUpdates up to xxx message
    Bot_EchoMessages();   // reply to message with Echo
    Bot_lasttime = millis();
  }
}






