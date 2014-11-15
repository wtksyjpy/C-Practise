/*
 
 A program to compute the early exercise boundary for American style
 stock put options.  Written by
 
 Jonathan Goodman, Courant Institute of Mathematical Sciences, NYU
 goodman@cims.nyu.edu
 http://www.math.nyu.edu/faculty/goodman
 
 Dan Ostrov, Mathematics Department, Santa Clara University
 dostrov@scu.edu
 
 written summer 2000.
 
 This was written to produce the pictures in our paper on the early
 exercise boundary  for American style puts.  It is not particularly
 efficient and is not "state of the art" computational technique.
 
 */



#include <iostream>
#include <math.h>     /*  Will use the log or exp functions somewhere  */
#include <fstream>  /*  Use the C++ file communication system for dumping
computed results.       */
#include <iomanip>  /*  To be able to print more decimal digits in the
output*/

#define NX_MAX 16002 /*  A dimension bigger than we will probably ever
use to simplify storage allocation  */
#define NUMAVG 500

#define T_STEP_RATIO .9  /* Thr fraction of max possible CFL ratio to use.  */

#define MACH_EPSILON 1.e-15 /* A small tolerence related to the roundoff level
for double precision computer arithmetic.  Used
in time_step in taking the max of the computed
solution and the computed intrinsic value.  */

// A program to solve the black scholes problem for an american style put
// in log variables.



//*************************** time_step **************************************



/*
 Take a single time step for the american put problem.
 First take a Forward Euler step, using precomputed
 coefficients a, b, and c.  Then take the maximium of
 that with the intrinsic value.
 
 Report an error if the early exercise boundary is in
 the first grid interval.  Apply dirichlet boundary
 conditions at the right boundary.
 
 The strike price is taken to be S=1, which corresponds to
 x=0 in log variables.
 
 u is the solution being computed.  Its first and last entries
 hold boundary values and are not updated.  The first entry is
 u[0].  The last is u[nx].  The u array has nx+1 entries, of which
 nx-1 are updated.  The old values are overwritten by new
 values.
 
 The routine returns a number, x_crit, which is the x value of the
 first grid point where the constraint u>1-S = 1-exp(x) is not
 binding.
 
 
 */
using namespace std;

static int time_step( double u[],
                     double uintr[],
                     double x_crit[],
                     double x_min,
                     double dx,
                     double dt,
                     double sigma, double r,
                     int nx) {
    
    double* u_new= new double[NX_MAX];   // Temporary storage for the time step routine.
    
    //  Coefficients for the finite difference method.
    
    double a = (dt*sigma*sigma)/(2*dx*dx) - ( ( r - sigma*sigma/2 )*dt)/(2*dx);
    double b = 1 - ( dt*sigma*sigma)/(dx*dx) - r*dt;
    double c = (dt*sigma*sigma)/(2*dx*dx) + ( ( r - sigma*sigma/2 )*dt)/(2*dx);
    
    // A safety precaution, probably unnecessary.
    
    if ( ( a < 0 ) || ( b < 0 ) || ( c < 0 ) ) {
        cout << "in time_step, bailing because a coefficient is negative."
        << "  a, b, c, = " << a << "  " << b << "  " << c << endl;
        delete u_new;
        return 1;
    }
    
    //  Take a time step for the PDE
    
    int ix;
    for ( ix=1; ix<nx; ix++)
        u_new[ix] = a*u[ix-1] + b*u[ix] + c*u[ix+1];
    
    // Take the max with the intrinsic value.
    
    double x = x_min;
    double x_cutoff = -1.e-3; // Purely technical, determines how the intrinsic
    // value is computed.
    for ( ix=1; ix<nx; ix++) {
        x = x + dx;            // The first trip through the loop has ix=1.
        
        // Do the comparison
        
        if ( u_new[ix] > uintr[ix]*( 1 + MACH_EPSILON)  )
            // Allow for roundoff in the u_new computation.
            break;          // Stop if you've left the intrinsic value curve . . .
        u_new[ix] = uintr[ix]; // Otherwise make correct the numerical solution.
        
    }  // end of "for (int ix=1; ix<nx; ix++){ ... "
    
    *x_crit = x;  // If you got here, it should be because you broke out of the
    // loop when you found  the constraint no longer binding.
    
    for ( ix = 1; ix < nx; ix++ )  // Finally, copy the new time level solution
        u[ix] = u_new[ix];          // back into the u array.  Don't modify the
    // end point values.
    
    delete u_new;
    return 0;
    
}


