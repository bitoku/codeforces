#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

#if !defined(_MATH_DEFINES_DEFINED)
#define _MATH_DEFINES_DEFINED

/* Define _USE_MATH_DEFINES before including math.h to expose these macro
 * definitions for common math constants.  These are placed under an #ifdef
 * since these commonly-defined names are not part of the C/C++ standards.
 */

/* Definitions of useful mathematical constants
 * M_E        - e
 * M_LOG2E    - log2(e)
 * M_LOG10E   - log10(e)
 * M_LN2      - ln(2)
 * M_LN10     - ln(10)
 * M_PI       - pi
 * M_PI_2     - pi/2
 * M_PI_4     - pi/4
 * M_1_PI     - 1/pi
 * M_2_PI     - 2/pi
 * M_2_SQRTPI - 2/sqrt(pi)
 * M_SQRT2    - sqrt(2)
 * M_SQRT1_2  - 1/sqrt(2)
 */

#define M_E        2.71828182845904523536
#define M_LOG2E    1.44269504088896340736
#define M_LOG10E   0.434294481903251827651
#define M_LN2      0.693147180559945309417
#define M_LN10     2.30258509299404568402
#define M_PI       3.14159265358979323846
#define M_PI_2     1.57079632679489661923
#define M_PI_4     0.785398163397448309616
#define M_1_PI     0.318309886183790671538
#define M_2_PI     0.636619772367581343076
#define M_2_SQRTPI 1.12837916709551257390
#define M_SQRT2    1.41421356237309504880
#define M_SQRT1_2  0.707106781186547524401

#endif  /* _USE_MATH_DEFINES */

int main() {
    ld x1, x2, y1, y2, r1, r2;
    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;
    if (r1 < r2) {
        swap(x1, x2);
        swap(y1, y2);
        swap(r1, r2);
    }
    ld d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    if (d >= r1 + r2) {
        cout << 0 << endl;
        return 0;
    }
    if (d + r2 <= r1) {
        cout << setprecision(16) << r2 * r2 * M_PI << endl;
        return 0;
    }
    ld cosalpha = (r1 * r1 + d * d - r2 * r2) / (2 * r1 * d);
    ld alpha = acos(cosalpha);
    ld area = r1 * r1 * (alpha - sin(alpha) * cosalpha);
    ld cosbeta = (r2 * r2 + d * d - r1 * r1) / (2 * r2 * d);
    ld beta = acos(cosbeta);
    area += r2 * r2 * (beta - sin(beta) * cosbeta);
    cout << setprecision(16) << area << endl;
}