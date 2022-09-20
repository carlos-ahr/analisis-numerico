#include <iostream>
#include <cmath>

using namespace std;

class secante{
    private:
        double xi0, xi, error, err;
        int n;
    public:
        int res;
        secante(): xi0(0.0), xi(0.0)
        {}

};