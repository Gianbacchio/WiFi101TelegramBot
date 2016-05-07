/*
  Copyright (c) 2015 Giancarlo Bacchio. All right reserved.

  TelegramBot - Library to create your own Telegram Bot using ARDUINO WiFiShield101.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
  */


#ifndef WiFi101TelegramBot_h
#define WiFi101TelegramBot_h

#include <Arduino.h>
#include <WiFi101.h>

class TelegramBOT
{
  public:
    TelegramBOT (String, String, String);
  	String message[20][6];  // amount of messages read per time  (update_id, name_id, name, lastname, chat_id, text)
  	void begin(void);
  	void analizeMessages(void);
  	void sendMessage(String chat_id, String text, String reply_markup);
  	void getUpdates(String offset);
  private:
    String connectToTelegram(String command);
    String _token;
    String _name;
    String _username;
    WiFiClient client;
};

#endif
