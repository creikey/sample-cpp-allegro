#ifndef HPP_VECTOR2
#define HPP_VECTOR2

// Standard 2d Vector2
template <class T = float> class Vector2 {
public:
  T x;
  T y;
  Vector2() : x(T(0)), y(T(0)){};
  Vector2(T inx, T iny) : x(inx), y(iny){};
  Vector2<double> normalize() {
    double len = this->length();
    return Vector2<double>(this->x / len, this->y / len);
  };
  double length() { return sqrt(this->x * this->x + this->y * this->y); };
  std::string toString() {
    return "(" + std::to_string(this->x) + "," + std::to_string(this->y) + ")";
  };

  Vector2 &operator+(const Vector2 &vec) {
    this->x += vec.x;
    this->y += vec.y;
    return *this;
  }; // add
  Vector2 &operator*(const Vector2 &vec) {
    this->x *= vec.x;
    this->y *= vec.y;
    return *this;
  };
  Vector2 &operator*(const T scalar) {
    this->x *= scalar;
    this->y *= scalar;
    return *this;
  };
  Vector2 &operator-(const Vector2 &vec) {
    this->x -= vec.x;
    this->y -= vec.y;
    return *this;
  };
  Vector2 &operator/(const Vector2 &vec) {
    this->x /= vec.x;
    this->y /= vec.y;
    return *this;
  };
  bool operator>(const Vector2 &vec) {
    return (this->x > vec.x) && (this->y > vec.y);
  }
  bool operator<(const Vector2 &vec) {
    return (this->x < vec.x) && (this->y < vec.y);
  }
};

#endif // HPP_VECTOR2