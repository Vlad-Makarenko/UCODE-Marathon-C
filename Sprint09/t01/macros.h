//
// Created by Vladyslav Makarenko on 9/20/21.
//

#ifndef DESKTOP_MACROS_H
#define DESKTOP_MACROS_H

#define MX_SUM(x, y) x + y

#define MX_MULT(x, y) x * y

#define MX_MIN(x, y) x > y ? y : x

#define MX_ABS(x) x > 0 ? x : -1 * x

#define MX_IS_ODD(x) x % 2 == 0 ? 0 : 1

#endif //DESKTOP_MACROS_H