/**
 * @brief Define trazas de los tests
 *
 * @file test.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */
#ifndef _TEST_H
#define _TEST_H

#pragma GCC diagnostic ignored "-Wpedantic"

#ifndef NOCOLOR
#define KRED  "\x1B[31m"	/*!<Material proporcionado por los profesores*/
#define KGRN  "\x1B[32m"	/*!<Material proporcionado por los profesores*/
#define KYEL  "\x1B[33m"	/*!<Material proporcionado por los profesores*/
#define KCYN  "\x1B[36m"	/*!<Material proporcionado por los profesores*/
#define RESET "\033[0m"		/*!<Material proporcionado por los profesores*/
#else
#define KRED				/*!<Material proporcionado por los profesores*/
#define KGRN				/*!<Material proporcionado por los profesores*/
#define KYEL				/*!<Material proporcionado por los profesores*/
#define KCYN				/*!<Material proporcionado por los profesores*/
#define RESET				/*!<Material proporcionado por los profesores*/
#endif

#define PRINT_TEST_RESULT(x) do{					\
    __test_counter++;							\
    __pass = (x);							\
    __test_passed = (__pass)? __test_passed + 1 : __test_passed;	\
    printf(KYEL "%s" RESET " line "  "%d " KCYN "%s" RESET ": %s\n",	\
	   __FILE__, __LINE__ , __FUNCTION__,				\
	   ((!__pass) ? KRED "NOT PASS" RESET : KGRN "PASS" RESET));	\
  } while (0)	/*!<Material proporcionado por los profesores*/

#define PRINT_PASSED_PERCENTAGE printf("Tests passed %d%%\n", ((__test_passed * 100) / __test_counter))	/*!<Material proporcionado por los profesores*/

static int __test_counter = 0;
static int __test_passed  = 0;
static int __pass = 0;

#endif
