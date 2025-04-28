#pragma once
struct KComplex
{
	double r;
	double i;

    KComplex(double tr = 0.0, double ti = 0.0) : r(tr), i(ti) {}
	double Length() const
	{
		return sqrt(r * r + i * i);
	}
	KComplex Normalize()
	{
		const double length = Length();
		KComplex temp(r / length, i / length);
		return temp;
	}
    void Print() const
    {
        printf("%g + %gi\n", r, i);
    }
};

KComplex operator+(KComplex a, KComplex b)
{
	KComplex t;
	t.r = a.r + b.r;
	t.i = a.i + b.i;
	return t;
}

KComplex operator+(double r, KComplex b)
{
	KComplex t;
	t.r = r + b.r;
	t.i = 0.0 + b.i;
	return t;
}

KComplex operator+(KComplex a, double r)
{
	KComplex t;
	t.r = a.r + r;
	t.i = a.i + 0.0;
	return t;
}

KComplex operator-(KComplex a)
{
	KComplex t;
	t.r = -a.r;
	t.i = -a.i;
	return t;
}

KComplex operator-(KComplex a, KComplex b)
{
	KComplex t;
	t.r = a.r - b.r;
	t.i = a.i - b.i;
	return t;
}

KComplex operator-(double r, KComplex b)
{
	KComplex t;
	t.r = r - b.r;
	t.i = 0.0 - b.i;
	return t;
}

KComplex operator-(KComplex a, double r)
{
	KComplex t;
	t.r = a.r - r;
	t.i = a.i - 0.0;
	return t;
}

KComplex operator*(KComplex a, KComplex b)
{
	KComplex t;
	t.r = a.r * b.r - a.i * b.i;
	t.i = a.r * b.i + a.i * b.r;
	return t;
}

KComplex operator*(double r, KComplex b)
{
	KComplex t;
	t.r = r * b.r - 0.0 * b.i;
	t.i = r * b.i + 0.0 * b.r;
	return t;
}

KComplex operator*(KComplex a, double r)
{
	KComplex t;
	t.r = a.r * r - a.i * 0.0;
	t.i = a.r * 0.0 + a.i * r;
	return t;
}
