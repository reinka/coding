#include <stdio.h>


void pow_int(int* base, int exponent);
void pow_float(float* base, int exponent);
void pow_double(double* base, int exponent);
void pow_void(void* base, int exponent, int type);


int main(int argc, char const *argv[])
{
	int base_int, exponent, type;
	float base_float;
	double base_double;
	void *p = NULL;



	printf("Wählen Sie eine ganzzahlige Basis und einen ganzzahligen Exponent:" );
	scanf(" %d %d", &base_int, &exponent);
	while(getchar() != '\n');
	
	pow_int(&base_int, exponent);
	printf("%d\n", base_int);




	printf("Wählen Sie eine Basis in Gleitkommedarstellung mit einfacher Präzision und einen ganzzahligen Exponent:" );
	scanf(" %f %d", &base_float, &exponent);
	while(getchar() != '\n');
	
	pow_float(&base_float, exponent);
	printf("%f\n", base_float);




	printf("Wählen Sie eine Basis in Gleitkommedarstellung mit doppelter Präzision und einen ganzzahligen Exponent:" );
	scanf(" %lf %d", &base_double, &exponent);
	while(getchar() != '\n');
	
	pow_double(&base_double, exponent);
	printf("%lf\n", base_double);






	printf("Wählen Sie Basis vom Typ Ihrer Wahl und einen ganzzahligen Exponent.\n" );
	printf("Vom welchen Datentypen soll Ihre Basis sein (int = 1, float = 2, double = 3): ");
	
	scanf(" %d", &type);
	while(getchar() != '\n');
	
	printf("Wählen Sie nun Ihre Basis und einen ganzzahligen Exponenten: ");
	switch(type){
		case 1: scanf(" %d %d", &base_int, &exponent); 
				while(getchar() != '\n'); 
				p = &base_int;
				pow_void(p, exponent, type);
				printf("%d\n", *(int*)p); 
				break;
		case 2: scanf(" %f %d", &base_float, &exponent);
				while(getchar() != '\n');
				p = &base_float;
				pow_void(p, exponent, type);
				printf("%f\n", *(float*)p);
				break;
		case 3: scanf(" %lf %d", &base_double, &exponent); 
				while(getchar() != '\n');
				p = &base_double;
				pow_void(p, exponent, type);
				printf("%lf\n", base_double); 
				break;
	}


	return 0;
}



void pow_int(int* base, int exponent)
{	
	int factor = 1;
	for(int i = 0; i < exponent; i++)
		factor *= *base;
	*base = factor;
}




void pow_float(float* base, int exponent)
{
	float factor = 1;
	for(int i = 0; i < exponent; i++)
		factor *= *base;
	*base = factor;
}



void pow_double(double* base, int exponent)
{
	double factor = 1;
	for(int i = 0; i < exponent; i++)
		factor *= *base;
	*base = factor;
}



void pow_void(void* base, int exponent, int type){
	
	/*derefernzierung von void pointer ohne weiteres nicht möglich.
	  Es wird "type" gebraucht, um einen type cast auf den void pointer 
	  durchüfhren zu können, um anschließend den void pointer dereferenzieren zu können.
	  der void pointer wird quasi zu einem pointer der auf den typen "type" zeigt gecastet.
	  anschließend dereferenziert.
	 */

	double factor = 1;

	switch(type){

		case 1: for(int i = 0; i < exponent; i++)
					factor *= *(int*)base;
				
				*(int*)base = factor;
				break;

		case 2:	for(int i = 0; i < exponent; i++)
					factor *= *(float*)base;
				
				*(float*)base = factor;
				break;

		case 3:	for(int i = 0; i < exponent; i++)
					factor *= *(double*)base;
				
				*(double*)base = factor;
				break;
	}			
}

