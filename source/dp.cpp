#include "dp.hpp"

double Dp::fact (int n){

	//double f[n+1]; // gcc allows this but MVSC doesn't!
	//So to run on C++11 or MVSC, following could be done
	std::vector<double> f;
	f.resize(n+1);

	int i = 0;
	f[0] = 1;

	for (i=1; i <= n; i++) {
		f[i] = i* f[i-1];
	}

	return f[n];
}

double Dp::fibonacci (int n){
	//double f[n+1]; //same reasoning as above

	std::vector<double> f;
	f.resize(n + 1);
	int i = 0;
	f[0] = 0;
	f[1] = 1;

	for (i = 2; i <= n; i++) {
		f[i] = f[i-1] + f[i-2];
	}
	return f[n];
}
