#pragma once
#include <cmath>

namespace ad {


	class Dual {
	public:
		double value;
		double derivative;
		Dual(double v, double d) : value(v), derivative(d) {}
		Dual(double v) : value(v), derivative(0) {}
		Dual operator+(const Dual& other) {
			return Dual(value + other.value, derivative + other.derivative);
		}
		Dual operator-(const Dual& other) {
			return Dual(value - other.value, derivative - other.derivative);
		}
		Dual operator-() {
			return Dual(-value, -derivative);
		}
		Dual operator*(const Dual& other) {
			return Dual(value * other.value, derivative * other.value + value * other.derivative);
		}
		Dual operator/(const Dual& other) {
			return Dual(value / other.value, derivative / other.value - value * other.derivative / (other.value * other.value));
		}
		Dual operator^(const double& power) {
			return Dual(std::pow(value, power), power * std::pow(value, power - 1) * derivative);
		}
		Dual operator^(const Dual& other) {
			double v = std::pow(value, other.value);
			return Dual(v, v * (other.derivative * std::log(value) + (other.value * derivative / value)));
		}




	};


	Dual sin(Dual x) {
		return Dual(std::sin(x.value), x.derivative * std::cos(x.derivative));
	}
	Dual cos(Dual x) {
		return Dual(std::cos(x.value), -x.derivative * std::sin(x.derivative));
	}

}

