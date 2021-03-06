#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    gyro,           sensorGyro)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_3,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port2,           leftD,         tmotorVex393HighSpeed_MC29, PIDControl, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port3,           rightD,        tmotorVex393HighSpeed_MC29, PIDControl, encoderPort, I2C_2)
#pragma config(Motor,  port4,           lift,          tmotorVex393_MC29, PIDControl, encoderPort, I2C_3)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


// PID controlled movement
// i: controls direction, set to 1 for forward and -1 for negative
// d: distance in # of tiles
// s: speed of motor from -127 to 127
void moveStraight(int i,long d,int s){
	clearTimer(T1);
	nMotorEncoder(leftD) = 0;
	nMotorEncoder(rightD) = 0;
	short dist = 700*d*i;
	//remember to change code based on wiring
	setMotorTarget(leftD,dist,s,false);
	setMotorTarget(rightD,dist,s,false);

	// Runs till target is reached
	while((!getMotorTargetCompleted(leftD) || !getMotorTargetCompleted(rightD))&time1[T1]<4000)
	{
		sleep(10);
	}
}


task main()
{
	while(1){
		moveStraight(1,1,60);
		sleep(500);
		moveStraight(-1,1,60);
	}
}
