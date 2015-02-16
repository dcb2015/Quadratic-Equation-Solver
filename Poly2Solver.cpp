void Poly2Solver(double a, double b1, double c, double* sr, double* si, double* lr, double* li) {
// Calculates the zeros of the quadratic a*x^2 + b1*x + c
// This solver computes both real only AND complex roots (if applicable).
// The components of the two roots are lr and li (the real and imaginary components, respectively, of one root), and
// sr and si (the real and imaginary components, respectively,  of the other root).

char rflag;
double b, d, e;

*sr = *lr = *si = *li = std::numeric_limits<double>::quiet_NaN();
if (a == 0) {
    cout << "\n a = 0. NOT A QUADRATIC EQUATION! TWO ROOTS WILL NOT BE FOUND. \n";
    cout << "\nEnter any key to continue. \n";
    cin >> rflag;
    if (b1 != 0) {
        *sr = -(c/b1);
        *si = 0.0;
    }
}
else {
   *sr = *si = *li = 0.0;
   if (c == 0){
        *lr = -(b1/a);
   }
   else {
        b = b1/2.0;
        if (fabs(b) < fabs(c)){
           e = ((c >= 0) ? a : -a);
           e = -e + b*(b/fabs(c));
           d = sqrt(fabs(e))*sqrt(fabs(c));
        } // End if (fabs(b) < fabs(c))
        else { // Else (fabs(b) >= fabs(c))
           e = -((a/b)*(c/b)) + 1.0;
           d = sqrt(fabs(e))*(fabs(b));
        } // End else (fabs(b) >= fabs(c))

        if (e >= 0) { // Real zeros
           d = ((b >= 0) ? -d : d);
           *lr = (-b + d)/a;
           *sr = ((*lr != 0) ? (c/(*lr))/a : *sr);
        } // End if (e >= 0)
        else { // Complex conjugate zeros
           *lr = *sr = -(b/a);
           *si = fabs(d/a);
           *li = -(*si);
        } // End else (e < 0)
   }
}
return;
} // End Poly2Solver
