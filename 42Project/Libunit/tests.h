#ifndef TESTS_H
# define TESTS_H

# include <stdlib.h>
# include <stdio.h>

typedef					int (*ptest_func)(void); //testing function in a test

typedef enum			e_bool
{
	FALSE = 0,	
	TRUE = !FALSE
}						t_bool;

typedef enum			e_Error
{
	OK = 0,
	KO = -1,
	BUSE = 11,
	SEGV = 10,
	NO_TEST = 4,
	NO_SUITE = 5,
	NO_REGISTRY = 6
}						t_Error;

/** CUnit test case data type.
 *  CU_Test is a linked list of unit tests. 
 * 	Each test has a name, a callable test function, and a flag for whether the
 *  test is active and thus executed during a  test run.
 * 	A test also holds links to the next tests in the list
 *  Generally, the linked list includes tests which are associated
 *  with each other in a CU_Suite.
 * 	As a result, tests are run in the order in which they are added to a suite
 * (see CU_add_test()).
 */
typedef struct			s_unit_test
{
	char				*test_name;
	t_Error				error;
	t_bool				is_running;
	ptest_func			*test;
	struct s_unit_test	*next;
}						t_unit_test;
typedef	s_unit_test		*punit_test;  //pointer to the unit test

/** CUnit suite data type.
 *  CU_Suite is a linked list of CU_Test containers.
 * 	Each suite has a name, a count of registered unit tests, and a flag for whether
 *  the suite is active during test runs.
 *  In addition, the suite holds a pointer to the head of the linked
 *  list of associated CU_Test objects. Finally, pointers to the next suites
 *  Generally, the linked list includes suites which are associated with
 *  each other in a CU_TestRegistry.
 * 	As a result, suites are run in the
 *  order in which they are registered (see CU_add_suite()).
 */
typedef struct			s_unit_suite
{
	char				*suite_name;
	size_t				nb_tests;
	t_bool				is_running;
	size_t				nb_succes;
	size_t				nb_failed;
	punit_test			*test;
	struct s_unit_suite	*next;
}						t_unit_suite;
typedef	s_unit_suite	*punit_suite; //pointer to the suite

/** CUnit test registry data type.
 *  CU_TestRegisty is the repository for suites containing unit tests.
 *  The test registry maintains a count of the number of CU_Suite
 *  objects contained in the registry, as well as a count of the total
 *  number of CU_Test objects associated with those suites.  It also
 *  holds a pointer to the head of the linked list of CU_Suite objects.
 *  <br /><br />
 *
 *  With this structure, the user will normally add suites implictly to
 *  the internal test registry using CU_add_suite(), and then add tests
 *  to each suite using CU_add_test().  Test runs are then initiated
 *  using one of the appropriate functions in TestRun.c via one of the
 *  user interfaces.<br /><br />
 *
 *  Automatic creation and destruction of the internal registry and its
 *  objects is available using CU_initialize_registry() and
 *  CU_cleanup_registry(), respectively.  For internal and testing
 *  purposes, the internal registry can be retrieved and assigned.
 *  Functions are also provided for creating and destroying independent
 *  registries.<br /><br />
 */

typedef struct			s_unit_registry
{
		size_t		nb_suite;
		punit_suite	*suite;
}						t_unit_registry;
typedef s_unit_registry	*punit_registry; //pointer to the registry
#endif
