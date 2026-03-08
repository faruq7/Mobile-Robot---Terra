#ifndef Encoder_H
#define Encoder_H

class Encoder{

  public:
    Encoder(int a, int b);
    
    void begin();
    void debug();
    static void encoderISR();
    
    void Read_Encoder_Val();
    long Get_Pulses();
    long Get_Revs();
    void Reset_Counter();
    volatile long EncoderCount_A1;
    //volatile long Encoder::EncoderCount_A1 = 0;
    void getCount();

    int channel_a;
    int channel_b;
  private:

    void handleISR();

    static void isr0();
    static void isr1();

    static Encoder* instance0;
    static Encoder* instance1;
    
    int PPR = 480;
    int Lhs_Val_A = 0;
    
};


#endif