#include <test'1'.h>
/*#include <test"1".h>*/

#include "test'2'.h"
#include ".\test'2'.h"
#include ".\\test'2'.h"

#include_next <test'1'.h>
/*#include_next <test"1".h>*/

#include_next "test'2'.h"
#include_next ".\test'2'.h"
#include_next ".\\test'2'.h"
