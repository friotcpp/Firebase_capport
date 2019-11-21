//=================check color function========//
String checkColor(String device, String command)
{
  String error_color = "error";
  int color_num = strtol( command.c_str(), NULL, 2 ); //convert string to int in base 2;
  if (device == Device1)
  {
    digitalWrite(2, int(command[0])-'0'); //change string to int with ascii correction
    digitalWrite(0, int(command[1])-'0');
    digitalWrite(4, int(command[2])-'0'); 
    digitalWrite(5, int(command[3])-'0');
    //===Firebase update===//
    Firebase.setString(firebaseData,  "/Device1" , ColorNames[color_num]);
    return ColorNames[color_num];
   }
  else if (device == Device2)
  {
    digitalWrite(15, int(command[0]^1)-'0'); //change string to int with ascii correction
    digitalWrite(16, int(command[1]^1)-'0');
    digitalWrite(12, int(command[2]^1)-'0'); 
    digitalWrite(14, int(command[3])-'0');
    //===Firebase update===//
    Firebase.setString(firebaseData,  "/Device2" , ColorNames[color_num]);
    return ColorNames[color_num];
  }
  else if (device == AllDevice)
  {
    digitalWrite(2, int(command[0])-'0'); //change string to int with ascii correction
    digitalWrite(0, int(command[1])-'0');
    digitalWrite(4, int(command[2])-'0'); 
    digitalWrite(5, int(command[3])-'0');
    digitalWrite(15, int(command[0]^1)-'0'); //change string to int with ascii correction
    digitalWrite(16, int(command[1]^1)-'0');
    digitalWrite(12, int(command[2]^1)-'0'); 
    digitalWrite(14, int(command[3])-'0');
    //===Firebase update===//
    Firebase.setString(firebaseData,  "/Device1" , ColorNames[color_num]);
    Firebase.setString(firebaseData,  "/Device2" , ColorNames[color_num]);
    return ColorNames[color_num];
  }
  return error_color;
}
