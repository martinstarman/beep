#pragma once

class Vec2
{
public:
  Vec2(float x, float y);
  ~Vec2();
  float X();
  float Y();
  void SetY(float y);

private:
  float mX;
  float mY;
};
