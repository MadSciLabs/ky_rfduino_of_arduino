/*
 Copyright (c) 2013 OpenSourceRF.com.  All right reserved.
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 See the GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

/*
This sketch demonstrates how to do error free bulk data
transfer over Bluetooth Low Energy 4.

The data rate should be approximately:
  - 32 kbit/sec at 1.5ft (4000 bytes per second)
  - 24 kbit/sec at 40ft (3000 bytes per second)
  
This sketch sends a fixed number of 20 byte packets to
an iPhone application.  Each packet is different, so
that the iPhone application can verify if any data or
packets were dropped.
*/

#include <RFduinoBLE.h>

// send 500 20 byte buffers = 10000 bytes
int packets = 500; 

// flag used to start sending
int flag = false;

// variables used in packet generation
int ch;
int packet;
int _count = 0;

int start;

void setup() {
  override_uart_limit = true;
  
  Serial.begin(57600);
  Serial.println("Waiting for connection...");
  RFduinoBLE.begin();
}

void RFduinoBLE_onConnect() {
  packet = 0;
  ch = 'A';
  start = 0;
  flag = true;
  Serial.println("Sending");
  // first send is not possible until the iPhone completes service/characteristic discovery
}

void loop() {

  //Serial.println("Loop");
  
  if (flag)
  {
    // generate the next packet

    _count++;
    if (_count > 5000) {_count = 0;}
  
    //Convert int to 2 byte integer

    /*
    buf[0] = (byte) (_count & 0xFF);
    buf[1] = (byte) ((_count >> 8) & 0xFF);
    buf[2] = '\0';
    */
    
    /*
    for (int i = 0; i < 20; i++)
    {
      buf[i] = ch;
      ch++;
      if (ch > 'Z')
        ch = 'A';
    }
    */

    // send is queued (the ble stack delays send to the start of the next tx window)
    //while (! RFduinoBLE.send(buf, 3))
    //  ;  // all tx buffers in use (can't send - try again later)

    while (! RFduinoBLE.sendInt(0));
    
    while (! RFduinoBLE.sendInt(_count));
    while (! RFduinoBLE.sendInt(_count+10));
    while (! RFduinoBLE.sendInt(_count+20));
    while (! RFduinoBLE.sendInt(_count+30));
    while (! RFduinoBLE.sendInt(_count+40));

    /*
    if (! start)
      start = millis();
    */
    
    /*
    packet++;
    if (packet >= packets)
    {
      int end = millis();
      float secs = (end - start) / 1000.0;
      int bps = ((packets * 20) * 8) / secs; 
      Serial.println("Finished");
      Serial.println(start);
      Serial.println(end);
      Serial.println(secs);
      Serial.println(bps / 1000.0);
      flag = false;
      delay(1000);
      flag = true;
      packet = 0;
    }
    */
 
  }
}

