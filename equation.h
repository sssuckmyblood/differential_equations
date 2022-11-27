#define FUNCTIONS 6
#include <math.h>
#include <memory.h>
#include "expressionEstimator.h"

#include <QMessageBox>


/////////////////////////////////////////////////
// Задаем шаблоны функций и их точных решений //	
///////////////////////////////////////////////

double F0(double, double);
double F1(double, double);
double F2(double, double);
double F3(double, double);
double F4(double, double);
double F5(double, double);

double F0_analytical(double, double, double);
double F1_analytical(double, double, double);
double F2_analytical(double, double, double);
double F3_analytical(double, double, double);
double F4_analytical(double, double, double);
double F5_analytical(double, double, double);

///////////////////////////////////
// Объявляем класс уравнений	//	
/////////////////////////////////

class equation {

	private:

		/* Задаем приватные свойства уранения */

		double a;
		double b;
		double y0;
		double h;
		double n;
		int function;

		/* Задаем массив указателей на функции */
	
		double (*func[FUNCTIONS])(double, double) = {
		  F0,
		  F1,
		  F2,
		  F3,
		  F4,
		  F5

		};

		/* Задаем массив указателей на аналитические решения уравнений */
	
		double (*analytical[FUNCTIONS])(double, double, double) = {
		  F0_analytical,
		  F1_analytical,
		  F2_analytical,
		  F3_analytical,
		  F4_analytical,
		  F5_analytical

		};


	public:
		/* Задаем массивы для хранения данных */
		int size;
		double* x;
		double* result_euler = nullptr;
		double* result_runge = nullptr;
		double* result_analytical = nullptr;
		double* error_euler = nullptr;
		double* error_runge = nullptr;

		/* Задаем прототипы конструкторов и методов */
        equation();
        equation(int, double, double, double, double);
        void set(int, double, double, double, double);
        void set_custom(double, double, double, double);
//		void set(int, double, double, double, double);
		equation(const equation&);
		~equation();
	
        void method_euler();
        void method_euler_custom(ExpressionEstimator &);
        void method_runge();
        void method_runge_custom(ExpressionEstimator &);

};

