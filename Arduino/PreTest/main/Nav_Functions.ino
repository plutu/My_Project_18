//This is where we put our overall navigational functions

void strip(char dir){
  dc_go(motor2, motor4, dir);
  howfarwevecome = 0;
  while(howfarwevecome<sidewaystime){
   if (get_distance()<5){
    dc_stop(motor2, motor4);
    if(is_mag()=True){
      collect();  
    }
    delay(pausetime);
  }
  howfarwevecome += pausetime;  
  }
  dc_stop(motor2, motor4);
}

void backtobase(int lines){//do we even need this function?
  dc_move(motor1, motor3, BACKWARD, lines*linesdone);
  //thought: maybe change the dc_move runtime to some arbitrarily large number (10000) so that we just run until we hit the wall. 
  //Can our bot take some bumps?
}

void dump(){
  dc_spin(motor2, motor4, 180); //doesn't matter which two motors, really
  step_open();
  dc_move(motor1, motor3, BACKWARD, linewidth);
  step_close();
  dc_spin(motor2, motor4, 180);
}


