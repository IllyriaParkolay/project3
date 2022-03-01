void GetAnalog_A0()
{
    Purple_Monkey = analogRead(A0);
      Purple_Monkey = map(Purple_Monkey, 0, 1023, 0, 255);
//    if (Purple_Monkey > 255)
//    {
//      Purple_Monkey=255;
//    }
     //Serial.println(Purple_Monkey);
  /*float voltage = Purple_Monkey * (5.0 / 1023.0);*/
}