//*********************  main  ********************************************

/*
 
 
 The main program.  This sets the parameters, runs the time stepper,
 and sends the output to a file.
 
 */

int main() {
    
    double r      = .03;    // The risk free rate.
    double sigma  = .9;     // The volatility, in percent/year.
    int    nx     = 16000;  // The number of grid points to use.
    double numavgd = NUMAVG;        // double version of NUMAVG
    int timecount;
    double rho     = r - sigma*sigma/2; // A normalized risk free rate.
    
    ofstream crit_price_output;          //set up the print file
    crit_price_output.open("v_avg.mat");
    
    crit_price_output <<  "  nx = " << nx << ";"
    "  NUMAVG= " << NUMAVG << ";"
    "   sigma = " << sigma << ";"
    "   r = " << r << ";"
    "   v_theory = " << 8*3.141592654*r*r/(sigma*sigma) << ";" << endl;
    crit_price_output <<  "time:          x_crit:            v:           total time iterations:" << endl;
    
    
    //Here's the important time loop parameters:
    
    for ( timecount = 2; timecount <= 40; timecount++) {    // Loop the time of integration.
        double T = pow(10,(timecount/-2.0));
        
        
        double x_max =    4*sigma*sqrt(T)          + fabs( (rho - 1) )*T;
        double x_min = -1.5*sigma*sqrt(T*log(1/T)) + fabs( (rho - 1) )*T;
        // Probably should use exponentials here but I want
        // to do short time simulations.
        
        double dx = ( x_max - x_min ) / nx;
        double dt = T_STEP_RATIO * dx*dx / ( sigma*sigma );
        
        if ( nx >= NX_MAX ) {
            cout << "In main program, not big enough arrays.  \n"
            << "  asked for nx = " << nx << ".  Had NX_MAX = " << NX_MAX
            << endl;
            return(3);
        }
        double* u= new double[NX_MAX];
        double* uintr= new double[NX_MAX];
        double x_crit;
        double xcritical[NUMAVG];
        double time[NUMAVG];
        
        //Initialize the solution
        
        double x        = x_min;
        double x_cutoff = -1.e-3; // Purely technical: change how the
        // intrinsic value is computed.
        int ix;
        
        for ( ix = 0; ix <= nx; ix++) {    // This loop includes both end points.
            if ( x > 0 )
                u[ix] = 0.;
            else if ( x < x_cutoff ) // The argument is large enough that the formula
                u[ix] = 1 - exp(x) ;  // is accurate enough.
            else
                u[ix] = - x * ( 1 + x/2 * ( 1 + x/3 * ( 1 + x/4 ) ) );
            // This is a factored form of the Taylor series for 1-exp(x),
            // which has no cancellation and therefore should be more accurate
            // when x is small.  It should give full double precision accuracy.
            // when |x| < 10^-4.
            x = x + dx;    // The first trip through the loop has ix=0, so the
            // increment goes at the end.
        }  // end of "for ( ix = 0; ix <= nx; ix++) ... "
        
        for ( ix = 0; ix <= nx; ix++)
            uintr[ix]=u[ix];
        
        //End of initialization
        
        double t = 0;
        int it, error_code;
        double vsum = 0;    // Used in comparing computed x_crit to theory.
        for ( it = 0; t < T; it++ ) {
            t += dt;
            error_code =
            time_step( u, uintr, &x_crit, x_min, dx, dt, sigma, r, nx);
            xcritical[it % NUMAVG] = x_crit;
            time[it % NUMAVG]=t;
            if ( error_code != 0 ) {
                cout << "Main returning because of time step error code "
                << error_code << endl;
                cout << "  it = "     << it
                << "  dt = "     << dt;
                return(1);
            }
        }
        
        //   This is the fun part, seeing how the data fit the theory . . .
        
        int count;
        for (count = 0; count < NUMAVG; count++)
            vsum += exp(-xcritical[count]*xcritical[count]/(sigma*sigma*time[count]))/time[count];
        crit_price_output << t
        <<  "       " << x_crit
        <<  "       " << vsum/numavgd
        << "      " << it << endl;
        cout << t <<"      " << it << endl;
        
        
        
    }
    
    crit_price_output.close();
    cout << "done! " << endl;
    return 0;
}



