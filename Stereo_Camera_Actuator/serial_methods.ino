boolean ser_available(){
  return Serial.available();
}

char ser_read_data(){
  delay(2);
  return Serial.read();
}

void ser_send_data(String data){
  Serial.println(data);
}
