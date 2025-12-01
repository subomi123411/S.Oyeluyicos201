constexpr double square(double x) {
    return x*x;
}

constexpr double max1 = 1.4*square(17); //OK 1.4*square(17) is a constant expression
constexpr double max2 = 1.4*square(var); //error var is not a constant exppression
const double max3 = 1.4*square(var); //OKmay be evaluated at run time 