#include "stdafx.h"
#include "Float3.h"
#include <cmath>

float Float3::Distance(Float3 b) const
{
	Float3 v {};
	v.x = x - b.x;
	v.y = y - b.y;
	v.z = z - b.z;
	return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}
