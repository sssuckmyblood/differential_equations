#include "equation.h"

#include <string.h>






equation::equation() {
    a = 0;
    b = 0;
    y0 = 0;
    h = 0;
    function = 0;
    n = 0;
    size = 0;
    x = nullptr;
    result_analytical = nullptr;
    error_euler = nullptr;
    error_runge = nullptr;

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// В конструкторе с параметрами задаем полученные свойства уравнения, просчитываем x и точные решения уравнений	//	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void equation::set(int equation, double a_v, double b_v, double y0_v, double h_v) {

    a = a_v;
    b = b_v;
    y0 = y0_v;
    h = h_v;
    function = equation;
    n = (b - a) / h;
    size = (int)n + 1;

    try {
            result_analytical = new double[size];

            x = new double[size];

            x[0] = a;
            result_analytical[0] = analytical[function](x[0], x[0], y0);

            for (int i = 1; i < size; i++) {
                 x[i] = a + i * h;
                 result_analytical[i] = analytical[function](x[i], x[0], y0);
            }

        } catch (...) {
                QMessageBox::critical(NULL,QObject::tr("Ошибка"),"Ошибка формирования отрезка вычислений");
        }


}

void equation::set_custom(double a_v, double b_v, double y0_v, double h_v) {

    a = a_v;
    b = b_v;
    y0 = y0_v;
    h = h_v;
    function = 0;
    n = (b - a) / h;
    size = (int)n + 1;

    try {

        result_analytical = nullptr;

        x = new double[size];
        x[0] = a;

        for (int i = 1; i < size; i++) {
            x[i] = a + i * h;

        }

    } catch (...) {
            QMessageBox::critical(NULL,QObject::tr("Ошибка"),"Ошибка формирования отрезка вычислений");
    }

}


equation::equation(const equation& obj){
	a = obj.a;
	b = obj.b;
	y0 = obj.y0;
	h = obj.h;
	function = obj.function;
	n = obj.n;
	size = obj.size;
	
	x = new double[size];
    result_euler = new double[size];
    result_runge = new double[size];
    result_analytical = new double[size];
    error_euler = new double[size];
    error_runge = new double[size];

#ifdef __linux__
    memcpy(x, obj.x, sizeof(double) * size);

    memcpy(result_euler, obj.result_euler, sizeof(double) * size);

    memcpy(result_runge, obj.result_runge, sizeof(double) * size);

    memcpy(result_analytical, obj.result_analytical, sizeof(double) * size);

    memcpy(error_euler, obj.error_euler, sizeof(double) * size);

    memcpy(error_runge, obj.error_runge, sizeof(double) * size);
#elif _WIN32
    memcpy_s(x, sizeof(double) * size, obj.x, sizeof(double) * size);

    memcpy_s(result_euler, sizeof(double) * size, obj.result_euler, sizeof(double) * size);

    memcpy_s(result_runge, sizeof(double) * size, obj.result_runge, sizeof(double) * size);

    memcpy_s(result_analytical, sizeof(double) * size, obj.result_analytical, sizeof(double) * size);

    memcpy_s(error_euler, sizeof(double) * size, obj.error_euler, sizeof(double) * size);

    memcpy_s(error_runge, sizeof(double) * size, obj.error_runge, sizeof(double) * size);
#else

#endif


}

equation::~equation() {

	delete[] x;
	delete[] result_euler;
	delete[] result_runge;
	delete[] error_euler;
	delete[] error_runge;
	delete[] result_analytical;

	
}

	////////////////////
	// Метод Эйлера  //	
	//////////////////

void equation::method_euler() {

 try {

	result_euler = new double[size];

	error_euler = new double[size];

    result_euler[0] = y0;
	error_euler[0] =fabs(result_analytical[0] - result_euler[0]);


	for (int i = 1; i < size; i++) {



		result_euler[i] = result_euler[i - 1] + h * func[function](x[i - 1], result_euler[i - 1]);

		/* Вычисляем погрешность на каждом шаге по формуле |точное решение - решение по методу Эйлера| */
        error_euler[i] = fabs(result_analytical[i] - result_euler[i]);


	}

 } catch (...) {
       QMessageBox::critical(NULL,QObject::tr("Ошибка"),"Ошибка вычислений в методе Эйлера");
    }
	
}

void equation::method_euler_custom(ExpressionEstimator& equ_custom) {

 try {
    result_euler = new double[size];

    result_euler[0] = y0;
    error_euler = nullptr;


        for (int i = 1; i < size; i++) {

            result_euler[i] = result_euler[i - 1] + h *  equ_custom.calculate(x[i - 1], result_euler[i - 1]);

        }

 } catch (...) {
         QMessageBox::critical(NULL,QObject::tr("Ошибка"),"Ошибка вычислений в методе Эйлера");
    }


}

	/////////////////////////
	// Метод Рунге-Кутта  //	
	///////////////////////

void equation::method_runge() {

 try {
    result_runge = new double[size];
	double* result1 = new double[size];
	double* result2 = new double[size];
	double* result3 = new double[size];
	double* result4 = new double[size];

	error_runge = new double[size];

	result_runge[0] = y0;
	error_runge[0] = fabs(result_analytical[0] - result_runge[0]);



    for (int i = 1; i < size; i++) {

		result1[i] = h * func[function](x[i - 1], result_runge[i - 1]);
		result2[i] = h * func[function](x[i - 1] + h / 2, result_runge[i - 1] + result1[i] / 2);
		result3[i] = h * func[function](x[i - 1] + h / 2, result_runge[i - 1] + result2[i] / 2);
		result4[i] = h * func[function](x[i - 1] + h, result_runge[i - 1] + result3[i]);
		result_runge[i] = result_runge[i - 1] + (result1[i] + 2. * result2[i] + 2. * result3[i] + result4[i]) / 6.;

		/* Вычисляем погрешность на каждом шаге по формуле |точное решение - решение по методу Рунге-Кутта| */
        error_runge[i] = fabs(result_analytical[i] - result_runge[i]);

	}

	delete[] result1;
	delete[] result2;
	delete[] result3;
	delete[] result4;

    } catch (...) {
       QMessageBox::critical(NULL,QObject::tr("Ошибка"),"Ошибка вычислений в методе Рунге-Кутта");
    }
}

void equation::method_runge_custom(ExpressionEstimator& equ_custom) {

try {
    result_runge = new double[size];
    double* result1 = new double[size];
    double* result2 = new double[size];
    double* result3 = new double[size];
    double* result4 = new double[size];
    error_runge = nullptr;
    result_runge[0] = y0;


    for (int i = 1; i < size; i++) {

        result1[i] = h * equ_custom.calculate(x[i - 1], result_runge[i - 1]);
        result2[i] = h * equ_custom.calculate(x[i - 1] + h / 2, result_runge[i - 1] + result1[i] / 2);
        result3[i] = h * equ_custom.calculate(x[i - 1] + h / 2, result_runge[i - 1] + result2[i] / 2);
        result4[i] = h * equ_custom.calculate(x[i - 1] + h, result_runge[i - 1] + result3[i]);
        result_runge[i] = result_runge[i - 1] + (result1[i] + 2. * result2[i] + 2. * result3[i] + result4[i]) / 6.;

    }

    delete[] result1;
    delete[] result2;
    delete[] result3;
    delete[] result4;

    } catch (...) {
           QMessageBox::critical(NULL,QObject::tr("Ошибка"),"Ошибка вычислений в методе Рунге-Кутта");
        }
}





