//==========color command response
void handleCommand() {
  digitalWrite(led, 1);
  String device = server.arg("OutputDevice");
  String command = server.arg("Command");
  String color = checkColor(device,command);
  server.send(200, "text/plain", "Successfully Received Code: [" + command + "]\nColor: [" + color + "]");
   toEP(device,command);
  Serial.println("Handling Command: {" + command + "} For: {" + device + "}...");
  Serial.println("The Led is now: " + color + "!");
  digitalWrite(led, 0);
}
void toEP(String EPname, String EPCommand){

<<<<<<< Updated upstream
  EPname = "http://EPRGB/recieve";
=======
  EPname = "http://192.168.137.191/recieve";
>>>>>>> Stashed changes
      Serial.println("Connecting to " + EPname);
   HTTPClient http;    //Declare object of class HTTPClient
   http.begin(EPname);      //Specify request destination
   http.addHeader("Content-Type", "application/x-www-form-urlencoded");
<<<<<<< Updated upstream
   int httpCode = http.POST("Command"+EPCommand);   //Send the request
   String payload = http.getString();          //Get the response payload
 
=======
   int httpCode = http.POST("Command="+EPCommand);   //Send the request
   String payload = http.getString();          //Get the response payload
   Serial.println("Code from EP");
>>>>>>> Stashed changes
   Serial.println(httpCode);   //Print HTTP return code
   Serial.println(payload);    //Print request response payload
 
   http.end();  //Close connection
  
  
  
  }
