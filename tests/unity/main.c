#include <MathFunctions.h>
#include <unity.h>

/**
 * Funcion que usa mypow para una base positiva y un exponente positivo
*/
void test_mypow_base_and_exp_pos (void)
{
    TEST_ASSERT_EQUAL (4, mypow(2,2));
    TEST_ASSERT_NOT_EQUAL (4, mypow(2,3));
}

/**
 * Funcion que usa mypow para una base negativo y un exponente positivo
*/
void test_mypow_base_neg_and_exp_pos (void)
{
    TEST_ASSERT_EQUAL (4, mypow(-2,2));
    TEST_ASSERT_EQUAL (-8, mypow(-2,3));
    TEST_ASSERT_NOT_EQUAL (4, mypow(-2,3));
}

/**
 * Funcion que usa mypow para una base negativo y un exponente negativo
*/
void test_mypow_base_neg_and_exp_neg (void)
{
    TEST_ASSERT_EQUAL (1/4, mypow(-2,-2));
    TEST_ASSERT_EQUAL (-1/8, mypow(-2,-3));
    TEST_ASSERT_NOT_EQUAL (4, mypow(-2,-3));
}

/**
 * Funcion que usa mypow para una base positivo y un exponente negativo
*/
void test_mypow_base_pos_and_exp_neg (void)
{
    TEST_ASSERT_EQUAL (1/4, mypow(2,-2));
    TEST_ASSERT_EQUAL (1/8, mypow(2,-3));
    TEST_ASSERT_NOT_EQUAL (4, mypow(2,-3));
}

/**
 * funcionar antes de incializar
*/
void setUp(void){}

/**
 * funcion despues de finalizar
*/
void tearDown(void){}

int main (int argc, char *argv[])
{
    UNITY_BEGIN ();
    RUN_TEST(test_mypow_base_and_exp_pos);
    RUN_TEST(test_mypow_base_neg_and_exp_pos);
    RUN_TEST(test_mypow_base_neg_and_exp_neg);
    RUN_TEST(test_mypow_base_pos_and_exp_neg);
    return UNITY_END();
}
