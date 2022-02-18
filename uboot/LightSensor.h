class LightSensor
{
  private:
  int pin;

  public:
  LightSensor();
  LightSensor(int pin_);
  
  float get_value();
};
