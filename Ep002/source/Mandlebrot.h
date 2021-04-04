#ifndef MANDLEBROT_H
#define MANDLEBROT_H

class Mandlebrot
{
public:
    static constexpr int MAX_ITERATIONS = 1000;

public:
    Mandlebrot();
    ~Mandlebrot();

    static int getIterations(double x, double y);
};


#endif // MANDLEBROT_G