#include <stdio.h>
#include <math.h>
#include <conio.h>

float get_positive_float_input();
char ask_to_do_more();
float find_area(float side1, float side2, float side3);
float find_height(float side, float area);
float find_median(float side1, float side2, float side3);
float find_bisector(float side1, float side2, float side3);

void draw_line() { printf(" <-------------------------->\n\n"); }

int main()
{
	float a, b, c;
	char check = 0;
	char again = 0;

	printf("  <<<--- Triangle Calculator --->>>  \n\n");
	do {
		do
		{
			// Enter triangle sides
			printf(" ENTER A: ");
			a = get_positive_float_input();
			printf(" ENTER B: ");
			b = get_positive_float_input();
			printf(" ENTER C: ");
			c = get_positive_float_input();

			printf("\n");

			if ((a + b) <= c || (a + c) <= b || (b + c) <= a)
			{
				printf(" This triangle doesn't exist!\n\n");
				draw_line();
				check = 0;
			}
			else
			{
				check = 1;
			}
		} while (!check);

		// Calculating and print results
		float area = find_area(a, b, c);
		printf(" Triangle area: %.4f\n", area);
		printf(" Triangle perimeter: %.4f\n\n", a + b + c);

		printf(" Height A: %.4f\n", find_height(a, area));
		printf(" Height B: %.4f\n", find_height(b, area));
		printf(" Height C: %.4f\n\n", find_height(c, area));

		printf(" Median A: %.4f\n", find_median(a, b, c));
		printf(" Median B: %.4f\n", find_median(b, c, a));
		printf(" Median C: %.4f\n\n", find_median(c, a, b));

		printf(" Bisector A: %.4f\n", find_bisector(a, b, c));
		printf(" Bisector B: %.4f\n", find_bisector(b, c, a));
		printf(" Bisector C: %.4f\n", find_bisector(c, a, b));

		again = ask_to_do_more();

		draw_line();
	} while (again);

	return 0;
}

// Ask to do again
char ask_to_do_more()
{
	printf("\n ??? Do you want to do more (enter) ??? ");

	char decision = _getch();
	printf("%c\n\n", decision);

	if (decision == '\r' || decision == 'y' || decision == 'Y' || decision == '1' || decision == '+')
	{
		return 1;
	}
	return 0;
}

// Get input from user
float get_positive_float_input()
{
	char check = 0;
	char buf;
	float i;

	// Loop for repeating input if it's not a float
	do
	{
		if (scanf("%f%c", &i, &buf) && buf == '\n')
		{
			if (i > 0)
			{
				check = 1;
			}
			else
			{
				printf("\n Number must be greater than 0!\n Enter again: ");
			}
		}
		else
		{
			printf("\n Not a float!\n Enter again: ");
			while ((buf = getchar()) != '\n' && buf != EOF);
		}
	} while (!check);

	return i;
}

// Find area of the triangle
float find_area(float side1, float side2, float side3)
{
	float p = (side1 + side2 + side3) / 2;
	return sqrt(p * (p - side1) * (p - side2) * (p - side3));
}

// Find height to 'side' of the triangle
float find_height(float side, float area)
{
	return 2 * area / side;
}

// Find median to 'side1' of the triangle
float find_median(float side1, float side2, float side3)
{
	return 0.5 * sqrt(2 * side2 * side2 + 2 * side3 * side3 - side1 * side1);
}

// Find bisector to 'side1' of the triangle
float find_bisector(float side1, float side2, float side3)
{
	float p = (side1 + side2 + side3) / 2;
	return 2 / (side2 + side3) * sqrt(side2 * side3 * p * (p - side1));
}