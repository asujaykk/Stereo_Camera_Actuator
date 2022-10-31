/*
 * The below method will read serial data starting from 'strt' char until 'en' char to a string 
 * The start and end characters are removed from the output string
 * The reading stops if the iteration reach MAX_CHAR_PER_DATA to avoid infinite looping
 */

String read_data(char strt,char en){
  String data="";
  while(ser_read_data()!=strt);
  char a=ser_read_data();
  for(int i=0;i<MAX_CHAR_PER_DATA && a!=en;){
   if (ser_available()){
     data +=a;
     a=ser_read_data();
     i++;
   }
  }
  return data;
}



/*
 * The following method will split the data frame string 'in'  with seperation character 'sep' and store
 * the substrings in 'out' array.
 * 
 */

boolean split_String(String in, String out[], char sep){
  int st=0;
  int en=0;
  for(int i=0;i<ELEMENTS_PER_DATA;i++){
     en=in.indexOf(sep,st);
     //ser_send_data(String(st)+" "+String(en));
     if (en!=-1){      
       out[i]=in.substring(st,en);
       st=en+1;
     }
     else if (en==-1 and i!=0){
       out[i]=in.substring(st,in.length());
       //ser_send_data("size"+String(in.length()));
     }
     else if (en==-1 && i==0){
       return false;
     }
     
  }
  return true;
}

/*
 * The following method will convert input string array 'inA' to integer array 'outA'
 * Basically each data frame element recieved as string need to be converted to integer.
 */

void update_eyepos_array(String inA[],int outA[]){
  for (int i=0;i<ELEMENTS_PER_DATA;i++){
    outA[i]=StrToInt(inA[i]);
  }
}


/*
 * Method to convert string to integer
 */

int StrToInt(String str){
  return str.toInt();
}

/*
 * The following method will copy array 'arin' to 'arout'
 */

void arrayCopy(int arin[],int arout[]){
  for (int i=0;i<ELEMENTS_PER_DATA;i++){
    arout[i]=arin[i];
  }
}
