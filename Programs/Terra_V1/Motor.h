#ifndef Motor_H
#define Motor_H

enum Side {Left, Right};


class Motor{

  public:
    Motor(int fwd, int bwd, int pwm, Side s);

    // After constructor add in begin, get and update
    int get_pins();

    // Other useful functions
    void Straight_cm(int distance);
    void Turn_Left();
    void Turn_Right();
    void Single_Point_Turn(Side s);
    void Stop();
    void Backwards(int pwm);
    void Slow_Down(int slow_down_pwm);



  
  private:
    int _pwm;
    int _side;
    int _fwd;
    int _bwd;
};


#endif