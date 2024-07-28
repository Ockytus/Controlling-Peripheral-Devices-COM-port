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

     LATE1_bit = 1;
     LATE2_bit = 1;
     LATE0_bit = 1;

     UART1_Init(9600);
     delay_ms(100);

     while(1)
     {
             if(UART1_Data_Ready() == 1)
             {
                ReceiveData = UART1_Read();
                if(ReceiveData == 'a')
                {
                   LATE0_bit = 0;
                   TransmitData = 'a';
                   UART1_Write(TransmitData);
                }
                
                if(ReceiveData == 'A')
                {
                    LATE0_bit = 1;
                    TransmitData = 'A';
                    UART1_Write(TransmitData);
                }
                    
                if(ReceiveData == 'B')
                {
                      LATE1_bit = 1;
                      TransmitData = 'B';
                      UART1_Write(TransmitData);
                }
                if(ReceiveData == 'C')
                {
                     LATE2_bit = 1;
                     TransmitData = 'C';
                     UART1_Write(TransmitData);
                }
             }
     }

}