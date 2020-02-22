#include <stdio.h>

double evaluate_polynomial(double x, double* coeffs, int degree, int stage, double result);

int main()
{

        double x;
        int degree;
        double coeffs[50];

        printf("Polynomial Evaluation using Horner's rule ----\n");

        printf("Format :  (a0 * x^4) + (a1 * x^3) + (a4 * x^2) + (a5 * x) + (a6) \n\n");

        printf("Enter the degeree of the polynomial: ");
        scanf("%d", &degree);

        printf("Enter the value of x : ");
        scanf("%lf", &x);

        printf("Enter the co-effs (starting from a0) :\n");
        for(int i=0; i<degree+1; i++)
                scanf("%lf", &coeffs[i]);

        double ansX = 0;
        double ans = evaluate_polynomial(x, coeffs, degree, 0, ansX);

        printf("Ans = %lf\n", ans);

        return 0;
}


double evaluate_polynomial(double x, double* coeffs, int degree, int stage, double result)
{
        if(stage > degree)
        {
                return result;
        }

        result *= x;
        result += coeffs[stage];

        return evaluate_polynomial(x, coeffs, degree, stage+1, result);
}

