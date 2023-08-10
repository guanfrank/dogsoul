#include <stdio.h>
#include <math.h>

// Accelerometer data
extern float accel_x, accel_y, accel_z;
//void complementaryFilter( float , float );
// Gyroscope data
float gyro_x, gyro_y, gyro_z;

// Filter variables
float alpha = 0.98;  // Complementary filter constant

// Calibration offsets
float offset_x = 0.0;
float offset_y = 0.0;
float offset_z = 0.0;

// Apply calibration to accelerometer data
void calibrateAccelerometer() {
    accel_x -= offset_x;
    accel_y -= offset_y;
    accel_z -= offset_z;
}

// Complementary filter function
void complementaryFilter(float pitch, float roll) {
//    float pitch, roll;

    // Apply calibration
    calibrateAccelerometer();

    // Calculate pitch and roll using accelerometer data
    pitch = atan2(accel_x, sqrt(accel_y * accel_y + accel_z * accel_z));
    roll = atan2(accel_y, sqrt(accel_x * accel_x + accel_z * accel_z));

    // Combine gyroscope and accelerometer data using complementary filter
    pitch = alpha * (pitch + gyro_x) + (1 - alpha) * pitch;
    roll = alpha * (roll + gyro_y) + (1 - alpha) * roll;

    // Output filtered pitch and roll angles
    printf("%f, %f\n", pitch, roll);
   // printf("%f\n", roll);
}
/*
int main() {
    // Initialize accelerometer and gyroscope data
    accel_x = 0.0;
    accel_y = 0.0;
    accel_z = 0.0;
    gyro_x = 0.0;
    gyro_y = 0.0;
    gyro_z = 0.0;

    // Run the complementary filter
    complementaryFilter();

    return 0;
}
*/
