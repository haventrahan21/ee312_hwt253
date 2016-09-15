#include <stdio.h>
#define ptk .45359237;
#define ktp 2.2046226;
int i;
int num;
int hour;
int nhour;
int min;
int dollars;
int cents;
float USD;
float Euro;
int F;
int C;
float Dist;
float kg;
int lb;
int oz;
int rnd;

int main(void) {
	printf("Enter a number (1-11) to select a specific conversion to perform or to quit:\n");
	//num = getchar();
	scanf("%d", &num);
	switch (num) {
		case 1 :		//austin time to Irish
		printf("enter Austin time to be converted, expressed in hours and minutes:\n");
		scanf("%d", &hour);
		scanf("%d", &min);
		nhour = (hour + 6) % 24;
		printf("the time in Ireland equivalent to %d %d in Austin is %d %d of the ", hour, min, nhour, min);
		if (nhour < hour) { printf("next day"); }
		else { printf("same day"); }
		break;

		case 2:		//Irish to Austin time
		printf("enter a time\n");
		scanf("%d", &hour);
		scanf("%d", &min);
		nhour = (hour + 18) % 24;
		printf("the time in Austin equivalent to %d %d in Irleand is %d %d of the ", hour, min, nhour, min);
		if (nhour > hour) { printf("previous day"); }
		else { printf("same day"); }
		break;

		case 3:		//USD to Euro
		printf("Enter USD value\n");
		scanf("%d %d", &dollars, &cents);
		USD = cents / 100;
		USD = USD + dollars;
		Euro = USD * .89;
		printf("The Euro value is %f\n", Euro);
			break;

		case 4:		//Euro to USD
			printf("Enter Euro value\n");
			scanf("%f", &Euro);
			Euro = Euro * 1.13;
			dollars = Euro;
			Euro = Euro - dollars;
			Euro = Euro * 100;
			cents = Euro;
			printf("USD value is: $%d.%d", dollars, cents);
			break;

		case 5:		//F to C
			printf("Enter temperature in Fahrenheit\n");
			scanf("%d", &F);
			F = (F - 32);
			F = (5 * F);
			C = (F / 9);
			printf("The temperature in Celcius is %d\n", C);
			break;

		case 6:		//C to F
			printf("Enter temperature in Celcius\n");
			scanf("%d", &C);
			F = ((9 / 5)*C) + 32;
			printf("The temperature in Fahrenheit is %d\n", F);
			break;

		case 7:		//kg to lbs & oz
			printf("Enter weight in Kg\n");
			scanf("%f", &kg);
			kg = kg * ktp;
			lb = kg;
			kg = kg - lb;
			kg = kg * 100;
			oz = kg / 6.25;
			printf("Weight in pounds and ounces is: %d lbs %d oz", lb, oz);
			break;

		case 8:		//lbs & oz to kg
			printf("Enter weight in pounds and ounces\n");
			scanf("%d %d", &lb, &oz);
			kg = oz / 16;
			kg = lb + kg;
			kg = kg * ptk;
			printf("Weight in Kg is %f\n", kg);
			break;

		case 9:		//miles to km
			//km = .6213712 miles
			printf("Enter a distance in Miles to be converted to Kilometers\n");
			scanf("%f", &Dist);
			Dist = Dist /.6213712;
			printf("distance is %f\n", Dist);
			break;

		case 10:	//km to miles
			printf("Enter a distance in Kilometers to be converted to Miles\n");
			scanf("%f", &Dist);
			Dist = Dist * .6213712;
			printf("Distance is %f\n", Dist);
			break;
		case 11:
			printf("Goodbye\n");
			
	}
	
	return 0;
}
