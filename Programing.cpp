// NAMA		: Rana Ahmad Nasih Ulwan Khan
// NRP		: 5022221231
// Jurusan	: Teknik Elektro

#include <iostream>
#include <cmath>

#define GRAVITASI 10 //10 m/s^2
#define START_PENGUKURAN 1 //pengukuran dimulai dari 1 meter
#define SUDUT 45 //sudut elevasi tembakan

float mencari_V0(float vt, float speed_loss)
{
	float V0 = vt - speed_loss;
  	return V0;
}

float speed_dgn_loss(float a)
{
	float loss = 0;
	if (a >= 2 && a <= 11) {
		loss = 1;
	}
	else if (a >= 14 && a <= 23) {
		loss = 3;
	}
	else if (a >= 26 && a <= 30) {
		loss = 5;
	}
    return loss;
}

int main() {
	float input;
	float loss;
	float V0;
	int jarak;

  	std::cin >> input;

	loss = speed_dgn_loss(input);
	V0 = mencari_V0(input, loss);

	jarak = powf(V0, 2)*sin(2*SUDUT*3.14/180) / GRAVITASI;
	double t = sqrt(jarak*GRAVITASI/sin(2*SUDUT*3.14/180)) + loss;

  	std::cout << jarak << " " << t << std::endl;

    return 0;
}