char TransmitData, ReceiveData;
void main() {
     ADCON1 |= 0x0F;
     CMCON |=7;

     PORTB =0x00; LATB = 0x00;
     TRISB0_bit = 1;
     TRISB1_bit = 1;
     TRISB2_bit = 1;

     PORTE =0x00; LATE = 0x00;
     TRISE1_bit = 0;
     TRISE2_bit = 0;
     TRISE0_bit = 0;

     LATE1_bit = 0;
     LATE2_bit = 0;
     LATE0_bit = 0;

     UART1_Init(9600);
     delay_ms(100);

    while(1)
     {
        if(Button(&PORTB, 0, 10, 0))
        {
           while(Button(&PORTB, 0, 10, 0));
           LATE0_bit = 1;
           TransmitData = 'A';
           UART1_Write(TransmitData);
        }
        if(Button(&PORTB, 1, 10, 0))
        {
           while(Button(&PORTB, 1, 10, 0));
           LATE0_bit = 0;
           LATE1_bit = 0;
           LATE2_bit = 0;
           TransmitData = 'a';
           UART1_Write(TransmitData);
        }
        if(RE0_bit == 1)
        {
           if(Button(&PORTB, 2, 10, 0))
           {
              while(Button(&PORTB, 2, 10, 0));
              LATE1_bit = 1;
              TransmitData = 'B';
              UART1_Write(TransmitData);
           }
           if(Button(&PORTB, 3, 10, 0))
           {
              while(Button(&PORTB, 3, 10, 0));
              LATE1_bit = 0;
              LATE2_bit = 0;
              TransmitData = 'b';
              UART1_Write(TransmitData);
           }
        }
        if(RE1_bit == 1)
        {
           if(Button(&PORTB, 4, 10, 0))
           {
              while(Button(&PORTB, 4, 10, 0));
              LATE2_bit = 1;
              TransmitData = 'C';
              UART1_Write(TransmitData);
           }
           if(Button(&PORTB, 5, 10, 0))
           {
              while(Button(&PORTB, 5, 10, 0));
              LATE2_bit = 0;
              TransmitData = 'c';
              UART1_Write(TransmitData);
           }
        }
     }

}